/**
 * Barebones SSLChain implementaton
 * block.h
 */

#ifndef BITCOIN_PRIMITIVES_BLOCK_H
#define BITCOIN_PRIMITIVES_BLOCK_H

 #include "../uint256.h"
 #include "../serialize.h"
 #include "../xcert.h"
 #include "certs.h"

 //SSLChains's Blockcahin is practically identical to Bitcoin's one.

 class CBlockHeader
 {
 public:
 	static const int32_t CURRENT_VERSION=1;
 	int32_t nVersion;
 	uint256 hashPrevBlock;
 	uint256 hashMerkleRoot;
 	uint32_t nTime;
 	uint32_t nBits;
 	uint32_t nNonce;

	uint32_t nHeight;

 	CBlockHeader()
 	{
 		SetNull();
 	}

	 ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion) const {
        READWRITE(this->nVersion);
        nVersion = this->nVersion;
        READWRITE(hashPrevBlock);
        READWRITE(hashMerkleRoot);
        READWRITE(nTime);
        READWRITE(nBits);
        READWRITE(nNonce);
    }

 	void SetNull()
 	{
		nVersion = CBlockHeader::CURRENT_VERSION;
 		hashPrevBlock.SetNull();
 		hashMerkleRoot.SetNull();
 		nTime = 0;
 		nBits = 0;
 		nNonce = 0; //Need?
	    nHeight = 0;
 	}

 	bool IsNull() const
 	{
 		return (nBits == 0);
 	}

 	uint256 GetHash() const;

 	int64_t GetBlockTime() const
 	{
 		return (int64_t) nTime;
 	}

	int32_t GetHeight() const
	{
		return nHeight;
	}
 };

 class CBlock : public CBlockHeader
 {
 public:
 	//STACK_OF(X509)* certs;
    //std::vector<unsigned char*> certs;
	 std::vector<Certificate> certs;

 	mutable bool fChecked;

 	CBlock()
 	{
 		SetNull();
 	}

 	CBlock(const CBlockHeader &header)
 	{
 		SetNull();
 		*((CBlockHeader*)this) = header;
 	}

 	void SetNull()
 	{
 		CBlockHeader::SetNull();
 		//certs = createCertStack();
        certs.clear();
 		fChecked = false;
 	}

 	CBlockHeader GetBlockHeader() const
 	{
 		CBlockHeader block;
 		block.nVersion = nVersion;
 		block.hashPrevBlock = hashPrevBlock;
 		block.hashMerkleRoot = hashMerkleRoot;
 		block.nTime = nTime;
 		block.nBits = nBits;
 		block.nNonce = nNonce;
	    block.nHeight = nHeight;
 		return block;
 	}

	// Build the merkle tree for this block and return the merkle root.
	// If non-NULL, *mutated is set to whether mutation was detected in the merkle
	// tree (a duplication of transactions in the block leading to an identical
	// merkle root).
	uint256 ComputeMerkleRoot(bool* mutated = NULL) const;

	std::string ToString() const;
 };
#endif // BITCOIN_PRIMITIVES_BLOCK_H
