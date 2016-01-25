/**
 * Barebones SSLChain implementaton
 * xcert.h
 */

#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/sha.h>
#include <openssl/obj_mac.h>
#include <openssl/safestack.h>

#include "uint256.h"
#include "hash.h"

 typedef std::vector<unsigned char*> CertVector;


/**
 * Generate a new key-pair and a 2048-bit RSA key to pair
 *
 * @return pointer to the generated key pair
 */
EVP_PKEY* generate_rsa();

/**
 * Generate a simple, self-signed X.509 certificate
 *
 * @param the keypair to be paired with and sign the cert
 *
 * @return the signed X509 certificate
 */
X509* generate_x509(EVP_PKEY* pkey);

unsigned char* pemCert(X509* cert);
uint256 convertTest(X509* cert);
/**
 * Create a new certificate stack using OpenSSL's STACK_OF(obj*) implemenation
 *
 * @return a new STACK_OF(X509*) initialized to null
 */
STACK_OF(X509)* createCertStack();

/**
 * Push a certificate to an OpenSSL STACK object
 *
 * @param the stack object
 * @param the certificte to be pushed
 *
 * @return the updated stack object
 */
void pushToCertStack(STACK_OF(X509)* stack, X509* cert);

/**
 * Pop a certificate from the stack
 * @param the stack object
 *
 * @return the popped certificate
 */
X509* popFromCertStack(STACK_OF(X509)* stack);

/**
 * Duplicate a given stack
 * @param the stack to be copied
 *
 * @return the copied stack object
 */
STACK_OF(X509)* copyStack(STACK_OF(X509)* stack);

/**
 * Get the amount of certs in the stack
 * @param the stack object
 *
 * @return the number of certs in the stack
 */
int getStackSize(STACK_OF(X509)* stack);

/**
 * Frees the memory allocated to the stack object
 * @param the stack object to be deallocated
 */
void freeStack(STACK_OF(X509)* stack);

//char* encodeCert(X509* cert);

unsigned char* encodeCert(X509* cert);

unsigned char* hashCert(unsigned char* data);
