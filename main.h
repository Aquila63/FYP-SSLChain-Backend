#include "primitives/certs.h"

 typedef std::vector<unsigned char*> CertVector;

//std::vector<unsigned char*> createGenisisCerts();
std::vector<Certificate> createGenisisCerts();
Certificate createCert( unsigned char* countryCode, unsigned char* organization,
                        unsigned char* commonName );
CBlock CreateGenisisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, uint32_t nVersion);

int main();
