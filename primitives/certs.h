#ifndef SSLCHAIN_CERTS_H
#define SSLCHAIN_CERTS_H

#include "../uint256.h"
#include "../serialize.h"
#include "../xcert.h"

class Certificate
{
public:
	X509* cert;
	uint256 hash;
	//char* pem;

	Certificate();

#pragma region SERIALIZATION
	//I need this to make hashes apparently
	//ADD_SERIALIZE_METHODS;

	//Error: can't call a non const function inside a const function (despite it being handled in serialize.h)
	//We'll do it live

	template <typename Stream, typename Operation>
	inline void SerializationOp(Stream& s, Operation ser_action, int nType, int nVersion)
	{

		/**
		 * In order to hash the certificate, I convert it to PEM format (base64 encoded data) and read in
		 * each character individually to the BTC Serialization system (as the only type it can take which
		 * is appropriate in this scenario is a char)
		 *
		 * BTC uses this system to gather data to hash. My issue was that I wasn't reading anything, so all of the
		 * hashes were the same (i.e. it was hashing a null object of sorts)
		 */

		char* pem = convertToPem();
		for(int i = 0; i < strlen(pem); i++)
		{
			READWRITE(pem[i]);
		}
	}

	/**
	 * The generic function template T* NCONST_PTR (line 43 in serialize.h) was supposed to handle all of this
	 * Instead, I had to const_cast manually so I can serialize all of these objects
	 */

	size_t GetSerializeSize(int nType, int nVersion) const {
	    CSizeComputer s(nType, nVersion);
		const_cast<Certificate*>(this)->SerializationOp(s, CSerActionSerialize(), nType, nVersion);
	    return s.size();
	}
	template<typename Stream>
	void Serialize(Stream& s, int nType, int nVersion) const {
		const_cast<Certificate*>(this)->SerializationOp(s, CSerActionSerialize(), nType, nVersion);
	}
	template<typename Stream>
	void Unserialize(Stream& s, int nType, int nVersion) {
		SerializationOp(s, CSerActionUnserialize(), nType, nVersion);
	}
#pragma endregion SERIALIZATION

	void generateCert(EVP_PKEY* pkey);

	void generateCert(EVP_PKEY* pkey, unsigned char* countryCode, unsigned char* organization,
						unsigned char* commonName, unsigned char* email);

	void certDataVerif();



	char* convertToPem();

	unsigned char* uConvertToPem();

	void calcHash();

	uint256 GetHash() const;

	RSA* getPublicKey();

	char* getEmail();
};

#endif //SSLCHAIN_CERTS_H
