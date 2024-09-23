#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <inaddr.h>

#define Buf_Size 1024
void Server_Code();
void Error(const char* msg);
void Log(const char* msg);

char strServerIP[] = "172.30.1.85";
//char strServerIP[] = "127.0.0.1";

// char strServerIP[] = "127.0.0.1";    // 내 컴퓨터의 IP

char strPort[] = "12345";   // 8080(인터넷 열때)처럼 많이 알려진 포트는 사용하지 말것

int main()
{
    std::cout << "Server Start!\n";

    Server_Code();

    std::cout << "Server Finished!\n";
    return 0;
}

void Server_Code()
{
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    char msg[Buf_Size];
    int strLength, i;

    SOCKADDR_IN serverAddr, clientAddr;
    int clientAddrSize;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)  // 2.2버전으로 시작한다는 뜻
        Error("WSAStartUp() error!");
    Log("WSAStartUp() OK");

    serverSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET)
        Error("socket() error!");
    Log("socket() OK");

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(atoi(strPort));

    if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
        Error("bind() error");
    Log("bind() OK");

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
        Error("listen() error");
    Log("listen() OK");

    clientAddrSize = sizeof(clientAddr);
    i = 0;
    while (true)
    {
        clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &clientAddrSize);
        Log("Accept()...");

        if (clientSocket == SOCKET_ERROR)
            Error("Accept() error");
        else
            printf("Connected client %d", i + 1);

        memset(msg, 0, sizeof(msg));
        while ((strLength = recv(clientSocket, msg, Buf_Size, 0)) > 0)
        {
            printf("%d client: %s", i + 1, msg);
            send(clientSocket, msg, strLength, 0);
            memset(msg, 0, sizeof(msg));
        }

        if (strLength == 0)
        {
            Log("Client disconnected - normal");
        }
        else if (strLength == SOCKET_ERROR)
        {
            int err = WSAGetLastError();
            if (err == WSAECONNRESET)
            {
                Log("Client disconnected - unexpected");
            }
            else
            {
                printf("recv() error : %d\n", err);
            }
        }

        closesocket(clientSocket);
    }

    closesocket(serverSocket);
    WSACleanup();
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