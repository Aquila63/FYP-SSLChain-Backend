/**
 * Barebones SSLChain implementation
 * block.cpp
 */

 #include "../crypto/common.h"
 #include "block.h"
 #include "../hash.h"
 #include "../utilstrencodings.h"
 #include "../tinyformat.h"
 #include "../xcert.h"

 uint256 CBlockHeader::GetHash() const
 {
 	return SerializeHash(*this);
 }

 uint256 CBlock::ComputeMerkleRoot(bool *fMutated) const
 {
 	//Big Merkle Tree bug notice goes here

 	std::vector<uint256> vMerkleTree;
 	vMerkleTree.reserve(sizeof(certs) * 2 + 16);

    for(std::vector<Certificate>::const_iterator it(certs.begin()); it != certs.end(); ++it)
        vMerkleTree.push_back(it->GetHash());

 	int j = 0;
 	bool mutated = false;
 	for(int nSize = certs.size(); nSize > 1; nSize = (nSize + 1) / 2)
 	{
 		for(int i = 0; i < nSize; i+= 2)
 		{
 			int i2 = std::min(i+1, nSize-1);
 			if(i2 == i + 1 && i2 + 1 == nSize && vMerkleTree[j+1] == vMerkleTree[j+i2])
 			{
 				// Two identical hashes at the end of the list at a particular level.
                mutated = true;
 			}

 			vMerkleTree.push_back(Hash(BEGIN(vMerkleTree[j+i]), END(vMerkleTree[j+i]),
 									   BEGIN(vMerkleTree[j+i2]), END(vMerkleTree[j+i2])));

 		}
 		j += nSize;
 	}
 	//freeStack(certsCpy);
 	if(fMutated)
 	{
 		*fMutated = mutated;
 	}

 	return(vMerkleTree.empty() ? uint256() : vMerkleTree.back());
 }

 std::string CBlock::ToString() const
 {
 	std::stringstream ss;
 	ss << strprintf("CBlock(hash=%s, ver=%d, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, certs=%u)\n",
 					GetHash().ToString(),
 					nVersion,
 					hashPrevBlock.ToString(),
 					hashMerkleRoot.ToString(),
 					nTime, nBits, nNonce,
 					certs.size());

 	return ss.str();
 }
