// InhaWindowAPIProject.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "InhaWindowAPIProject.h"
#include "commdlg.h"

/* 
Q1. 파일 열기, 파일 저장 메뉴를 추가하고 각 기능을 구현하라.
    1. source.txt  읽어서 화면에 출력하라. 
    2. 채팅창 구현한 내용에서 채팅으로 입력된 내용을 저장하라.
        채팅창에 출력 내용은 10줄만
        채팅 내용은 100개까지 저장하고 있다가 파일에 내용을 저장할 수 있도록 한다.
*/


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

// int WINAPI WinMain() 이렇게 쓰기도 한다.
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
    LoadStringW(hInstance, IDC_INHAWINDOWAPIPROJECT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_INHAWINDOWAPIPROJECT));

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

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_INHAWINDOWAPIPROJECT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_CROSS);
    wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255)); //RGB(230, 210, 210));// GetStockObject(DKGRAY_BRUSH);//(COLOR_WINDOW+3);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_INHAWINDOWAPIPROJECT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(NULL, IDI_QUESTION);

    return RegisterClassExW(&wcex);
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

   HWND hWnd = CreateWindowW(szWindowClass, _T("아이고배고파")/*szTitle*/, WS_OVERLAPPEDWINDOW,
      200, 300, 800, 800, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, SW_SHOW);   // SW_MAXIMIZE로 하면 최대창으로 시작
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

#include <math.h>

struct POS
{
    int x, y;
};

#define TIMER_ID1 1
#define TIMER_ID2 2
#define CIRCLE_RADIUS 50

void DrawCircle(HDC hdc, POINT center, int radius)
{
    Ellipse(hdc, center.x - radius, center.y - radius, center.x + radius, center.y + radius);
}

BOOL InCircle(int x1, int y1, int x2, int y2, int radius)
{
    if (sqrt(((float)x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) <= radius)
        return TRUE;
    return FALSE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static POS pos = { CIRCLE_RADIUS, CIRCLE_RADIUS };
    static RECT rectView;
    static bool flag;
    static bool mouseFlag;
    static bool geometricObj = 0;

    OPENFILENAME ofn;
    TCHAR str[100], lpstrFile[100] = _T("");
    TCHAR filter[] = _T("Every File(*.*) \0*.*\0Text File\0*.text;*.doc\0");

    switch (message)
    {
    case WM_CREATE:
        GetClientRect(hWnd, &rectView);
        // SetTimer(hWnd, TIMER_ID1, 70, NULL);
        // SetTimer(hWnd, TIMER_ID2, 100, NULL);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case ID_FileOpen:
                memset(&ofn, 0, sizeof(OPENFILENAME));
                ofn.lStructSize = sizeof(OPENFILENAME);
                ofn.hwndOwner = hWnd;
                ofn.lpstrFilter = filter;
                ofn.lpstrFile = lpstrFile;
                ofn.nMaxFile = 100;
                ofn.lpstrInitialDir = _T("..");      // 열었을 때 위치 지정
                if (GetOpenFileName(&ofn) != 0)     // 파일 열기를 눌렀을 때
                {
                    _stprintf_s(str, _T("%s 파일을 열겠습니까?"), ofn.lpstrFile);
                    MessageBox(hWnd, str, _T("열기 선택"), MB_OK);
                }
                break;
            case ID_FileSave:
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case ID_DrawCircle:
            {
                int ans = MessageBox(hWnd, _T("원 그리기 선택"), _T("도형 선택"), MB_OKCANCEL);
                if (ans == IDOK)
                    geometricObj = 0;
            }
                break;
            case ID_DrawRectangle:
            {
                int ans = MessageBox(hWnd, _T("사각형 그리기 선택"), _T("도형 선택"), MB_OKCANCEL);
                if (ans == IDOK)
                    geometricObj = 1;
            }
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_KEYDOWN:
        if (wParam == VK_RIGHT)
        {
            pos.x += 40;
            if (pos.x + 20 > rectView.right)
                pos.x -= 40;
        }
        if (wParam == VK_LEFT)
        {
            pos.x -= 40;
            if (pos.x - 20 < rectView.left)
                pos.x += 40;
        }
        if (wParam == VK_DOWN)
        {
            pos.y += 40;
            if (pos.y + 20 > rectView.bottom)
                pos.y -= 40;
        }
        if (wParam == VK_UP)
        {
            pos.y -= 40;
            if (pos.y - 20 < rectView.top)
                pos.y += 40;
        }
        flag = true;
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_KEYUP:
        flag = false;
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_CHAR:
        break;
    case WM_LBUTTONDOWN:
    {
        int x, y;

        x = LOWORD(lParam); //x
        y = HIWORD(lParam); //y
        if (InCircle(x, y, pos.x, pos.y, CIRCLE_RADIUS))
            mouseFlag = TRUE;
        else mouseFlag = FALSE;

        pos.x = x;
        pos.y = y;

        InvalidateRect(hWnd, NULL, true);
    }
        break;
    case WM_LBUTTONUP:
        mouseFlag = FALSE;
        break;
    case WM_RBUTTONDOWN:
    {
        int x, y;
        x = LOWORD(lParam); //x
        y = HIWORD(lParam); //y
        if (InCircle(x, y, pos.x, pos.y, CIRCLE_RADIUS))
            flag = TRUE;
        else flag = FALSE;
        InvalidateRect(hWnd, NULL, true);
    }
        break;
    case WM_RBUTTONUP:
        break;
    case WM_MOUSEMOVE:  // 이거 하면 느리다
        int x, y;
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        if (mouseFlag) 
        {
            pos.x = x;
            pos.y = y;
        }
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_SIZE:
        GetClientRect(hWnd, &rectView);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        if (flag)
            SelectObject(hdc, GetStockObject(LTGRAY_BRUSH));

        if ( geometricObj == 0 ) 
            Ellipse(hdc, pos.x - CIRCLE_RADIUS, pos.y - CIRCLE_RADIUS, pos.x + CIRCLE_RADIUS, pos.y + CIRCLE_RADIUS);

        else 
            Rectangle(hdc, pos.x - CIRCLE_RADIUS, pos.y - CIRCLE_RADIUS, pos.x + CIRCLE_RADIUS, pos.y + CIRCLE_RADIUS);

        EndPaint(hWnd, &ps);
    }
        break;
    case WM_TIMER:
        switch (wParam)
        {
        case TIMER_ID1:
            pos.x += 40;
            if (pos.x + 20 > rectView.bottom)
                pos.x = rectView.bottom - CIRCLE_RADIUS;
            break;
        case TIMER_ID2:
            pos.x -= 40;
            if (pos.x > rectView.right + CIRCLE_RADIUS)
                pos.x = rectView.right - CIRCLE_RADIUS;
            break;
        }
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_DESTROY:
        KillTimer(hWnd, TIMER_ID1);
        KillTimer(hWnd, TIMER_ID2);
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
