#include "framework.h"
#include "WinAPIHopscotch.h"
#include "commdlg.h"
#include <stdio.h>

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800

/*
player
    - 이동
    - 플레이어 영역을 벗어났을 경우 이동한 곳을 선으로 표시
    - 플레이어 영역에 닿았을 경우 이동한 선을 플레이어 영역으로 추가
        => 어떻게? 선을 어떻게 영역으로 추가할 것인지?
        => Polygon Triangulation

map
    - 플레이어 영역
    - 장애물 영역

obstance
    - 날라오는 장애물
*/

#define MAX_LOADSTRING 100

HINSTANCE hInst;                               
WCHAR szTitle[MAX_LOADSTRING];                 
WCHAR szWindowClass[MAX_LOADSTRING];           

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 사용자 정의
void Update();
void Gdi_Init();
void Gdi_Draw(HDC hdc);
void Gdi_End();

ULONG_PTR g_GdipPlusToken;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPIHOPSCOTCH, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPIHOPSCOTCH));

    MSG msg;

    Gdi_Init();

    while (true)
    {
        if ((PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)))
        {
            if (msg.message == WM_QUIT)
            {
                break;
            }
            else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            Update();
        }
    }

    Gdi_End();

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPIHOPSCOTCH));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPIHOPSCOTCH);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

#include "Player.h"
#include "GameObject.h"
#include <vector>
using namespace std;
#define TIMER_UPDATE_ID 1

vector<GameObject*> objects;
Player *player;

RECT                rectView;

HDC                 hdc, MemDC, tmpDC;
HBITMAP             BackBit, oldBackBit;
RECT                bufferRT;
PAINTSTRUCT         ps;

BOOL                bGameOver = FALSE;

void CreateDoubbleBuffering(HWND hWnd);
void EndDoubleBuffering(HWND hWnd);

VOID CALLBACK UpdateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        player = new Player(200, 200, 10);
        objects.push_back(player);
        Gdi_Init();
        for (auto obj : objects)
            obj->CreateBitmap();
        SetTimer(hWnd, TIMER_UPDATE_ID, 33, (TIMERPROC)UpdateProc);
        GetClientRect(hWnd, &rectView);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
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
            CreateDoubbleBuffering(hWnd);

            Gdi_Draw(hdc);

            EndDoubleBuffering(hWnd);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_SIZE:
        GetClientRect(hWnd, &rectView);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        KillTimer(hWnd, TIMER_UPDATE_ID);
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

void Update()
{
    DWORD newTime = GetTickCount();
    static DWORD oldTime = newTime;

    if (newTime - oldTime < 100)
        return;

    oldTime = newTime;

    //시간 보정
    //oldTime = newTime - ((newTime - oldTime) % 100);

    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        player->MoveTo(rectView, -1, 0);
    }
    if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        player->MoveTo(rectView, 1, 0);
    }
    if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        player->MoveTo(rectView, 0, -1);
    }
    if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        player->MoveTo(rectView, 0, 1);
    }
}

void Gdi_Init()
{
    GdiplusStartupInput gpsi;
    if (GdiplusStartup(&g_GdipPlusToken, &gpsi, NULL) != Ok)
    {
        MessageBox(NULL, TEXT("GDI+ 라이브러리를 초기화할 수 없습니다."), TEXT("알림"), MB_OK);
    }
}

void Gdi_Draw(HDC hdc)
{
    Graphics graphics(hdc);

    for (int i = 0; i < objects.size(); i++)
        objects[i]->Draw(hdc);
}

void Gdi_End()
{
    GdiplusShutdown(g_GdipPlusToken);
}


void CreateDoubbleBuffering(HWND hWnd)
{
    hdc = BeginPaint(hWnd, &ps);

    GetClientRect(hWnd, &bufferRT);
    MemDC = CreateCompatibleDC(hdc);
    BackBit = CreateCompatibleBitmap(hdc, bufferRT.right, bufferRT.bottom);
    oldBackBit = (HBITMAP)SelectObject(MemDC, BackBit);
    PatBlt(MemDC, 0, 0, bufferRT.right, bufferRT.bottom, WHITENESS);
    tmpDC = hdc;
    hdc = MemDC;
    MemDC = tmpDC;
}

void EndDoubleBuffering(HWND hWnd)
{
    tmpDC = hdc;
    hdc = MemDC;
    MemDC = tmpDC;
    GetClientRect(hWnd, &bufferRT);
    BitBlt(hdc, 0, 0, bufferRT.right, bufferRT.bottom, MemDC, 0, 0, SRCCOPY);
    SelectObject(MemDC, oldBackBit);
    DeleteObject(BackBit);
    DeleteDC(MemDC);
    EndPaint(hWnd, &ps);
}

VOID UpdateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
    for (auto obj : objects)
        obj->Update();

    InvalidateRect(hwnd, NULL, false);
}
