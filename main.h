 typedef std::vector<unsigned char*> CertVector;

std::vector<unsigned char*> createGenisisCerts();
//CertVector* createGenisisCerts();
CBlock CreateGenisisBlock(uint32_t nTime, uint32_t nNonce, uint32_t nBits, uint32_t nVersion);

int main();
