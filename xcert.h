/**
 * Barebones SSLChain implementation
 * xcert.h
 *
 * X509 Utils
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

using std::string;

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

uint256 getCertHash(unsigned char* pem);
