#include <vector>
#include <algorithm>
using namespace std;
#include "framework.h"
#include "WindowCollisionProject.h"
#include "CObject.h"

/*
Q2. 클라이언트 영역에 마우스 클릭시 도형을 생성한다.
    도형은 사각형, 원, 별이 랜덤으로 생성되도록 한다.
    1. 생성된 도형은 임의의 방향으로 이동한다.
    2. 클라이언트 영역 외각에서 반사되도록 한다.
    3. 모드 설정
        3.1 1번 반사, 2번 합체, 3번 분열로 키를 설정
    4. 모드
        4.1 반사: 다른 오브젝트와 부딪히면 튕겨 나간다. ( + 이동 속도나 크기 속성 반영)
        4.2 합체: 상성 관계에 따라 다른 오브젝트를 만나면 합체해서 커지게 한다.
        4.3 분열: 상성 관계에 따라 다른 오브젝트와 만나면 분열해서 작아지게 한다.
            별 > 사각형 > 원 > 별
    5. 일정 크기 이상 또는 일정 크기 이하는 사라지도록 한다. 
    6. 각 오브젝트를 회전시킨다. 

    CObject
    {
        protected: 좌표, 이동 스피드, 이동 방향, 타입 (원, 별, 사각형)
        public:
            virtual void Update() = 0       // 좌표 갱신
            virtual void Draw() = 0;        // 그리기
            virtual BOOL Collision() = 0;   // 충돌
            etc...
    }

    class CCircle : CObject
    {
        private: 반지름...

        public:
            void Update() override;       // 좌표 갱신
            void Draw() override;         // 그리기
            BOOL Collision() override;    // 충돌
    }

    업캐스팅 사용하기
*/

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
    LoadStringW(hInstance, IDC_WINDOWCOLLISIONPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWCOLLISIONPROJECT));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWCOLLISIONPROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWCOLLISIONPROJECT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; 

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

#include <random>

#define MAX 200
#define TIMER_ID1 1



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static vector<CObject*> objects;
    static RECT rectView;
    static Mode mode = Mode::Basic;
    HBRUSH hBrush;
    HGDIOBJ oldBrush;
    POINT pts[6];
    float ct = 90;

    switch (message)
    {
    case WM_CREATE:
        srand(time(NULL));
        SetTimer(hWnd, TIMER_ID1, 15, NULL);
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
    case WM_KEYDOWN:
        switch (wParam)
        {
        case '1':
            mode = Mode::Basic;
            break;
        case '2':
            mode = Mode::Merge;
            break;
        case '3':
            mode = Mode::Decompose;
            break;
        }
        break;
    case WM_LBUTTONDOWN:
        {
        double x = LOWORD(lParam);
        double y = HIWORD(lParam);

        int randomSize  = rand() % 5 + 1;   // 1~5//
        int randomType  = rand() % 3;
        int randomSpeed = rand() % 3 + 5;
        int randomDir   = rand() % 8;
        int randomDirX  = rand() % 360;
        
        switch (randomType)
        {
        case ObjectType::Circle:
            objects.emplace_back(new CCircle( { x, y }, randomSpeed, randomDirX, ObjectType::Circle, randomSize));
            break;
        case ObjectType::Rect:
            objects.emplace_back(new CRect({ x, y }, randomSpeed, randomDirX, ObjectType::Rect, randomSize));
            break;
        case ObjectType::Star:
            objects.emplace_back(new CStar({ x, y }, randomSpeed, randomDirX, ObjectType::Star, randomSize));
            break;
        }

        InvalidateRect(hWnd, NULL, true);
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            hBrush = CreateSolidBrush(RGB(230, 150, 150));
            oldBrush = SelectObject(hdc, hBrush);

            BOOL flag[100] = { false };

            for (int i = 0; i < objects.size(); i++)
            {

                for (int j = 0; j < objects.size(); j++)
                {
                    if (i != j && flag[j] == false)
                    {
                        switch (objects[i]->Collision(*objects[j], mode))
                        {
                        case 0:
                            flag[i] = true;
                            break;
                        case 1:
                            CObject * ptr = objects[j];
                            objects.erase(remove(objects.begin(), objects.end(), ptr), objects.end());
                            EndPaint(hWnd, &ps);
                            break;
                        }
                    }
                }
                SelectObject(hdc, oldBrush);
                if (objects[i]->isCollided)
                    oldBrush = SelectObject(hdc, hBrush);
                objects[i]->Draw(hdc);
            }

            DeleteObject(oldBrush);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_TIMER:
        switch (wParam)
        {
        case TIMER_ID1:
            for (int i = 0; i < objects.size(); i++)
            {
                objects[i]->Update(rectView);
            }
            break;
        }
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_DESTROY:
        KillTimer(hWnd, TIMER_ID1);
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