/**
 * Barebones SSLChain implementation
 * main.cpp
 *
 * At this point, main.cpp is a testing ground for each
 * module that I construct
 */

 #include "primitives/block.h"
 #include "xcert.h"
 #include "main.h"
 #include "hash.h"
 #include <time.h>
 #include <iostream>

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

 CBlock CreateGenisisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, uint32_t nVersion)
 {
    //printf("....CreateGenisisBlock..\n");

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
 	printf("Genesis block successfully created!");
 	return genesis;
 }

 int main()
 {
    printf("....Started....\n");
 	//uint32_t timestamp = (uint32_t)time(NULL);
 	CBlock genBlock = CreateGenisisBlock(2820938944, 2, 0x207fffff, 1);
    printf("\n%s", genBlock.ToString().c_str());
 	return 0;
 }
