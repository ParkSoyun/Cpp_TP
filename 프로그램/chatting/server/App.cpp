
#include "App.h"

vector<User*> App::userList = vector<User*>();
const int App::MAXUSER = 10;
HANDLE App::hMutex = CreateMutex(NULL, FALSE, NULL);

App::App() : chattingserver(nullptr, 3490) {
}

void App::printNewUser(const User *user) const {
	cout << "�� ������ �����߽��ϴ�. (" << user->getIP() << ", " << user->getPort() << ")" << endl;
}

void App::printExceedUser(const User *user) const {
	cout << "�� ������ ���ӿ� �����߽��ϴ�. (" << user->getIP() << ", " << user->getPort() << ")" << endl;
}

void App::start() {
	chattingserver.binding();
	chattingserver.listening(10);

	cout <<	"============< ä�� ���� ���α׷� >==========\n"
				"============================================\n"
				"====\t\t\t\t\t====\n"
				"====\tVersion : v1.0.0\t\t====\n"
				"====\t\t\t\t\t====\n"
				"====\tCreate By : ������������������\t====\n"
				"====\t\t\t\t\t====\n"
				"====\tEmail : lead788@gmail.com\t====\n"
				"====\t\t\t\t\t====\n"
				"============================================\n"
				"============================================\n";

	cout << "Log : " << endl;

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
		oss << "(" << user->getIP() << ":" << user->getPort() <<") : " << "�� ������ �����߽��ϴ�. ";
		user->sendMessageAll(oss.str().c_str());
		user->start();
	}
}