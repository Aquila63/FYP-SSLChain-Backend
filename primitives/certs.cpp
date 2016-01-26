#include "certs.h"

Certificate::Certificate()
{
	this->cert = NULL;
}

void Certificate::generateCert(EVP_PKEY *pkey)
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

	this->cert = x509;
}

void Certificate::generateCert(EVP_PKEY* pkey, unsigned char* countryCode, unsigned char* organization,
                               unsigned char* commonName)
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
	                           countryCode, -1, -1, 0);
	// Company/Organization
	X509_NAME_add_entry_by_txt(name, "O",  MBSTRING_ASC,
	                           organization, -1, -1, 0);
	// Common Name
	X509_NAME_add_entry_by_txt(name, "CN", MBSTRING_ASC,
	                           commonName, -1, -1, 0);

	// Set issuer name
	X509_set_issuer_name(x509, name);

	// Self-signed for now
	X509_sign(x509, pkey, EVP_sha1());

	this->cert = x509;
}

char* Certificate::convertToPem()
{
	BIO * bio_out = BIO_new(BIO_s_mem());
	PEM_write_bio_X509(bio_out, this->cert);
	BUF_MEM *bio_buf;
	BIO_get_mem_ptr(bio_out, &bio_buf);
	string pemStr = string(bio_buf->data, bio_buf->length);
	char* pem = const_cast<char*>(pemStr.c_str());
	BIO_free(bio_out);

	char* out = new char[pemStr.length()];
	//Copy to output array
	memcpy(out, pem, pemStr.length());
	return out;
}

unsigned char* Certificate::uConvertToPem()
{
	BIO * bio_out = BIO_new(BIO_s_mem());
	PEM_write_bio_X509(bio_out, this->cert);
	BUF_MEM *bio_buf;
	BIO_get_mem_ptr(bio_out, &bio_buf);
	string pemStr = string(bio_buf->data, bio_buf->length);
	unsigned char* pem;
	char* cstr = const_cast<char*>(pemStr.c_str());
	//pem = reinterpret_cast<unsigned char*>(cstr);
	BIO_free(bio_out);

	unsigned char* retPem = new unsigned char[pemStr.length()];
	memcpy(retPem, cstr, pemStr.length());

	return retPem;
}

void Certificate::certDataVerif()
{
	BIO *bio_out = BIO_new_fp(stdout, BIO_NOCLOSE);

	//Subject
	BIO_printf(bio_out, "Subject: ");
	X509_NAME_print(bio_out, X509_get_subject_name(cert), 0);
	BIO_printf(bio_out, "\n");

	//Issuer
	BIO_printf(bio_out, "Issuer: ");
	X509_NAME_print(bio_out, X509_get_issuer_name(cert), 0);
	BIO_printf(bio_out, "\n");

	//Public Key
	EVP_PKEY *pkey = X509_get_pubkey(cert);
	EVP_PKEY_print_private(bio_out, pkey, 0, NULL);
	EVP_PKEY_free(pkey);

	//Signature
	X509_signature_print(bio_out, cert->sig_alg, cert->signature);
	BIO_printf(bio_out, "\n");

	BIO_free(bio_out);
}

void Certificate::calcHash()
{
	//hash = SerializeHash(*this);
}

uint256 Certificate::GetHash() const
{
	return SerializeHash(*this);
}