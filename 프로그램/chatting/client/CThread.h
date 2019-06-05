#pragma once

#ifndef __CTHREAD_CONF__
#define __CTHREAD_CONF__

#include <iostream>
#include <Windows.h>
#include "ChatException.h"

class CThread {
private:
	HANDLE hThread;
	DWORD  ThreadID;

	static DWORD WINAPI StaticThreadStart( LPVOID lpParam );

protected:
	virtual DWORD run(void) = 0;

public:
	CThread() : hThread( NULL ), ThreadID( 0 ) {}
	
	void ThreadClose() {
		if( hThread ) CloseHandle( hThread );
	}

	bool start();
	void join();
	bool isRunning();
	DWORD getExitCode();
};


#endif