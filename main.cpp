/**
 * Barebones SSLChain implementaton
 * main.cpp
 *
 * At this point, main.cpp is a tesing ground for each
 * module that I construct
 */

 #include "primitives/block.h"
 #include "xcert.h"
 #include "main.h"
 #include "hash.h"
 #include <time.h>
 #include <iostream>

//typedef std::vector<unsigned char*> CertVector;

 /*std::vector<unsigned char*> createGenisisCerts()
 {
    printf("....CreateGeneisisCerts....\n");

    std::vector<unsigned char*> vec;

    //Create a big block of certs to place in the tree
    for(int i = 0; i < 4; i++)
    {
        EVP_PKEY* key = generate_rsa();
        EVP_PKEY* key_2 = generate_rsa();
        EVP_PKEY* key_3 = generate_rsa();

        X509* x509 = generate_x509(key);
        X509* x509_2 = generate_x509(key_2);
        X509* x509_3 = generate_x509(key_3);

        //convertTest(x509);

        unsigned char* cstr = pemCert(x509);
        //printf("%s\n", cert);

        //unsigned char* hashedCert0 = hashCert(cert);

        unsigned char* cstr2 = pemCert(x509_2);
        //unsigned char* hashedCert2 = hashCert(cert2);

        unsigned char* cstr3 = pemCert(x509_3);
        //unsigned char* hashedCert3 = hashCert(cert3);


        vec.push_back(cstr);
        vec.push_back(cstr2);
        vec.push_back(cstr3);
    }

    return vec;
 }*/

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
	uint256 hash = cert.GetHash();
	EVP_PKEY_free(key);
	return cert;
}

 CBlock CreateGenisisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, uint32_t nVersion)
 {
    printf("....CreateGenisisBlock..\n");

	//Certs are normal here, they get hashed when they are passed through the m-tree
    //std::vector<unsigned char*> nCerts;
	 std::vector<Certificate> nCerts;
     nCerts = createGenisisCerts();

    printf("....CreatingBlocks....\n");
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

 /*void hashTest()
 {
    printf("....Testing Bitcoin's Hash....\n\n");
    printf("...Generating a test cert...\n");

 	EVP_PKEY* key = generate_rsa();
 	X509* x509 = generate_x509(key);

    printf("...Encoding cert...\n");
    unsigned char* eCert = encodeCert(x509);

    printf("...Running hash function...\n");
    int len = strlen((char*)eCert);
    uint256 hash = Hash(&eCert[0], &eCert[len]);
    hash.ToString();
 }*/


 int main()
 {
    printf("....Started....\n");
 	//uint32_t timestamp = (uint32_t)time(NULL);
 	CBlock genBlock = CreateGenisisBlock(2820938944, 2, 0x207fffff, 1);
    //genBlock.ToString();
 	return 0;
 }
