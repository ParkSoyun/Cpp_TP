#pragma once

#ifndef __APP_CONF__
#define __APP_CONF__

#include <iostream>
#include "ChattingClient.h"
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

class App {
private:
	char serverip[16];
	int serverport;
	ChattingClient *chattingclient;

public:
	App();
	~App();

	void start();
	void printStart();
	void printExit();
	void printError();

	static HANDLE hMutex;
};

#endif