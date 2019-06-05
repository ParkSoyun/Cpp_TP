#pragma once

#ifndef __CHATTINGSERVER_CONF__
#define __CHATTINGSERVER_CONF__

#include <iostream>
#include <WinSock2.h>
#include "User.h"
#include "ChatException.h"

class ChattingServer {
private:
	SOCKET server_socket;
	SOCKADDR_IN server_address;

public:
	ChattingServer(const char *ip=nullptr, int port=0);
	~ChattingServer();

	void binding();
	void listening(int size);
	User* acceptUser();


};

#endif