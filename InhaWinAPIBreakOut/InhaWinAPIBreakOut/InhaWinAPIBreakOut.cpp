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
Player*             player = new Player({ 400, 700 }, 50, 1);
RECT                rectView;

HDC                 hdc, MemDC, tmpDC;
HBITMAP             BackBit, oldBackBit;
RECT                bufferRT;
PAINTSTRUCT         ps;

VOID CALLBACK UpdateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);
VOID CALLBACK KeyStateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);

void InitObjects();
void CreateDoubbleBuffering(HWND hWnd);
void EndDoubleBuffering(HWND hWnd);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HBRUSH hBrush;
    static HGDIOBJ oldBrush;

    switch (message)
    {
    case WM_CREATE:
        srand(time(NULL));
        SetTimer(hWnd, TIMER_UPDATE, 33, (TIMERPROC)UpdateProc);
        SetTimer(hWnd, TIMER_KEYSTATE, 33, (TIMERPROC)KeyStateProc);
        GetClientRect(hWnd, &rectView);
        InitObjects();
        break;
    case WM_PAINT:
        {
            CreateDoubbleBuffering(hWnd);
            for (auto obj : objects)
            {
                obj->Draw(hdc);
            }
            EndDoubleBuffering(hWnd);
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
    vector <bool> flag(objects.size(), false);
    GameObject* ball = NULL;

    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->Update(rectView);

        if (objects[i]->GetType() == EObjectType::Ball)
        {
            ball = objects[i];
        }
    }

    InvalidateRect(hwnd, NULL, false);

    if (ball == NULL) return;

    vector<GameObject*> removeObj;

    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i]->GetType() == EObjectType::Obstacle)
        {
            // 삭제해야 함
            if (objects[i]->Collision(*ball))
            {
                removeObj.push_back(objects[i]);
            }
        }
        if (objects[i]->GetType() == EObjectType::Player)
        {
            objects[i]->Collision(*ball);
        }
    }

    for (int i = 0; i < removeObj.size(); i++)
    {
        objects.erase(remove(objects.begin(), objects.end(), removeObj[i]), objects.end());
    }
}

VOID CALLBACK KeyStateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
    if (GetKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        player->MoveTo(rectView, { -10, 0 });
    }
    if (GetKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        player->MoveTo(rectView, { 10, 0 });
    }
    if (GetKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000)
    {
        player->MoveTo(rectView, { 0, -10 });
    }
    if (GetKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        player->MoveTo(rectView, { 0, 10 });
    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        Ball* ball = player->Attack();
        if ( ball != NULL )
            objects.push_back(ball);
    }
    
    InvalidateRect(hwnd, NULL, false);
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
