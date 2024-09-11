#include "framework.h"
#include "WinAPIHopscotch.h"
#include "commdlg.h"
#include <stdio.h>

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

// 사용자 정의
void Gdi_Init();
void Gdi_Draw(HDC hdc);
void Gdi_End();

ULONG_PTR g_GdipPlusToken;

#pragma region WinMain
#define MAX_LOADSTRING 100

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
    LoadStringW(hInstance, IDC_WINAPIHOPSCOTCH, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
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
    }

    Gdi_End();

    return (int)msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPIHOPSCOTCH));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPIHOPSCOTCH);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance;

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, WINDOW_WIDTH_SIZE, WINDOW_HEIGHT_SIZE, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}
#pragma endregion

#include "Player.h"
#include "GameObject.h"
#include "Map.h"
#include <vector>
#include <queue>
using namespace std;
#define TIMER_UPDATE_ID 1
#define TIMER_KEY_STATE_ID 2
#define TIMER_UPDATE_BOARD_ID 3

const int UpdateDeltaTime = 33;
const int UpdateBoardTime = 1000;

vector<GameObject*> objects;
Player* player;
Map* map;
vector<POINT> points;
vector<POINT> area;

short board[BOARD_SIZE_Y][BOARD_SIZE_X];
short visit[BOARD_SIZE_Y][BOARD_SIZE_X];

RECT                rectView;

HDC                 hdc, MemDC, tmpDC;
HBITMAP             BackBit, oldBackBit;
RECT                bufferRT;
PAINTSTRUCT         ps;

BOOL                bGameOver = FALSE;

void CreateDoubbleBuffering(HWND hWnd);
void EndDoubleBuffering(HWND hWnd);
void Init(HWND hWnd);

VOID CALLBACK UpdateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);
VOID CALLBACK UpdateBoardProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);
VOID CALLBACK KeyStateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);

void DFS()
{
    static const short dirX[4] = { 0, 0, 1, -1 };
    static const short dirY[4] = { 1, -1, 0, 0 };

    queue<pair<int, int>> q;
    int count = 0;

    for (int i = 0; i < BOARD_SIZE_Y / 10; i++)
    {
        for (int j = 0; j < BOARD_SIZE_X / 10; j++)
        {
            if (board[i][j] == 1 && visit[i][j] == 0)
            {
                // 1이면 들른 곳
                visit[i][j] = ++count;
                q.push({ j, i });   // x, y 순서

                while (!q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int z = 0; z < 4; z++)
                    {
                        int dx = cur.first + dirX[z];
                        int dy = cur.second + dirY[z];

                        if (dy < 0 || dx < 0 || dy >= BOARD_SIZE_Y || dx >= BOARD_SIZE_X ) continue;
                        if (board[dy][dx] == 0 || visit[dy][dx] != 0 ) continue;

                        visit[dy][dx] = count;
                        q.push({ dx, dy });
                    }
                }
            }
        }
    }
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        Init(hWnd);
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
    case WM_KEYDOWN:
        if (player->GetPressed())
        {
            POINT temp = { player->GetCenterX(), player->GetCenterY() };
            if (points.back().x != temp.x || points.back().y != temp.y)
                points.push_back({ player->GetCenterX(), player->GetCenterY() });
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            player->SetPressed(true);
        }
        break;
    case WM_KEYUP:
        if (wParam == VK_SPACE)
        {
            player->SetPressed(false);
            points.push_back({ player->GetCenterX(), player->GetCenterY() });
        }
        break;
    case WM_PAINT:
        {
            CreateDoubbleBuffering(hWnd);

            Gdi_Draw(hdc);

            EndDoubleBuffering(hWnd);
        }
        break;
    case WM_SIZE:
        GetClientRect(hWnd, &rectView);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        KillTimer(hWnd, TIMER_UPDATE_ID);
        KillTimer(hWnd, TIMER_KEY_STATE_ID);
        KillTimer(hWnd, TIMER_UPDATE_BOARD_ID);
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

void Init(HWND hWnd)
{   
    GetClientRect(hWnd, &rectView);

    map = new Map();
    map->SetRectView(rectView);

    player = new Player(50, 50, 10);
    player->SetRectView(rectView);
    
    objects.push_back(map);
    objects.push_back(player);

    points.push_back({ player->GetCenterX(), player->GetCenterY() });

    Gdi_Init();

    for (auto obj : objects)
        obj->CreateBitmap();

    SetTimer(hWnd, TIMER_UPDATE_ID, UpdateDeltaTime, (TIMERPROC)UpdateProc);
    SetTimer(hWnd, TIMER_KEY_STATE_ID, UpdateDeltaTime, (TIMERPROC)KeyStateProc);
    SetTimer(hWnd, TIMER_UPDATE_BOARD_ID, UpdateBoardTime, (TIMERPROC)UpdateBoardProc);
}

#pragma region Gdi

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

    map->SetPoints(points, area);
    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->Draw(hdc);
    }
}

void Gdi_End()
{
    GdiplusShutdown(g_GdipPlusToken);
}

#pragma endregion

#pragma region Double Buffering
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
#pragma endregion

VOID UpdateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
    for (auto obj : objects)
        obj->Update();

    InvalidateRect(hwnd, NULL, false);
}

VOID UpdateBoardProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
    DFS();
    if (player->CollisionWindow())
    {
        for (auto v : points)
        {
            area.push_back(v);
        }
        points.clear();
    }
}

VOID KeyStateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
    DWORD newTime = GetTickCount();
    static DWORD oldTime = newTime;

    if (newTime - oldTime < 50)
        return;

    oldTime = newTime;

    

    if (player->CollisionWindow())
    {

    }
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        player->SetPressed(true);
    }
    if (GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        if (player->MoveTo(rectView, -1, 0))
        {
            if (!player->GetPressed())
                board[player->GetY() / 10][player->GetX() / 10] = 1;
        }
    }
    else if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        if (player->MoveTo(rectView, 0, -1))
        {
            if (player->GetPressed())
                board[player->GetY() / 10][player->GetX() / 10] = 1;
        }
    }
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        if (player->MoveTo(rectView, 1, 0))
        {
            if (player->GetPressed())
                board[player->GetY() / 10][player->GetX() / 10] = 1;
        }
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        if (player->MoveTo(rectView, 0, 1))
        {
            if (player->GetPressed())
                board[player->GetY() / 10][player->GetX() / 10] = 1;
        }
    }
}
