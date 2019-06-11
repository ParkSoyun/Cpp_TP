
#include "App.h"

vector<User*> App::userList = vector<User*>();
const int App::MAXUSER = 10;
HANDLE App::hMutex = CreateMutex(NULL, FALSE, NULL);

App::App() : chattingserver(nullptr, 3490) {
}

void App::printNewUser(const User *user) const {
	cout << "새 유저가 접속했습니다. (" << user->getIP() << ", " << user->getPort() << ")" << endl;
}

void App::printExceedUser(const User *user) const {
	cout << "새 유저가 접속에 실패했습니다. (" << user->getIP() << ", " << user->getPort() << ")" << endl;
}

void App::start() {
	chattingserver.binding();
	chattingserver.listening(10);

	cout << "=================< 채팅 서버 프로그램 >=================\n"
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
		"\n\n\n";

	cout << "------------------------- L o g ------------------------- " << endl;

	while (true){
		User *user = chattingserver.acceptUser();
		if (App::userList.size() >= App::MAXUSER){
			printExceedUser(user);
			continue;
		}

		WaitForSingleObject(App::hMutex, INFINITE);
		App::userList.push_back(user);
		ReleaseMutex(App::hMutex);
		printNewUser(user);
		stringstream oss;
		oss << "(" << user->getIP() << ":" << user->getPort() <<") : " << "새 유저가 접속했습니다. ";
		user->sendMessageAll(oss.str().c_str());
		user->start();
	}
}