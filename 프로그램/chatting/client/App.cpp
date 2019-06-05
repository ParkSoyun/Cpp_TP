
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

	cout <<	"========< 채팅 클라이언트 프로그램 >========\n"
				"============================================\n"
				"====\t\t\t\t\t====\n"
				"====\tVersion : v1.0.0\t\t====\n"
				"====\t\t\t\t\t====\n"
				"====\tCreate By : 찬차나찬찬차난차눙\t====\n"
				"====\t\t\t\t\t====\n"
				"====\tEmail : lead788@gmail.com\t====\n"
				"====\t\t\t\t\t====\n"
				"============================================\n"
				"============================================\n";
	cout << "서버 IP주소 => ";
	cin >> buf;
	cout << "서버 Port번호 => ";
	cin >> port;

	sprintf(this->serverip, "%s", buf);
	this->serverport = port;
}

void App::printExit() {
	cout << "서버의 연결이 종료됐습니다." << endl;
}
void App::printError() {
	cout << "서버의 연결이 끊겼습니다." << endl;
}