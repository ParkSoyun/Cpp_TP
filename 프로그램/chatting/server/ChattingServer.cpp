
#include "ChattingServer.h"

ChattingServer::ChattingServer(const char *ip, int port){

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	this->server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->server_socket == INVALID_SOCKET){
		throw ChatException(1000);
		WSACleanup();
	}

	memset(&this->server_address, 0, sizeof(this->server_address));
	if (ip != nullptr) {
		this->server_address.sin_addr.S_un.S_addr = inet_addr(ip);
	} else {
		this->server_address.sin_addr.S_un.S_addr = INADDR_ANY;
	}
	this->server_address.sin_port = htons(port);
	this->server_address.sin_family = AF_INET;
}

ChattingServer::~ChattingServer(){
	closesocket(this->server_socket);
	WSACleanup();
}

void ChattingServer::binding(){
	if (bind(this->server_socket, (SOCKADDR*)&this->server_address, sizeof(this->server_address)) == SOCKET_ERROR){
		throw ChatException(1001);
	}
}

void ChattingServer::listening(int size){
	if (size <= 0) throw ChatException(1002);
	if (listen(this->server_socket, size) == SOCKET_ERROR){
		throw ChatException(1002);
	}
}

User* ChattingServer::acceptUser(){
	SOCKET client_socket;
	SOCKADDR_IN client_address;
	int len = sizeof(client_address);
	client_socket = accept(this->server_socket, (SOCKADDR*)&client_address, &len);
	return new User(client_socket, client_address);
}