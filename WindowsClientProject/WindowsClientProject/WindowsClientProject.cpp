// >> Client 

/*
Q1. 채팅 프로그램 만들기
        채팅 로그 출력
        채팅 입력창 구현
        
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "framework.h"
#include "WindowsClientProject.h"

// >> : 
#include <commdlg.h>
#include <CommCtrl.h>
#include <WinSock2.h>
#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "ws2_32.lib")
int WinSock_Client();
#define WM_ASYNC WM_USER+1
// << : 


// >> : 
WSADATA wsadata;
SOCKET s;
SOCKADDR_IN   addr = { 0 };
TCHAR msg[200], str[100];
TCHAR chat[2000];
char buffer[120];
int msgLen;
int msgCount;

int InitClient(HWND hWnd);
void CloseClient();
int SendMessageToServer();
// << : 

BOOL CALLBACK Dialog1_Proc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

HINSTANCE   g_hInst;

#pragma region Window_Main
#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSCLIENTPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSCLIENTPROJECT));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



HWND ChildWnd[1];
LRESULT CALLBACK ChildWndProc1(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSCLIENTPROJECT));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDI_WINDOWSCLIENTPROJECT);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);


    wcex.lpfnWndProc = ChildWndProc1;
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = _T("Child Window Class 1");
    RegisterClassExW(&wcex);

    return NULL;
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    g_hInst = hInstance;

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}



#pragma endregion


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static RECT rectView;
    switch (message)
    {
    case WM_CREATE:
        GetClientRect(hWnd, &rectView);
        InitClient(hWnd);
        DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, (DLGPROC)Dialog1_Proc);
        break;

    case WM_ASYNC:
        switch (lParam)
        {
        case FD_READ:
            msgLen = recv(s, buffer, 120, 0);
            buffer[msgLen] = NULL;
#ifdef _UNICODE
            msgLen = MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), NULL, NULL);
            MultiByteToWideChar(CP_ACP, 0, buffer, strlen(buffer), msg, msgLen);
            msg[msgLen] = NULL;
#else
            strcpy_s(msg, buffer);
#endif
            wcscat_s(chat, msg);
            wcscat_s(chat, _T("\r\n"));
            InvalidateRect(hWnd, NULL, true);
            break;
        }
        break;

    case WM_CHAR:
        if (wParam == VK_RETURN)
            return SendMessageToServer();
        str[msgCount++] = wParam;
        str[msgCount] = NULL;
        InvalidateRect(hWnd, NULL, true);
        break;

    case WM_KEYDOWN:
        //send(s, "Hello Server!", 13, 0);
        break;

    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            
            TextOut(hdc, 0, 400, str, _tcslen(str));
            
            if (_tcscmp(msg, _T("")))
                TextOut(hdc, 0, 430, msg, _tcslen(msg));

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

int WinSock_Client()
{
    return 0;
}

int InitClient(HWND hWnd)
{        
    WSAStartup(MAKEWORD(2, 2), &wsadata);

    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET)
    {
        MessageBox(NULL, _T("socket() failed"), _T("Error"), MB_OK);
        return 0;
    }

    MessageBox(NULL, _T("socket() OK"), _T("Success"), MB_OK);

    addr.sin_family = AF_INET;
    addr.sin_port = 20;
    addr.sin_addr.S_un.S_addr = inet_addr("172.30.1.85"); // "127.0.0.1");

    if (connect(s, (LPSOCKADDR)&addr, sizeof(addr)) == SOCKET_ERROR)
    {
        return 0;
    }

    WSAAsyncSelect(s, hWnd, WM_ASYNC, FD_READ);
    return 1;
}

void CloseClient()
{
    // >> :
    closesocket(s);
    WSACleanup();
    // << :

    return;
}

int SendMessageToServer()
{
    if (s == INVALID_SOCKET) return 0;

#ifdef _UNICODE 
    msgLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
    WideCharToMultiByte(CP_ACP, 0, str, -1, buffer, msgLen, NULL, NULL);
    msg[msgLen] = NULL;
#else 
    strcpy(buffer, str);
    msgLen = strlen(buffer);
#endif
    send(s, (LPSTR)buffer, msgLen + 1, 0);
    msgCount = 0;

    _tcscpy_s(str, _T(""));
    return 1;
}

BOOL CALLBACK Dialog1_Proc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        SetFocus(GetDlgItem(hDlg, IDC_EDIT_MYCHAT));
        SetTimer(hDlg, 1, 100, NULL);
        return 1;
        break;
    case WM_CHAR:
        if (wParam == VK_RETURN)
        {
            GetDlgItemText(hDlg, IDC_EDIT_MYCHAT, str, 100);
            SetDlgItemText(hDlg, IDC_EDIT_MYCHAT, _T(""));
            return SendMessageToServer();
        }
        str[msgCount++] = wParam;
        str[msgCount] = NULL;
        SetDlgItemText(hDlg, IDC_EDIT_MYCHAT, str);
        InvalidateRect(hDlg, NULL, true);
        break;
    case WM_COMMAND:
        switch (wParam)
        {
        case IDC_BNT_EXIT:
            PostQuitMessage(0);
            break;
        case IDC_BNT_SEND:
            GetDlgItemText(hDlg, IDC_EDIT_MYCHAT, str, 100);
            SetDlgItemText(hDlg, IDC_EDIT_MYCHAT, _T(""));
            SetFocus(GetDlgItem(hDlg, IDC_EDIT_MYCHAT));
            return SendMessageToServer();
            break;
        }
        break;
    case WM_TIMER:
        SetDlgItemText(hDlg, IDC_EDIT_CHAT, chat);
        break;
    case WM_DESTROY:
        CloseClient();
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hDlg, uMsg, wParam, lParam);
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}


LRESULT ChildWndProc1(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    TCHAR word;

    switch (message)
    {
    case WM_CREATE:
        DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, (DLGPROC)Dialog1_Proc);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);


        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
