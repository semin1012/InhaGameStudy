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
#include "Item.h"
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

BOOL                bGameOver = FALSE;

VOID CALLBACK UpdateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);
VOID CALLBACK KeyStateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);

void InitObjects();
void CreateDoubbleBuffering(HWND hWnd);
void EndDoubleBuffering(HWND hWnd);
void CheckGameOver(vector<GameObject*>);
void DrawTextInGame(HDC hdc);

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
            DrawTextInGame(hdc);
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
    vector<GameObject*> balls;

    vector<GameObject*> removeObj;

    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->Update(rectView);

        if (objects[i]->GetType() == EObjectType::Ball)
        {
            balls.push_back(objects[i]);
            if (objects[i]->GetIsOver())
            {
                removeObj.push_back(objects[i]);
            }
        }
    }

    InvalidateRect(hwnd, NULL, false);

    CheckGameOver(balls);

    if (balls.size() == 0) return;

    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i]->GetType() == EObjectType::Obstacle)
        {
            for (int j = 0; j < balls.size(); j++) 
            {
                // TODO: 0.25 확률 바꾸기
                int random = 0;

                switch (objects[i]->Collision(*balls[j]))
                {
                // -1이면 삭제
                case -1:
                    player->AddScore(objects[i]->GetScore());
                    removeObj.push_back(objects[i]);

                    if (random == 0)
                    {
                        POINT objectPos = objects[i]->GetPos();
                        Item* item = new Item({ objectPos.x, objectPos.y + HEIGHT_HALF_SIZE * 2 }, 10, EObjectType::Item);
                        objects.push_back(item);
                    }

                    break;
                case 1:
                    player->AddScore(objects[i]->GetScore());
                    break;
                }
            }
        }

        if (objects[i]->GetType() == EObjectType::Player)
        {
            for (int j = 0; j < balls.size(); j++)
                objects[i]->Collision(*balls[j]);
        }
    }

    for (int i = 0; i < removeObj.size(); i++)
    {
        objects.erase(remove(objects.begin(), objects.end(), removeObj[i]), objects.end());
    }
}

VOID CALLBACK KeyStateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
    if (bGameOver == TRUE)
        return;

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
            Obstacle* obstacle = new Obstacle({ 0 + 80 * i + 40, 200 - j * HEIGHT_HALF_SIZE * 2 }, 40, j + 1);
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

void CheckGameOver(vector<GameObject*> balls)
{
    if (player->GetBallCount() <= 0 && balls.size() == 0)
    {
        player->SetPos({ 1000, 1000 });
    }
}

void DrawTextInGame(HDC hdc)
{
    wchar_t ballCountText[32];
    wchar_t scoreText[32];

    swprintf_s(ballCountText, L"남은 Ball 개수: %d", player->GetBallCount());
    swprintf_s(scoreText, L"점수: %d", player->GetScore());

    TextOut(hdc, 50, 50, ballCountText, _tcsclen(ballCountText));
    TextOut(hdc, 50, 70, scoreText, _tcsclen(scoreText));
}
