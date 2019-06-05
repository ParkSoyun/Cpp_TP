
#include "ChattingClient.h"
#include "App.h"

const int ChattingClient::MAXSTRLEN = 255;

ChattingClient::ChattingClient(const char *ip, int port) {
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	this->client_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (this->client_socket == INVALID_SOCKET){
		throw ChatException(1000);
		WSACleanup();
	}

	memset(&this->server_address, 0, sizeof(this->server_address));
	this->server_address.sin_addr.S_un.S_addr = inet_addr(ip);
	this->server_address.sin_port = htons(port);
	this->server_address.sin_family = AF_INET;
}

ChattingClient::~ChattingClient() {
	closesocket(this->client_socket);
	delete this->st;
	delete this->rt;
	WSACleanup();
}

void ChattingClient::connectServer() {
	cout << "서버 접속 시도중..." << endl;
	if (connect(this->client_socket, (SOCKADDR*)&this->server_address, sizeof(this->server_address)) == SOCKET_ERROR){
		cout << "서버 접속 실패" << endl;
		throw ChatException(1001);
	}
	cout << "서버에 접속했습니다." << endl;
}

int ChattingClient::run() {
	this->st = new SendThread(this->client_socket);
	this->rt = new RecvThread(this->client_socket);
	connectServer();
	st->start();
	rt->start();
	st->join();
	rt->join();
	return st->getExitCode();
}





void SendRecvInterface::recvMessage(SOCKET socket, char *buf){
	Message msg;
	int len = 0;
	memset(&msg, 0, sizeof(Message));

	if (recv(socket, (char*)&msg, sizeof(Message), 0) <= 0){
		throw ChatException(1100);
	}
	len = strnlen(msg.data, ChattingClient::MAXSTRLEN);
	strncpy(buf, msg.data, len);
	buf[len]=0;
}

void SendRecvInterface::sendMessage(SOCKET socket, const char *buf){
	Message msg;
	memset(&msg, 0, sizeof(Message));

	if (buf != nullptr) {
		int len = strnlen(buf, ChattingClient::MAXSTRLEN);
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

void SendRecvInterface::gotoxy(int x, int y) {
	COORD Cur;
	Cur.X=x;
	Cur.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}



SendThread::SendThread(SOCKET cs) : client_socket(cs) {
	
}

DWORD SendThread::run(void) {
	int result = -1;
	char buf[ChattingClient::MAXSTRLEN];
	while (true){
		try {
			cin >> buf;
			if (exitUser(buf)){
				result = 0;
				throw ChatException(2100);
			}
			sendMessage(this->client_socket, buf);
		} catch (ChatException e){
			closesocket(this->client_socket);
			break;
		}
	}
	return result;
}

bool SendThread::exitUser(const char *buf) {
	if (stricmp(buf, UserCommand::EXIT) == 0){
		return true;
	}
	return false;
}

void SendThread::printcin(const char*) {
	gotoxy(1, 1);
}



RecvThread::RecvThread(SOCKET cs) : client_socket(cs) {

}

DWORD RecvThread::run(void) {
	char buf[ChattingClient::MAXSTRLEN];
	while (true){
		try {
			recvMessage(this->client_socket, buf);
			cout << buf << endl;
		} catch (ChatException e){
			closesocket(this->client_socket);
			break;
		}
	}
	return 0;
}