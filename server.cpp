#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <regex>
#include <time.h>
#include <assert.h>
//#include <boost/algorithm/string/predicate.hpp>

#include "server.h"
#include "arith_uint256.h"
#include "streams.h"

using std::cout;
using std::endl;
using std::string;
//using boost::starts_with;

Server::Server() { }

CBlock* Server::findBlock(string cmd)
{
	string result;
	std::regex re("GET BLOCK (.*)");
	std::smatch match;
	//cout << str << endl;
	//assert(std::regex_search(str, match, re));
	if(std::regex_search(cmd, match, re) && match.size() > 1)
		result = match.str(1); //Flagged as an error, but still compiles.

	//Debugger says that result is empty, but cout prints it
	//Shit's strange
	//cout << "REGEX RESULT = " << result << endl;

	CBlock* resBlock = NULL;

	for(std::vector<CBlock*>::iterator it(blockchain.vChain.begin());
	    it != blockchain.vChain.end(); ++it)
	{
		string hash = (*it)->GetHash().ToString();

		if(hash.compare(0, result.length(), result) == 0)
			resBlock = (*it);

		//if(starts_with(hash, match[0]))
		//	resBlock = (*it);
	}

	return resBlock;
}

int Server::start()
{
	int status;
	printf("Server Started \n");

	socketfd = socket(AF_INET,  SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(2048);

	status = bind(socketfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
	//printf("Listening... \n");

	status = listen(socketfd, 5);
	this->receive();
}

void Server::receive()
{
	socklen_t clilen = sizeof(client_addr);
	//csockfd = accept(socketfd, (struct sockaddr* )&client_addr, &clilen);
	while(1)
	{
		/*
		 * Accept the connection within the server loop
		 * Having it outside caused an issue with the nodejs server whereby it was
		 * unable to reconnect after doing its thing.
		 * Pretty stupid mistake in fairness
		 */
		 csockfd = accept(socketfd, (struct sockaddr* )&client_addr, &clilen);

		printf("\n");
		long nBytes = 0;
		//char buffer[1000];

		/*
		 * Using vector as a buffer instead of a char array; garbage data turns up
		 * due to the fact that I don't use all of the bytes that I statically
		 * allocate to a char array buffer (like char buffer[1000] - I may only
		 * use a tenth of that; the rest is filled in with garbage, a dynamic
		 * data structure like vectors works really well, actually
		 */

		vector<unsigned char> buffer;
		buffer.resize(5000);

		nBytes = recv(csockfd, &buffer[0], buffer.size(), 0);
		//printf("%lu\n", nBytes);
		buffer.resize(nBytes);
		string str(buffer.begin(), buffer.end());
		cout << str << endl;

		if(str.find("PRINT GENESIS BLOCK") != string::npos)
		{
			string response = "\n----GENESIS BLOCK----\n\n";
			response.append(blockchain.Genesis()->ToString());
			send(csockfd, response.c_str(), response.size(), 0);
		}
		else if(str.find("PRINT CHAIN") != string::npos)
		{
			string response = "\n----BLOCK HASHES----\n\n";
			response.append(blockchain.printChain());
			send(csockfd, response.c_str(), response.size(), 0);
		}
		else if(str.find("GET BLOCK") != string::npos)
		{
			string response;
			CBlock* resBlock;
			resBlock = findBlock(str);

			if(resBlock == NULL)
				response = "Block not found";
			else
				response = resBlock->ToString();

			send(csockfd, response.c_str(), response.size(), 0);
		}
		else if(str.find("PRINT CERTS") != string::npos)
		{
			string response;
			CBlock* resBlock;
			resBlock = findBlock(str);

			if(resBlock == NULL)
				response = "Block not found";
			else
			{
				response = "\n----CERT SUBJECTS----\n\n";
				for(vector<Certificate>::iterator it(resBlock->certs.begin());
				     it != resBlock->certs.end(); ++it)
				{
					string data = (*it).getCertData();
					response.append(data);
					response.append("\n");
				}
			}

			send(csockfd, response.c_str(), response.size(), 0);
		}
		else if(str.find("GET CERT") != string::npos)
		{
			bool certFound = false;
			string response, email, data;

			std::regex re("GET CERT (.*)");
			std::smatch match;
			if(std::regex_search(str, match, re) && match.size() > 1)
				email = match.str(1);

			for(std::vector<CBlock*>::iterator it(blockchain.vChain.begin());
			    it != blockchain.vChain.end(); ++it)
			{
				CBlock* block = (*it);
				for(vector<Certificate>::iterator itc(block->certs.begin());
				    itc != block->certs.end(); ++itc)
				{
					data = (*itc).getCertData();
					if(data.find(email) != string::npos)
					{
						certFound = true;
					}
					//I really don't like doing this
					if(certFound)
						break;
				}
				//If there's a better way to do this, I can't think of it right now.
				if(certFound)
					break;
			}

			if(certFound)
				response = data;
			else
				response = "Certificate email not found";

			send(csockfd, response.c_str(), response.size(), 0);
		}
		else if(str.find("GET PUB KEY") != string::npos)
		{
			bool certFound = false;
			string response, email, data;
			Certificate cert;

			std::regex re("GET PUB KEY (.*)");
			std::smatch match;
			if(std::regex_search(str, match, re) && match.size() > 1)
				email = match.str(1);

			for(std::vector<CBlock*>::iterator it(blockchain.vChain.begin());
			    it != blockchain.vChain.end(); ++it)
			{
				CBlock* block = (*it);
				for(vector<Certificate>::iterator itc(block->certs.begin());
				    itc != block->certs.end(); ++itc)
				{
					data = (*itc).getCertData();
					if(data.find(email) != string::npos)
					{
						certFound = true;
						cert = (*itc);
					}
					if(certFound)
						break;
				}
				if(certFound)
					break;
			}

			if(certFound)
			{
				response = "\n";
				response.append(cert.keyToPem(cert.getPublicKey()));
			}
			else
				response = "Certificate email not found";

			send(csockfd, response.c_str(), response.size(), 0);
		}
		else if(str.find("HELP") != string::npos)
		{
			//I realise this should done on the client side, but at this point, I don't really care.

			string response = "\n-----COMMANDS-----\n\n";
			response.append("PRINT GENESIS BLOCK\n");
			response.append("PRINT CHAIN\n");
			response.append("GET BLOCK <block hash>\n");
			response.append("PRINT CERTS <block hash>\n");
			response.append("GET CERT <email>\n");
			response.append("GET PUB KEY <email>\n");
			response.append("SHUTDOWN\n");

			send(csockfd, response.c_str(), response.size(), 0);
		}
		else if(str.find("SHUTDOWN") != string::npos)
		{
			string response = "Shutting down";
			send(csockfd, response.c_str(), response.size(), 0);
			this->closeSockets();
		}
		else
		{
			string response = "Invalid Command";
			send(csockfd, response.c_str(), response.size(), 0);
		}
	}
}

void Server::closeSockets() {
	close(socketfd);
	close(csockfd);
	exit(0);
}

/**
 *	Function for the server to run proof of work on the desired block
 */
uint32_t Server::proofOfWork(CBlockHeader* header, uint32_t difficultyBits)
{
	uint32_t maxNonce = (uint32_t) pow(2, 32);
	//uint32_t target = (uint32_t) pow(2, (256-difficultyBits));
	arith_uint256 target = arith_uint256().SetCompact(difficultyBits);
	uint256 hashOut = uint256();

	CDataStream ss(SER_NETWORK, PROTOCOL_VERSION);
	CHash256 hasher;
	ss << *header;
	assert(ss.size() == 80);
	hasher.Write((unsigned char*) &ss[0], 76);

	clock_t start;
	double duration;

	start = clock();
	for(uint32_t nonce = 0; nonce < maxNonce; nonce++)
	{
		CHash256(hasher).Write((unsigned char*) &nonce, 4).Finalize((unsigned char*) &hashOut);

		//unsigned char* hash = (unsigned char*) &hashOut;
		//arith_uint256 t_hash = UintToArith256(hashOut);

		if(UintToArith256(hashOut) <= target)
		{
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			printf("Success with nonce %d\n", nonce);
			//printf("Hash is %s\n", hashOut.ToString());
			cout << "Hash is: " << hashOut.ToString() << endl;
			printf("Duration = %d mins %d secs\n", (int) duration / 60, (int) duration % 60);
			return nonce;
		}
	}

	printf("Failed after %d (max nonce) tries", maxNonce);
	return maxNonce;
};

/**
 *	Function to verify a nonce obtained through POW
 */
bool Server::verifyProof(CBlockHeader* header, uint32_t nonce, uint32_t difficultyBits)
{
	uint256 hashOut = uint256();
	arith_uint256 target = arith_uint256().SetCompact(difficultyBits);
	CDataStream ss(SER_NETWORK, PROTOCOL_VERSION);
	CHash256 hasher;
	ss << *header;
	assert(ss.size() == 80);
	hasher.Write((unsigned char*) &ss[0], 76);
	CHash256(hasher).Write((unsigned char*) &nonce, 4).Finalize((unsigned char*) &hashOut);

	if(UintToArith256(hashOut) <= target)
	{
		printf("Proof Verified\n\n\n");
		return true;
	}
	else
	{
		printf("Something's wrong\n\n\n");
		return false;
	}
}
