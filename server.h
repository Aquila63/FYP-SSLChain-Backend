#ifndef SERVERTEST_NET_H_H
#define SERVERTEST_NET_H_H

#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>

#include "chain.h"

class Server
{
public:
	/*
	 * Server Suff
	 */
	int socketfd, csockfd;
	struct sockaddr_in serv_addr, client_addr;

	/*
	 * SSLC stuff
	 */
	CChain blockchain;

	Server();
	int start();
	void receive();
	void closeSockets();
};

#endif //SERVERTEST_NET_H_H
