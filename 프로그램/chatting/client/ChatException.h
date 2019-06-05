#pragma once

#ifndef __EXCEPTION_CONF__
#define __EXCEPTION_CONF__

#include <iostream>

using std::cerr;
using std::endl;

class ChatException {
private:
	int code;

public:
	ChatException(int code) : code(code) {};

	int getCode() const { return code; }
	void printError() {
		switch (code){
		case 1000:
			cerr << "소켓 생성 에러 (에러코드:" << code << ")" << endl;
			break;
		case 1001:
			cerr << "서버 접속 에러 (에러코드:" << code << ")" << endl;
			break;
		case 1100:
			cerr << "세션 연결 에러 (에러코드:" << code << ")" << endl;
			break;
		case 2100:
			cerr << "접속 종료 (코드:" << code << ")" << endl;
			break;
		}
	}


};

#endif