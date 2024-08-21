// InhaWindowAPIProject.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "InhaWindowAPIProject.h"

/* 
Q1. 채팅창에 문자열을 입력하고 엔터키를 누르면
    문자열이 한칸 올라가서 표시되고 그 다음에 입력하는
    데이터들이 보여지도록 하는 코드를 작성하라.
    채팅 최대 목록은 10개로 제한한다.

    ex> abc (enter)

        abc
        > asdf (enter)

        abc
        asdf
        > ... (enter)
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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static TCHAR str[1000];
    static int count, yPos;
    RECT rc = { 0, 0, 800, 800};
    static SIZE caretSize;

    switch (message)
    {
    case WM_CREATE:
        count = 0;
        yPos = 0;
        CreateCaret(hWnd, NULL, 5, 15);
        ShowCaret(hWnd);
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
    case WM_KEYDOWN:

        break;
    case WM_CHAR:
    // 아래처럼 쓰면 이미 쓰고 있던 hdc를 얻어와서 거기에 출력을 하는 코드다.
    // WM_PAINT에서처럼 새로 페인트를 하는 느낌과는 다름
    {
        if (wParam == VK_BACK)
        {
            if (count > 0)
                count--;
        }
        else if (wParam == VK_RETURN)
        {
            count = 0;
            yPos = yPos + 20;
        }
        else
        {
            if (count < 1000-1)
                str[count++] = wParam;
        }
        str[count] = NULL;

        InvalidateRgn(hWnd, NULL, true);
        // InvalidateRect(hWnd, NULL, true);
        // 위와 아래는 같은 것임. 두번째 인자가 NULL이면 전체를 다시 그리라고 하는 거고
        // rect 크기를 지정하면 거기만 다시 그리라고 요청함. 세번째 인자는 지우고 다시 그리라는 뜻
    }
        break;
    case WM_KEYUP:
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

        TextOut(hdc, 10, 10, _T("Hello World"), _tcslen(_T("Hello World")));

        //SetTextColor(hdc, RGB(150, 110, 120));

        //RECT rect;
        //rect.left = 100, rect.top = 100, rect.right = 250, rect.bottom = 200;
        //DrawText(hdc, _T("Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 "),
        //    _tcslen(_T("Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 Hello World2 ")),
        //    &rect, DT_WORDBREAK | DT_CENTER | DT_VCENTER);

        TextOut(hdc, 100, yPos, str, _tcslen(str));

        DrawText(hdc, str, _tcslen(str), &rc, DT_TOP | DT_LEFT | DT_WORDBREAK);
        GetTextExtentPoint(hdc, str, _tcslen(str), &caretSize);
        SetCaretPos(caretSize.cx, 0);


            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        HideCaret(hWnd);
        DestroyCaret();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
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
