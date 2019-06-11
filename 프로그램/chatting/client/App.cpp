
#include "App.h"

HANDLE App::hMutex = CreateMutex(NULL, FALSE, NULL);

App::App() : serverport(0) {
	memset(serverip, 0, sizeof(serverip));
}

App::~App() {
	delete chattingclient;
}

void App::start() {
	int result = 0;

	printStart();
	chattingclient = new ChattingClient(this->serverip, this->serverport);

	try { 
		result = chattingclient->run();
	} catch (ChatException e) {
		e.printError();
		return;
	}

	if (result == 0){
		printExit();
	} else {
		printError();
	}
}

void App::printStart() {
	char buf[16];
	int port;

	cout << "==============< 채팅 클라이언트 프로그램 >==============\n"
		"========================================================\n"
		"========\t\t\t\t\t========\n"
		"========\t    Version : v1.0.0\t        ========\n"
		"========\t\t\t\t\t========\n"
		"========      안동대학교 컴퓨터공학과 8조\t========\n"
		"========\t\t\t\t\t========\n"
		"========      권산, 박소윤, 이지연, 천준민\t========\n"
		"========\t\t\t\t\t========\n"
		"========================================================\n"
		"========================================================\n"
		"\n\n\n\n";


	cout << "서버 IP주소 >> ";
	cin >> buf;
	cout << "서버 Port번호 >> ";
	cin >> port;

	sprintf(this->serverip, "%s", buf);
	this->serverport = port;
}

void App::printExit() {
	cout << "연결이 종료되었습니다." << endl;
}
void App::printError() {
	cout << "연결이 끊겼습니다." << endl;
}