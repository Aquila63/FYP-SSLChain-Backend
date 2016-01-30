#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string>

#include "server.h"

using std::cout;
using std::string;

Server::Server() { }

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
	csockfd = accept(socketfd, (struct sockaddr* )&client_addr, &clilen);
	while(1)
	{
		//printf("Receiving...\n");
		char buffer[1000];
		recv(csockfd, buffer, 1000, 0);
		string str(buffer);
		if(str.find("PRINT GENESIS BLOCK") != string::npos)
		{
			string response = "----GENESIS BLOCK----\n";
			response.append(blockchain.Genesis()->ToString());
			send(csockfd, response.c_str(), response.size(), 0);
		}
		else
		{
			string response = "No commands sent";
			send(csockfd, response.c_str(), response.size(), 0);
		}
	}

	//this->closeSockets();

}

void Server::closeSockets() {
	close(socketfd);
	close(csockfd);
}