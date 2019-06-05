#pragma once

#ifndef __CHATTINGCLIENT_CONF__
#define __CHATTINGCLIENT_CONF__

#include <iostream>
#include <cstring>
#include <cstdio>
#include <WinSock2.h>
#include "CThread.h"
#include "ChatException.h"


class ChattingClient;
class SendThread;
class RecvThread;
class SendRecvInterface;

namespace UserCommand {
	const char * const EXIT = "/exit";
};

typedef struct _MSG{
	char data[256];
} Message;

class ChattingClient {
private:
	SendThread *st;
	RecvThread *rt;
	SOCKET client_socket;
	SOCKADDR_IN server_address;

	void connectServer();
public:
	ChattingClient(const char *ip, int port);
	~ChattingClient();

	int run();

	static const int MAXSTRLEN;
};


class SendRecvInterface : public CThread {
public:
	virtual DWORD run(void)=0;
	void sendMessage(SOCKET socket, const char *buf);
	void recvMessage(SOCKET socket, char *buf);
	void gotoxy(int x, int y);
};


class SendThread : public SendRecvInterface {
private:
	SOCKET client_socket;

public:
	SendThread(SOCKET cs);
	virtual DWORD run(void);

	bool exitUser(const char *buf);
	void printcin(const char*);
};

class RecvThread : public SendRecvInterface {
private:
	SOCKET client_socket;

public:
	RecvThread(SOCKET cs);
	virtual DWORD run(void);
	void printcout(const char*);
};

#endif