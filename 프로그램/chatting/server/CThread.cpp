
#include "CThread.h"

DWORD WINAPI CThread::StaticThreadStart( LPVOID lpParam ) {
	CThread* pThread = (CThread*)lpParam;
	return pThread->run();
}

bool CThread::start() {
	if( hThread ) {
		if( WaitForSingleObject( hThread, 0 ) == WAIT_TIMEOUT ) {
			return false;
		}
		CloseHandle( hThread );
	}

	hThread = CreateThread(
		NULL,			
		0,				
		(LPTHREAD_START_ROUTINE)CThread::StaticThreadStart,
		this,
		0,
		&ThreadID
		);

	if( hThread != NULL ) return true;

	return false;
}

void CThread::join() {
	::WaitForSingleObject( hThread, INFINITE );
}

bool CThread::isRunning() {
	if( hThread ){
		DWORD dwExitCode = 0;
		::GetExitCodeThread( hThread, &dwExitCode );
		if( dwExitCode == STILL_ACTIVE ) return true;
	}
	return false;
}