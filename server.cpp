#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <regex>
//#include <boost/algorithm/string/predicate.hpp>

#include "server.h"

using std::cout;
using std::endl;
using std::string;
//using boost::starts_with;

Server::Server() { }

CBlock* Server::findBlock(string str)
{
	string result;
	std::regex re("GET BLOCK (.*)");
	std::smatch match;
	//cout << str << endl;
	//assert(std::regex_search(str, match, re));
	if(std::regex_search(str, match, re) && match.size() > 1)
		result = match.str(1); //Flagged as an error, but still compiles.

	//Debugger says that result is empty, but cout prints it
	//Shit's strange
	//cout << "REGEX RESULT = " << result << endl;

	CBlock* resBlock = NULL;

	for(std::vector<CBlock*>::iterator it(blockchain.vChain.begin()); it != blockchain.vChain.end(); ++it)
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
	csockfd = accept(socketfd, (struct sockaddr* )&client_addr, &clilen);
	while(1)
	{
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
		buffer.resize(nBytes);
		string str(buffer.begin(), buffer.end());

		if(str.find("PRINT GENESIS BLOCK") != string::npos)
		{
			string response = "----GENESIS BLOCK----\n";
			response.append(blockchain.Genesis()->ToString());
			send(csockfd, response.c_str(), response.size(), 0);
		}
		else if(str.find("PRINT CHAIN") != string::npos)
		{
			string response = "----BLOCK HASHES----\n";
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
				response = "----CERT SUBJECTS----\n";
				for (std::vector<Certificate>::iterator it(resBlock->certs.begin());
				     it != resBlock->certs.end(); ++it)
				{
					string data = (*it).getCertData();
					response.append(data);
					response.append("\n");
				}
			}

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