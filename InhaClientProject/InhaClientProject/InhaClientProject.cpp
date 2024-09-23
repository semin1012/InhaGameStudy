// InhaClientProject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <inaddr.h>

#define Buf_Size 1024
void Client_Code();
void Error(const char* msg);
void Log(const char* msg);

char strServerIP[] = "172.30.1.52";
char strClientIP[] = "127.0.0.1";


char strPort[] = "12345";   // 8080(인터넷 열때)처럼 많이 알려진 포트는 사용하지 말것
#include <iostream>

int main()
{
    std::cout << "Client Start!\n";

    Client_Code();

    std::cout << "Client Finished!\n";
}

void Client_Code()
{
    WSADATA wsaData;
    SOCKET serverSocket;
    char msg[Buf_Size];
    int strLength, i;

    SOCKADDR_IN serverAddr, clientAddr;
    int clientAddrSize;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)  // 2.2버전으로 시작한다는 뜻
        Error("WSAStartUp() error!");
    Log("WSAStartUp() OK");

    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET)
        Error("socket() error");
    Log("socekt() OK");

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.S_un.S_addr = inet_addr(strServerIP);
    serverAddr.sin_port = htons(atoi(strPort));

    if (connect(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
        Error("connect() error");
    else
        puts("Connected...");

    while (1)
    {
        fputs("Input Message(Q to quit) : ", stdout);
        fgets(msg, Buf_Size, stdin);
        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n"))
            break;

        send(serverSocket, msg, strlen(msg), 0);
        strLength = recv(serverSocket, msg, Buf_Size - 1, 0);
        msg[strLength] = 0;
        printf("Message from server: %s\n", msg);
    }

    closesocket(serverSocket);
}

void Error(const char* msg)
{
    fputs(msg, stderr); // error log
    fputc('\n', stderr);
    exit(1);
}

void Log(const char* msg)
{
    fputs(msg, stdout); // output log
    fputc('\n', stdout);
}