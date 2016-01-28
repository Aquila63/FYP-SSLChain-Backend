#ifndef SSLCHAIN_CHAIN_H
#define SSLCHAIN_CHAIN_H

#include "primitives/block.h"

#include <vector>

using std::vector;

class CChain
{
public:
	vector<CBlock*> vChain;

	CChain()
	{
		//Allocate some space for the the blockchain
		//For this prototype, I don't see it being getting anywhere near 1000 blocks
		vChain.reserve(1000);
	}

	CBlock* Genesis() const
	{
		return vChain.size() > 0 ? vChain[0] : NULL;
	};

	CBlock* Tip() const
	{
		return vChain.size() > 0 ? vChain[(int) vChain.size() - 1] : NULL;
	}

	int GetHeight()
	{
		return (int) vChain.size();
	}

	void add(CBlock* block)
	{
		vChain.push_back(block);
	}
};

#endif //SSLCHAIN_CHAIN_H
