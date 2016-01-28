/**
 * Barebones SSLChain implementation
 * main.cpp
 *
 * At this point, main.cpp is a testing ground for each
 * module that I construct
 */

 #include "primitives/block.h"
 #include "chain.h"
 #include "xcert.h"
 #include "main.h"
 #include "hash.h"
 #include <time.h>
 #include <iostream>

using namespace std;

#define TEST_CERT_COUNT 4

CChain blockchain;

uint32_t getLinuxTS()
{
	return (uint32_t)time(NULL);
}

unsigned char* unsignedStrConverter(std::string str)
{
	char* cstr = const_cast<char*>(str.c_str());
	unsigned char* retStr = new unsigned char[str.length()];
	memcpy(retStr, cstr, str.length());

	return retStr;
}

std::vector<Certificate> createGenisisCerts()
{
	std::vector<Certificate> vec;
	//Create a big block of certs to place in the tree

	Certificate cert = createCert((unsigned char*)"IE",
	                              (unsigned char*)"Trinity College, Dublin",
	                              (unsigned char*)"John Doe");
	vec.push_back(cert);

	//cert.certDataVerif();

	Certificate cert2 = createCert((unsigned char*)"IE",
	                              (unsigned char*)"University College Dublin",
	                              (unsigned char*)"Jane Doe");
	vec.push_back(cert2);

	Certificate cert3 = createCert((unsigned char*)"IE",
	                               (unsigned char*)"Dublin City University",
	                               (unsigned char*)"Joe Bloggs");
	vec.push_back(cert3);

	Certificate cert4 = createCert((unsigned char*)"UK",
	                               (unsigned char*)"Queen's University Belfast",
	                               (unsigned char*)"Billy Strong");
	vec.push_back(cert4);

	return vec;
}

Certificate createCert( unsigned char* countryCode, unsigned char* organization,
                        unsigned char* commonName )
{
	EVP_PKEY* key = generate_rsa();
	Certificate cert;
	cert.generateCert(key, countryCode, organization, commonName);
	//cert.calcHash();
	//uint256 hash = cert.GetHash();
	EVP_PKEY_free(key);
	return cert;
}

Certificate createCustomCert()
{
	string ccStr;
	unsigned char* cc;
	string orgStr;
	unsigned char* org;
	string cnStr;
	unsigned char* cn;
	cout << "Certificate Initialization" << endl;
	cout << "Please enter the following details:" << endl;
	cout << "Country Code: ";
	cin >> ccStr;
	cout << endl;
	cout << "Organization: ";
	cin >> orgStr;
	cout << endl;
	cout << "Common Name: ";
	cin >> cnStr;
	cout << endl;

	cc = unsignedStrConverter(ccStr);
	org = unsignedStrConverter(orgStr);
	cn = unsignedStrConverter(cnStr);

	return createCert(cc, org, cn);
}

CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, uint32_t nVersion)
{
	//printf("....CreateGenesisBlock..\n");

	//Certs are normal here, they get hashed when they are passed through the m-tree
	 std::vector<Certificate> nCerts;
	 nCerts = createGenisisCerts();

	//printf("....CreatingBlocks....\n");
	CBlock genesis;
	genesis.nTime = nTime;
	genesis.nBits = nBits;
	genesis.nNonce = nNonce;
	genesis.nVersion = nVersion;
	genesis.certs = nCerts;
	genesis.hashPrevBlock.SetNull();
	genesis.hashMerkleRoot = genesis.ComputeMerkleRoot(NULL);
	printf("Genesis block successfully created!\n");
	return genesis;
}

CBlock createStandardBlock()
{
	std::vector<Certificate> nCerts;
	for (int i = 0; i < TEST_CERT_COUNT; i++)
	{
		Certificate cert = createCustomCert();
		nCerts.push_back(cert);
	}

	CBlock aBlock;
	aBlock.nTime = getLinuxTS();
	aBlock.nBits = 0x207fffff;
	aBlock.nNonce = 0;
	aBlock.nVersion = 1;
	aBlock.certs = nCerts;
	aBlock.hashPrevBlock.SetNull();
	aBlock.hashMerkleRoot = aBlock.ComputeMerkleRoot();

	return aBlock;
}

void addToChain(CBlock* block)
{
	block->nHeight = blockchain.GetHeight();
	if(block->nHeight > 0)
	{
		uint256 pHash = blockchain.Tip()->GetHash();
		block->hashPrevBlock = pHash;
	}
	blockchain.add(block);
}

int main()
{
	printf("....Started....\n");
	uint32_t timestamp = (uint32_t)time(NULL);
	CBlock genBlock = CreateGenesisBlock(timestamp, 2, 0x207fffff, 1);
	//printf("\n%s", genBlock.ToString().c_str());
	//uint256 hash = genBlock.GetHash();
	addToChain(&genBlock);
	printf("----GENESIS BLOCK----\n%s", blockchain.Genesis()->ToString().c_str());
	printf("\n");

	CBlock aBlock = createStandardBlock();
	addToChain(&aBlock);
	printf("\n%s", blockchain.Tip()->ToString().c_str());
	return 0;
}
