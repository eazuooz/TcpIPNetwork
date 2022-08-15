// Thread.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
#include <process.h>

unsigned WINAPI ThreadFunc(void* arg)
{
	int i;
	int cnt = *((int*)arg);
	for (i = 0; i < cnt; i++)
	{
		Sleep(10000);  puts("running thread");
	}
	return 0;
}

int main()
{
    HANDLE hThread;
    unsigned int threadID;
    int param = 5;

	hThread = (HANDLE)_beginthreadex
				(NULL, 0, ThreadFunc, (void*)&param, 0, &threadID);

	if (hThread == 0)
	{
		puts("_beginthreadex() error");
		return -1;
	}

	Sleep(30000);
	puts("end of main");

    return 0;
}


