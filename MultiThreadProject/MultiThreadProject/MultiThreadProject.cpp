// MultiThreadProject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>
#include <process.h>

int Value = 0;
int ValuePlusOne = 0;

int Cnt = 0;
bool isChecked = false;

CRITICAL_SECTION cs;

DWORD WINAPI ThFunc1(LPVOID lpParam)
{
    while (1)
    {
        Value = rand() % 1000;
        ValuePlusOne = Value + 1;
    }
    return 0;
}

DWORD WINAPI ThFunc2(LPVOID lpParam)
{
    while (1)
    {
        if (ValuePlusOne != (Value + 1))
        {
            printf("%d : %d, %d \n", Cnt++, ValuePlusOne, Value+1);
        }
    }
    return 0;
}

DWORD WINAPI ThFunc3(LPVOID lpParam)
{
    while (1)
    {
        isChecked = false;
        Value = rand() % 1000;
        ValuePlusOne = Value + 1;
        isChecked = true;
        //printf("[#1] %d : %d, %d \n", Cnt, ValuePlusOne, Value + 1);
    }
    return 0;
}

DWORD WINAPI ThFunc4(LPVOID lpParam)
{
    while (1)
    {
        if (isChecked == true)
        {
            if (ValuePlusOne != (Value + 1))
            {
                printf("%d : %d, %d \n", Cnt++, ValuePlusOne, Value + 1);
            }
        }
    }
    return 0;
}

DWORD WINAPI ThFunc5(LPVOID lpParam)
{
    while (1)
    {
        EnterCriticalSection(&cs);
        Value = rand() % 1000;
        ValuePlusOne = Value + 1;
        LeaveCriticalSection(&cs);
        Sleep(0);
    }
    return 0;
}

DWORD WINAPI ThFunc6(LPVOID lpParam)
{
    while (1)
    {
        EnterCriticalSection(&cs);
        {
            printf("%d : %d, %d \n", Cnt, ValuePlusOne, Value + 1);
            if (ValuePlusOne != (Value + 1))
            {
                printf("%d : %d, %d \n", Cnt++, ValuePlusOne, Value + 1);
            }
        }
        LeaveCriticalSection(&cs);
        Sleep(0);
    }
    return 0;
}

unsigned __stdcall ThFunc7(LPVOID lpParam)
{
    while (1)
    {
        EnterCriticalSection(&cs);
        Value = rand() % 1000;
        ValuePlusOne = Value + 1;
        LeaveCriticalSection(&cs);
        Sleep(0);
    }
    return 0;
}

unsigned __stdcall ThFunc8(LPVOID lpParam)
{
    while (1)
    {
        EnterCriticalSection(&cs);
        {
            printf("%d : %d, %d \n", Cnt, ValuePlusOne, Value + 1);
            if (ValuePlusOne != (Value + 1))
            {
                printf("%d : %d, %d \n", Cnt++, ValuePlusOne, Value + 1);
            }
        }
        LeaveCriticalSection(&cs);
        Sleep(0);
    }
    return 0;
}

int main()
{
    InitializeCriticalSection(&cs);

    DWORD dwThID1, dwThID2;
    HANDLE hThreads[2];

    unsigned long ulStackSize = 0;

    dwThID1 = 0;
    dwThID2 = 0;
    hThreads[0] = NULL;
    hThreads[1] = NULL;

    {
        // 생성. CREATE_SUSPENDED: 일단 만들어두고 신호가 있을 때까지 대기하라는 의미
        //hThreads[0] = CreateThread(NULL, ulStackSize, ThFunc1, NULL, CREATE_SUSPENDED, &dwThID1);
        //hThreads[1] = CreateThread(NULL, ulStackSize, ThFunc2, NULL, CREATE_SUSPENDED, &dwThID2);
        // 위의 코드는 스레드 안정성이 보장되지 않다.

        // 3, 4는 원래 스레드가 어느정도 보장되어야 하는데 윈도우 업데이트 문제인지 안 됨
        // 5, 6은 CriticalSection()을 사용해서 스레드 안전성이 보장된다.
        //hThreads[0] = CreateThread(NULL, ulStackSize, ThFunc5, NULL, CREATE_SUSPENDED, &dwThID1);
        //hThreads[1] = CreateThread(NULL, ulStackSize, ThFunc6, NULL, CREATE_SUSPENDED, &dwThID2);

        // 7, 8번과 같은 형식은 WinAPI에 대해서 safe하다.
        hThreads[0] = (HANDLE)_beginthreadex(NULL, ulStackSize, (unsigned(__stdcall*)(void*))ThFunc7, NULL, 0, (unsigned*)&dwThID1);
        hThreads[1] = (HANDLE)_beginthreadex(NULL, ulStackSize, (unsigned(__stdcall*)(void*))ThFunc8, NULL, 0, (unsigned*)&dwThID1);


        // 실행   
        if (hThreads[0]) ResumeThread(hThreads[0]);
        if (hThreads[1]) ResumeThread(hThreads[1]);

        // 밑에 코드는 스레드 안쪽에서 스레드 죽이고 싶을 때 사용하면 좋음 
        // _end와 Exit는 같은 기능을 한다. 
        _endthreadex(dwThID1);
        _endthreadex(dwThID2);
        //ExitThread(dwThID1);
        //ExitThread(dwThID2);

        // 이 스레드들이 종료될 때까지 프로그램을 나가지 않고 기다린다
        WaitForMultipleObjects(2, hThreads, TRUE, INFINITE);

        if (hThreads[0]) CloseHandle(hThreads[0]);
        if (hThreads[1]) CloseHandle(hThreads[1]);

        DeleteCriticalSection(&cs);

        return 0;
    }
}