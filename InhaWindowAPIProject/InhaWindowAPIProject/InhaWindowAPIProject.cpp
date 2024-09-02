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

   HWND hWnd = CreateWindowW(szWindowClass, _T("에고야")/*szTitle*/, WS_OVERLAPPEDWINDOW,
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

#include <fstream>

#define CIRCLE_RADIUS 50
#define MAX_STR_LENGTH 100
#define MAX_STR_COUNT 100
#define MAX_SHOW_COUNT 10

void OutFromFile(TCHAR filename[], HWND hwnd, TCHAR buffer[MAX_STR_COUNT][MAX_STR_LENGTH])
{
    FILE* fptr;
    HDC hdc;
    int line;
    line = 0;
    hdc = GetDC(hwnd);
#ifdef _UNICODE
    _tfopen_s(&fptr, filename, _T("r, ccs = UNICODE"));
#else
    _tfopen_s(&fptr, filename, _T("r"));
#endif
    while (_fgetts(buffer[line], MAX_STR_LENGTH, fptr) != NULL)
    {
        if (buffer[line][_tcslen(buffer[line]) - 1] == _T('\n'))
            buffer[line][_tcslen(buffer[line]) - 1] = NULL;
        TextOut(hdc, 0, line * 20, buffer[line], _tcslen(buffer[line]));
        line++;
    }
    fclose(fptr);
    ReleaseDC(hwnd, hdc);
}

void SaveFile(TCHAR filename[], TCHAR buffer[MAX_STR_COUNT][MAX_STR_LENGTH])
{
    FILE* fptr;
    int line = 0;

    _tfopen_s(&fptr, filename, _T("w, ccs = UNICODE"));

    while (buffer[line][0] != NULL)
    {
        _fputts(buffer[line++], fptr);
        _fputts(_T("\n"), fptr);
    }

    fclose(fptr);
}

void InitializeFile(OPENFILENAME& fn, HWND hWnd, TCHAR lpstrFile[])
{
    static TCHAR filter[] = _T("Every File(*.*) \0*.*\0Text File\0*.txt;*.doc\0");
    memset(&fn, 0, sizeof(OPENFILENAME));
    fn.lStructSize = sizeof(OPENFILENAME);
    fn.hwndOwner = hWnd;
    fn.lpstrFile = lpstrFile;
    fn.lpstrFilter = filter;
    fn.nMaxFile = 100;
    fn.lpstrInitialDir = _T("../Text");      // 열었을 때 위치 지정
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static RECT rectView;

    OPENFILENAME ofn, sfn;
    TCHAR scriptStr[MAX_STR_LENGTH], lpstrFile[MAX_STR_LENGTH] = _T("");
    static TCHAR buffer[MAX_STR_COUNT][MAX_STR_LENGTH];
    static TCHAR chatBuffer[MAX_STR_COUNT][MAX_STR_LENGTH];

    static int count, chatCount;
    static SIZE caretSize;
    int yPos = 700;


    switch (message)
    {
    case WM_CREATE:
        GetClientRect(hWnd, &rectView);
        count = 0;
        chatCount = 0;
        CreateCaret(hWnd, NULL, 5, 15);
        ShowCaret(hWnd);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case ID_FileOpen:
                InitializeFile(ofn, hWnd, lpstrFile);

                if (GetOpenFileName(&ofn) != 0)     // 파일 열기를 눌렀을 때
                {
                    OutFromFile(ofn.lpstrFile, hWnd, buffer);
                }
                break;
            case ID_FileSave:
                InitializeFile(sfn, hWnd, lpstrFile);

                if (GetSaveFileName(&sfn) != 0)
                {
                    _stprintf_s(scriptStr, _T("%s 파일로 저장하겠습니까?"), sfn.lpstrFile);
                    MessageBox(hWnd, scriptStr, _T("저장하기"), MB_OK);
                    SaveFile(sfn.lpstrFile, chatBuffer);
                }
                break;
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            case ID_DrawCircle:
                break;
            case ID_DrawRectangle:
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_KEYDOWN:
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_KEYUP:
        InvalidateRect(hWnd, NULL, true);
        break;
    case WM_CHAR:
    {
        if (chatCount < MAX_STR_COUNT)
        {
            if (wParam == VK_BACK)
            {
                if (count > 0)
                    count--;
            }
            else if (wParam == VK_RETURN)
            {
                count = 0;
                chatCount++;
            }
            else
            {
                if (count < MAX_STR_LENGTH - 1)
                    chatBuffer[chatCount][count++] = wParam;
            }
            chatBuffer[chatCount][count] = NULL;
        }
        InvalidateRgn(hWnd, NULL, true);
    }
        break;
    case WM_SIZE:
        GetClientRect(hWnd, &rectView);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);


        SetTextColor(hdc, RGB(0, 0, 0));

        for (int i = chatCount - MAX_SHOW_COUNT; i <= chatCount; i++)
        {
            if (i == chatCount)
                SetTextColor(hdc, RGB(0, 0, 255));
            TextOut(hdc, 0, yPos - 20 * (chatCount-i), chatBuffer[i], _tcslen(chatBuffer[i]));
        }

        GetTextExtentPoint(hdc, chatBuffer[chatCount], _tcslen(chatBuffer[chatCount]), &caretSize);
        SetCaretPos(caretSize.cx, yPos);

        EndPaint(hWnd, &ps);
    }
        break;
    case WM_TIMER:
        InvalidateRect(hWnd, NULL, true);
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
