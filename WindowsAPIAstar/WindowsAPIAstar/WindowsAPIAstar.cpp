// WindowsAPIAstar.cpp : 애플리케이션에 대한 진입점을 정의합니다.

#include <string>
#include <queue>
#include "framework.h"
#include "WindowsAPIAstar.h"
#include "Node.h" 
using namespace std;
#define MAX_LOADSTRING 100
#define MAX_WIDTH_COUNT 10
#define MAX_HEIGHT_COUNT 10

#pragma region WinMain

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

    // TODO: 여기에 코드를 입력합니다.

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSAPIASTAR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSAPIASTAR));

    MSG msg;

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


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSAPIASTAR));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSAPIASTAR);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance;

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, 800, 800, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}
#pragma endregion


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


void Init();
void Astar();
void InitializeAllNode();
void Draw(HDC& hdc);

// -1: 장애물, 1: 시작지점, 2: 끝지점
vector<vector<int>> board(MAX_HEIGHT_COUNT, vector<int>(MAX_WIDTH_COUNT));
vector<vector<Node*>> nodes(MAX_HEIGHT_COUNT, vector<Node*>());
vector<Node*> points;
vector<Node*> paths;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static bool isCheck = true;
    static LPPOINT mousePos;
    static bool bStartPoint = true;
    static bool bObstacleKeyDown = false;
   

    switch (message)
    {
    case WM_CREATE:
        Init();
        SetTimer(hWnd, 0, 150, NULL);
        mousePos = new POINT;
        mousePos->x = 0;
        mousePos->y = 0;
        break;
    case WM_LBUTTONDOWN:
        GetCursorPos(mousePos);
        ScreenToClient(hWnd, mousePos);
        
        for (int i = 0; i < MAX_HEIGHT_COUNT; i++)
        {
            for (int j = 0; j < MAX_WIDTH_COUNT; j++)
            {
                Node* node = nodes[i][j];

                if (node->IsOnClick(mousePos->x, mousePos->y))
                {
                    if (node->GetNodeType() != ENodeType::Basic)
                        break;

                    // 장애물
                    if (bObstacleKeyDown)
                    {
                        if (node->GetNodeType() != ENodeType::Obstacle)
                        {
                            node->SetNodeType(ENodeType::Obstacle);
                            board[node->GetIndexY()][node->GetIndexX()] = -1;
                        }
                        break;
                    }

                    if (points.size() >= 2)
                    {
                        InitializeAllNode();
                        while (!points.empty())
                        {
                            Node* temp = points.back();
                            board[temp->GetIndexY()][temp->GetIndexX()] = 0;
                            points.pop_back();
                        }
                    }

                    // 시작 / 끝 지점
                    if (bStartPoint)
                    {
                        node->SetNodeType(ENodeType::StartPoint);
                        board[node->GetIndexY()][node->GetIndexX()] = 1;
                    }
                    else
                    {
                        node->SetNodeType(ENodeType::EndPoint);
                        board[node->GetIndexY()][node->GetIndexX()] = 2;
                    }

                    points.push_back(node);

                    if (points.size() == 2)
                        Astar();

                    isCheck = !isCheck;
                    bStartPoint = !bStartPoint;
                    break;
                }
            }
        }

        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_TIMER:
        {
            if (paths.size() <= 0)
                break;

            Node* path = paths.back();
            path->SetNodeType(ENodeType::Road);
            paths.pop_back();
        }
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_KEYDOWN:
        if (wParam == VK_SHIFT)
            bObstacleKeyDown = true;
        break;
    case WM_KEYUP:
        if (wParam == VK_SHIFT)
            bObstacleKeyDown = false;
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            SetBkMode(hdc, TRANSPARENT);

            Draw(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}



void Init()
{
    for (int i = 0; i < MAX_WIDTH_COUNT; i++)
    {
        for (int j = 0; j < MAX_HEIGHT_COUNT; j++)
        {
            Node* node = new Node(i * 50, j * 50, 50, 50, i, j);
            nodes[i].push_back(node);
        }
    }
}

struct cmp {
    bool operator()(Node* a, Node* b) {
        if (a->GetFCost() > b->GetFCost()) return true;
        else if (a->GetFCost() == b->GetFCost())
        {
            if (a->GetGCost() > b->GetGCost()) return true;
            else return false;
        }
        else return false;
    }
};

void Astar()
{
    priority_queue<Node*, vector<Node*>, cmp> open;

    bool visit[MAX_HEIGHT_COUNT][MAX_WIDTH_COUNT] = { 0, };
    vector<Node*> visitList;
    Node* startNode = points[0];
    Node* endNode = points[1];

    int cx[8] = { 0,1,0,-1,1,1,-1,-1 };
    int cy[8] = { -1,0,1,0,1,-1,1,-1 };

    startNode->SetGCost(0);
    startNode->SetHCost((abs(endNode->GetIndexX() - startNode->GetIndexX()) + abs(endNode->GetIndexY() - startNode->GetIndexY())) * 10);
    startNode->SetParent(make_pair(-1, -1));
    open.push(startNode);
    visit[startNode->GetIndexY()][startNode->GetIndexX()] = true;

    while (open.size()) {
        int x = open.top()->GetIndexX();
        int y = open.top()->GetIndexY();
        int G = open.top()->GetGCost();
        visitList.push_back(open.top());

        open.pop(); 
        if (x == endNode->GetIndexX() && y == endNode->GetIndexY()) break;

        Node *add;
        for (int i = 0; i < 8; i++) {
            int nextX = x + cx[i];
            int nextY = y + cy[i];
            if (nextX >= 0 && nextX < board.size() && nextY >= 0 && nextY < board.size()) {
                if (board[nextY][nextX] != -1 && visit[nextY][nextX] == false) {
                    add = nodes[nextX][nextY];
                    add->SetGCost(i < 4 ? G + 10 : G + 14);
                    add->SetHCost((abs(endNode->GetIndexX() - add->GetIndexX()) + abs(endNode->GetIndexY() - add->GetIndexY())) * 10);
                    add->SetParent(make_pair(y, x));
                    visit[nextY][nextX] = true;
                    open.push(add);
                }
            }
        }
    }

    int px = visitList.back()->GetIndexX();
    int py = visitList.back()->GetIndexY();
    while (visitList.size()) 
    {
        if (px == visitList.back()->GetIndexX() && py == visitList.back()->GetIndexY())
        {
            if (nodes[px][py]->GetNodeType() != ENodeType::StartPoint && nodes[px][py]->GetNodeType() != ENodeType::EndPoint)
            {
                //nodes[px][py]->SetNodeType(NodeType::Road);
                paths.push_back(visitList.back());
            }

            px = visitList.back()->GetParent().second;
            py = visitList.back()->GetParent().first;
        }
        visitList.pop_back();
    }

    return;
}

void InitializeAllNode()
{
    for (int i = 0; i < MAX_HEIGHT_COUNT; i++)
    {
        for (int j = 0; j < MAX_WIDTH_COUNT; j++)
        {
            nodes[j][i]->Initialize();
            board[i][j] = 0;
        }
    }
}

void Draw(HDC& hdc)
{
    for (int i = 0; i < MAX_HEIGHT_COUNT; i++)
    {
        for (int j = 0; j < MAX_WIDTH_COUNT; j++)
        {
            nodes[i][j]->Draw(hdc);
        }
    }
}
