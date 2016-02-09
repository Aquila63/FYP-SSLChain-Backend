#ifndef SERVERTEST_NET_H_H
#define SERVERTEST_NET_H_H

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <tuple>


#include "chain.h"

class Server
{
public:
	/*
	 * Server Stuff
	 */
	int socketfd, csockfd;
	struct sockaddr_in serv_addr, client_addr;
	Server();
	int start();
	void receive();
	void closeSockets();

	/*
	 * SSLC stuff
	 */
	CChain blockchain;
	CBlock* findBlock(string cmd);
	uint32_t proofOfWork(CBlockHeader* header, uint32_t difficultyBits);
	bool verifyProof(CBlockHeader* header, uint32_t nonce, uint32_t difficultyBits);
};

#endif //SERVERTEST_NET_H_H
