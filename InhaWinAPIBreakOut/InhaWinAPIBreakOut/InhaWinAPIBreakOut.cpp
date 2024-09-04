// InhaWinAPIBreakOut.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "InhaWinAPIBreakOut.h"
#pragma comment(lib, "Msimg32.lib")

#define MAX_LOADSTRING  100
#define WINDOW_WIDTH    815
#define WINDOW_HEIGHT   815
#define WINDOW_X        200
#define WINDOW_Y        150


HINSTANCE hInst;                                
WCHAR szTitle[MAX_LOADSTRING];                  
WCHAR szWindowClass[MAX_LOADSTRING];            

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


    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_INHAWINAPIBREAKOUT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);


    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_INHAWINAPIBREAKOUT));

    MSG msg;


    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_INHAWINAPIBREAKOUT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_INHAWINAPIBREAKOUT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; 

   HWND hWnd = CreateWindowW(szWindowClass, _T("벽돌 깨기"), WS_OVERLAPPEDWINDOW,
      WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

#include "GameObject.h"
#include "Player.h"
#include "Obstacle.h"
#include <vector>
using namespace std;

#define TIMER_UPDATE 1
#define TIMER_KEYSTATE 2

vector<GameObject*> objects;
Player* player = new Player({ 400, 700 }, 50, 1);
RECT rectView;

VOID CALLBACK UpdateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);
VOID CALLBACK KeyStateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);
void InitObjects();

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HBRUSH hBrush;
    HGDIOBJ oldBrush;

    switch (message)
    {
    case WM_CREATE:
        SetTimer(hWnd, TIMER_UPDATE, 33, (TIMERPROC)UpdateProc);
        SetTimer(hWnd, TIMER_KEYSTATE, 33, (TIMERPROC)KeyStateProc);
        GetClientRect(hWnd, &rectView);
        InitObjects();
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            hdc = GetDC(hWnd); 

            HDC hMemdc = CreateCompatibleDC(hdc);
            hBrush = CreateSolidBrush(RGB(0, 0, 0));

            for (auto obj : objects)
            {
                obj->Draw(hdc, hBrush);
            }
            
            ReleaseDC(hWnd, hMemdc);
            ReleaseDC(hWnd, hdc); 
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_SIZE:
        GetClientRect(hWnd, &rectView);
        break;
    case WM_DESTROY:
        KillTimer(hWnd, TIMER_UPDATE);
        KillTimer(hWnd, TIMER_KEYSTATE);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


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

VOID CALLBACK UpdateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
    for (auto obj : objects)
    {
        obj->Update();
    }

    InvalidateRect(hwnd, NULL, true);
}

VOID CALLBACK KeyStateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
    if (GetKeyState('A') & 0x8000)
    {
        player->MoveTo(rectView, { -10, 0 });
    }
    if (GetKeyState('D') & 0x8000)
    {
        player->MoveTo(rectView, { 10, 0 });
    }
    if (GetKeyState('W') & 0x8000)
    {
        player->MoveTo(rectView, { 0, -10 });
    }
    if (GetKeyState('S') & 0x8000)
    {
        player->MoveTo(rectView, { 0, 10 });
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        player->Attack();
    }
    
    InvalidateRect(hwnd, NULL, true);
}

void InitObjects()
{
    objects.push_back(player);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Obstacle* obstacle = new Obstacle({ 0 + 80 * i + 40, 200 - j * HEIGHT_HALF_SIZE * 2 }, 40, 10 * (j + 1), j + 1);
            objects.push_back(obstacle);
        }
    }
}
