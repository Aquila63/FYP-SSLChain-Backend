/**
* Barebones SSLChain implementation
* main.cpp
*
* At this point, main.cpp is a testing ground for each
* module that I construct
*/

#include <boost/foreach.hpp>

#include "primitives/block.h"
#include "chain.h"
#include "main.h"
#include <iostream>
#include "server.h"


using namespace std;

#define TEST_CERT_COUNT     4

//There's no need to make POW difficult as there's no monetary reward; I've set the difficulty to 3 leading 0s
#define POW_DIFFICULTY_BITS  0x1f0fffff

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
	                              (unsigned char*)"John Doe",
	                              (unsigned char*)"jodoe@tcd.ie");
	//cout << cert.keyToPem(cert.getPublicKey()) << endl;
	vec.push_back(cert);


	Certificate cert2 = createCert((unsigned char*)"IE",
	                               (unsigned char*)"University College Dublin",
	                               (unsigned char*)"Jane Doe",
	                               (unsigned char*)"jadoe@ucd.ie");
	//cout << cert2.keyToPem(cert2.getPublicKey()) << endl;
	vec.push_back(cert2);

	Certificate cert3 = createCert((unsigned char*)"IE",
	                               (unsigned char*)"Dublin City University",
	                               (unsigned char*)"Joe Bloggs",
	                               (unsigned char*)"jbloggs@dcu.ie");
	//cout << cert3.keyToPem(cert3.getPublicKey()) << endl;
	vec.push_back(cert3);

	Certificate cert4 = createCert((unsigned char*)"UK",
	                               (unsigned char*)"Queen's University Belfast",
	                               (unsigned char*)"Billy Strong",
	                               (unsigned char*)"bstring@qub.ac.uk");
	//cout << cert4.keyToPem(cert4.getPublicKey()) << endl;
	vec.push_back(cert4);

	return vec;
}

std::vector<Certificate> createGenisisCertsFromFile()
{
	std::vector<Certificate> vec;

	Certificate cert1;
	cert1.generateCertFromFile((char*)"../certs/genCert1.pem");
	vec.push_back(cert1);
	Certificate cert2;
	cert2.generateCertFromFile((char*)"../certs/genCert2.pem");
	vec.push_back(cert2);
	Certificate cert3;
	cert3.generateCertFromFile((char*)"../certs/genCert3.pem");
	vec.push_back(cert3);
	Certificate cert4;
	cert4.generateCertFromFile((char*)"../certs/genCert4.pem");
	vec.push_back(cert4);

	return vec;
}


Certificate createCert( unsigned char* countryCode, unsigned char* organization,
                        unsigned char* commonName, unsigned char* email)
{
	EVP_PKEY* key = generate_rsa();
	Certificate cert;
	cert.generateCert(key, countryCode, organization, commonName, email);
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
	string emailStr;
	unsigned char* email;

	cout << "Certificate Initialization" << endl;
	cout << "Please enter the following details:" << endl;
	cout << "Country Code [C]: ";
	//cin >> ccStr;
	getline(cin, ccStr);
	cout << endl;
	cout << "Organization [0]: ";
	//cin >> orgStr;
	getline(cin, orgStr);
	cout << endl;
	cout << "Common Name [CN]: ";
	//cin >> cnStr;
	getline(cin, orgStr);
	cout << endl;
	cout << "Email Address: ";
	//cin >> emailStr;
	getline(cin, emailStr);
	cout << endl;

	cc = unsignedStrConverter(ccStr);
	org = unsignedStrConverter(orgStr);
	cn = unsignedStrConverter(cnStr);
	email = unsignedStrConverter(emailStr);

	return createCert(cc, org, cn, email);
}

CBlock CreateGenesisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, uint32_t nVersion)
{
	//printf("....CreateGenesisBlock..\n");

	//Certs are normal here, they get hashed when they are passed through the m-tree
	 std::vector<Certificate> nCerts;
	 //nCerts = createGenisisCerts();
	nCerts = createGenisisCertsFromFile();

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

//Actually implemented in chain.h too, oops
void addToChain(CBlock* block, CChain blockchain)
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
	/*printf("....Started....\n");
	uint32_t timestamp = (uint32_t)time(NULL);
	CBlock genBlock = CreateGenesisBlock(timestamp, 2, 0x207fffff, 1);
	//printf("\n%s", genBlock.ToString().c_str());
	//uint256 hash = genBlock.GetHash();
	addToChain(&genBlock);
	printf("----GENESIS BLOCK----\n%s", blockchain.Genesis()->ToString().c_str());
	printf("\n");*/

	//CBlock aBlock = createStandardBlock();
	//addToChain(&aBlock);
	//printf("\n%s", blockchain.Tip()->ToString().c_str());

	Server server;

	//CBlock genBlock = CreateGenesisBlock(0, 0, POW_DIFFICULTY_BITS, 1);
	CBlock genBlock = CreateGenesisBlock(getLinuxTS(), 0, POW_DIFFICULTY_BITS, 1);
	//server.blockchain.add(&genBlock);

	printf("Testing POW...\n");
	printf("Bits = %d\n", genBlock.nBits);
	CBlockHeader genBlockHeader = genBlock.GetBlockHeader();
	uint32_t nonce = server.proofOfWork(&genBlockHeader, genBlock.nBits);
	genBlock.nNonce = nonce;
	server.verifyProof(&genBlockHeader, genBlock.nNonce, genBlock.nBits);

	server.blockchain.add(&genBlock);
	//CBlock aBlock = createStandardBlock();
	//addToChain(&aBlock);

	server.start();

	return 0;
}
