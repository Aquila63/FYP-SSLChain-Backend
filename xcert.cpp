/**
 * Barebones SSLChain implementaton
 * xcert.cpp
 *
 * Most of the functions relating to the X509 certificates will be handled here
 * Mainly deals with the creation and management of X509 certs within the SSLChain sytem
 */

#include <stdio.h>
#include <bits/unique_ptr.h>
#include "xcert.h"

using std::string;

EVP_PKEY* generate_rsa()
{
	EVP_PKEY* pkey;
	pkey = EVP_PKEY_new();
	RSA * rsa;
	rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
	EVP_PKEY_assign_RSA(pkey, rsa);

	if(pkey == NULL) { printf("!!!!!!!PKEY IS NULL!!!!!!!"); }
	if(rsa == NULL) { printf("!!!!!!!RSA IS NULL!!!!!!!"); }

	return pkey;
};

//Self signed
X509* generate_x509(EVP_PKEY* pkey)
{
	printf("....Generating Cert....\n");
	X509 * x509;
	x509 = X509_new();

	// Set serial no to 1 for now
	ASN1_INTEGER_set(X509_get_serialNumber(x509), 1);
	// Set validity
	X509_gmtime_adj(X509_get_notBefore(x509), 0);
	X509_gmtime_adj(X509_get_notAfter(x509), 3153600L);
	// Set pubkey
	X509_set_pubkey(x509, pkey);

	X509_NAME *name;
	name = X509_get_subject_name(x509);

	// Country
	X509_NAME_add_entry_by_txt(name, "C", MBSTRING_ASC,
							 (unsigned char*)"IE", -1, -1, 0);
	// Company/Organization
	X509_NAME_add_entry_by_txt(name, "O",  MBSTRING_ASC,
                             (unsigned char*)"MyCompany Inc.", -1, -1, 0);
	// Common Name
	X509_NAME_add_entry_by_txt(name, "CN", MBSTRING_ASC,
                             (unsigned char*)"localhost", -1, -1, 0);

	// Set issuer name
	X509_set_issuer_name(x509, name);

	// Self-signed for now
	X509_sign(x509, pkey, EVP_sha1());

    if(x509 == NULL) { printf("!!!!!!!X509 IS NULL!!!!!!!"); }


	return x509;
}

unsigned char* pemCert(X509* cert)
{
    BIO * bio_out = BIO_new(BIO_s_mem());
    PEM_write_bio_X509(bio_out, cert);
    BUF_MEM *bio_buf;
    BIO_get_mem_ptr(bio_out, &bio_buf);
    string pemStr = string(bio_buf->data, bio_buf->length);
    unsigned char* pem;
    char* cstr = const_cast<char*>(pemStr.c_str());
    pem = reinterpret_cast<unsigned char*>(cstr);
    BIO_free(bio_out);

    unsigned char* retPem = new unsigned char[pemStr.length()];
    memcpy(retPem, cstr, pemStr.length());

    return retPem;
}

const char* pemCertAlt(X509* cert)
{
    BIO * bio_out = BIO_new(BIO_s_mem());
    PEM_write_bio_X509(bio_out, cert);
    BUF_MEM *bio_buf;
    BIO_get_mem_ptr(bio_out, &bio_buf);
    string pemStr = string(bio_buf->data, bio_buf->length);
    return pemStr.c_str();
}

uint256 convertTest(X509* cert)
{
    unsigned char* test = pemCert(cert);
    uint256 hash = Hash(&test[0], &test[sizeof(test)]);
    return hash;
}

unsigned char* hashCert(unsigned char* data)
{
    //printf("....HashingCert....\n");
    //printf("Data: %s\n\n", data);
	unsigned char* hash = (unsigned char*) malloc(SHA256_DIGEST_LENGTH * sizeof(unsigned char));
    //printf("1....\n");
	SHA256_CTX sha256;
	//printf("2....\n");
	SHA256_Init(&sha256);
	//printf("3....\n");
	SHA256_Update(&sha256, data, strlen((const char*)data));
	//printf("4....\n");
	SHA256_Final(hash, &sha256);
	//printf("5....\n");
	//printf("HASH - %s\n", hash);
	return hash;
}

STACK_OF(X509)* createCertStack()
{
	STACK_OF(X509) *stack = sk_X509_new_null();
	return stack;
}

void pushToCertStack(STACK_OF(X509)* stack, X509* cert)
{
	sk_X509_push(stack, cert);
}

X509* popFromCertStack(STACK_OF(X509)* stack)
{
	X509* cert = sk_X509_pop(stack);
	return cert;
}

STACK_OF(X509)* copyStack(STACK_OF(X509)* stack)
{
	STACK_OF(X509) *sk = sk_X509_dup(stack);
	return sk;
}

int getStackSize(STACK_OF(X509)* stack)
{
	return sk_X509_num(stack);
}

void freeStack(STACK_OF(X509)* stack)
{
	sk_X509_free(stack);
}
