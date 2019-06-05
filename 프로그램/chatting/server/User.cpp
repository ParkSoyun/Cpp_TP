
#include "User.h"
#include "App.h"

const int User::MAXSTRLEN=255;

User::User(SOCKET cs, SOCKADDR_IN ca) : client_socket(cs), client_address(ca) {
}

User::~User(){
	closeSession();
	ThreadClose();
}

SOCKET User::getSocket() const {
	return this->client_socket;
}

char* User::getIP() const {
	static char *address = inet_ntoa(this->client_address.sin_addr);
	return address;
}

int User::getPort() const {
	return ntohs(this->client_address.sin_port);
}

void User::closeSession(){
	closesocket(this->client_socket);
}

DWORD User::run(void) {
	char buf[User::MAXSTRLEN];

	while (true) {
		try {
			recvMessage(buf);
			stringstream oss;
			oss << "(" << getIP() << ":" << getPort() <<") : " << buf;
			sendMessageAll(oss.str().c_str());
			cout << "(" << getIP() << ":" << getPort() <<") : " << buf << endl;
		} catch (ChatException e){
			stringstream oss;
			oss << "(" << getIP() << ":" << getPort() <<") : " << "유저가 나갔습니다. ";
			sendMessageAll(oss.str().c_str());
			printLeaveUser(*this);
			break;
		}
	}

	WaitForSingleObject(App::hMutex, INFINITE);
	int len = App::userList.size();
	for (int i=0; i<len; i++){
		User *user = App::userList.at(i);
		if (user->getSocket() == this->getSocket()){
			App::userList.erase(App::userList.begin()+i);
			break;
		}
	}
	ReleaseMutex(App::hMutex);
	delete this;
	return 0;
}

void User::recvMessage(char *buf){
	Message msg;
	int len=0;
	memset(&msg, 0, sizeof(Message));

	if (recv(this->client_socket, (char*)&msg, sizeof(Message), 0) <= 0){
		throw ChatException(1100);
	}
	len = strnlen(msg.data, User::MAXSTRLEN);
	strncpy(buf, msg.data, strnlen(msg.data, User::MAXSTRLEN));
	buf[len] = 0;
}

void User::sendMessageAll(const char *buf) {
	int len = App::userList.size();
	for (int i=0; i<len; i++){
		User *user = App::userList.at(i);
		try{
			sendMessage(user->getSocket(), buf);
		} catch(ChatException e) {}
	}
}

void User::sendMessage(SOCKET socket, const char *buf){
	Message msg;
	memset(&msg, 0, sizeof(Message));

	if (buf != nullptr) {
		int len = strnlen(buf, User::MAXSTRLEN);
		strncpy(msg.data, buf, len);
		msg.data[len]=0;
	}
	
	WaitForSingleObject(App::hMutex, INFINITE);
	if (send(socket, (const char*)&msg, sizeof(Message), 0) <= 0){
		ReleaseMutex(App::hMutex);
		throw ChatException(1100);
	}
	ReleaseMutex(App::hMutex);
}

void User::printLeaveUser(const User &user) const {
	cout << "유저가 나갔습니다. (" << user.getIP() << " : " << user.getPort() << ")" << endl;
}
