// InhaWindowAPIProject.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "InhaWindowAPIProject.h"
#include "commdlg.h"
#pragma comment(lib, "Msimg32.lib")

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

void Update();

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

    // 기본 메시지 루프입니다: 무조건 메시지 넘김
    /*
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    */

    // 메시지가 있으면 넘어가고 아니면 Update
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
            // : Update and drawing
            // : to do something
            Update();
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

// >> : image

// : background image
HBITMAP hBackImage;
BITMAP bitBack;

// : sigong image
HBITMAP hTransParentImage;
BITMAP bitTransParent;
RECT rectView;

// : animation image
HBITMAP hAniImage;
BITMAP bitAni;
const int SPRITE_SIZE_X = 57; // 크기 계산 후 넣은 상태
const int SPRITE_SIZE_Y = 52;
const int SPRITE_COUNT = 16; // 달리기 스프라이트 개수
const int SPRITE_DIRECTION = 2; // 달리기 방향

int Run_Frame_Max = 0;
int Run_Frame_Min = 0;
int curFrame = Run_Frame_Min;
POINT ptAni = { 400, 400 };


void UpdateFrame(HWND hwnd);

// TIMER
VOID CALLBACK AniProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);
VOID CALLBACK KeyStateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime);

// << : image

// >> : double buffering
HBITMAP hDoubleBufferBitmap;
HBITMAP hDoubleBufferImage;
HBITMAP hOldDoubleBufferBitmap;
// << : double buffering

TCHAR sKeyState[128];


void CreateBitmap();
void DrawBitmap(HWND hWnd, HDC hdc);
void DrawBitmapDoubleBuffering(HWND hWnd, HDC hdc);
void DeleteBitmap();


#define TIMER_ID1 1
#define TIMER_ID2 2
#define TIMER_ANI 3
#define TIMER_KEYSTATE 4

#define CIRCLE_RADIUS 50

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    POINT pos;
    static bool flag;
    static bool mouseFlag;
    static bool geometricObj = 0;

    OPENFILENAME ofn;
    TCHAR str[100], lpstrFile[100] = _T("");
    TCHAR filter[] = _T("Every File(*.*) \0*.*\0Text File\0*.text;*.doc\0");

    switch (message)
    {
    case WM_CREATE:
        pos.x = CIRCLE_RADIUS; pos.y = CIRCLE_RADIUS;
        GetClientRect(hWnd, &rectView);
        CreateBitmap();
        SetTimer(hWnd, TIMER_ANI, 33, AniProc);
        SetTimer(hWnd, TIMER_KEYSTATE, 100, KeyStateProc);
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
        //if (wParam == VK_RIGHT)
        //{
        //    pos.x += 40;
        //    if (pos.x + 20 > rectView.right)
        //        pos.x -= 40;
        //}
        //if (wParam == VK_LEFT)
        //{
        //    pos.x -= 40;
        //    if (pos.x - 20 < rectView.left)
        //        pos.x += 40;
        //}
        //if (wParam == VK_DOWN)
        //{
        //    pos.y += 40;
        //    if (pos.y + 20 > rectView.bottom)
        //        pos.y -= 40;
        //}
        //if (wParam == VK_UP)
        //{
        //    pos.y -= 40;
        //    if (pos.y - 20 < rectView.top)
        //        pos.y += 40;
        //}
        flag = true;
        //InvalidateRect(hWnd, NULL, false);
        break;
    case WM_KEYUP:
        flag = false;
        //InvalidateRect(hWnd, NULL, false);
        break;
    case WM_CHAR:
        break;
    case WM_LBUTTONDOWN:
    {
        int x, y;

        x = LOWORD(lParam); //x
        y = HIWORD(lParam); //y
        //if (InCircle(x, y, pos.x, pos.y, CIRCLE_RADIUS))
        //    mouseFlag = TRUE;
        //else mouseFlag = FALSE;

        pos.x = x;
        pos.y = y;

        //InvalidateRect(hWnd, NULL, false);
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
        //if (InCircle(x, y, pos.x, pos.y, CIRCLE_RADIUS))
        //    flag = TRUE;
        //else flag = FALSE;
        //InvalidateRect(hWnd, NULL, false);
    }
    break;
    case WM_RBUTTONUP:
        break;
    case WM_MOUSEMOVE:  // 이거 하면 느리다
        int x, y;
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        //if (mouseFlag)
        //{
        //    pos.x = x;
        //    pos.y = y;
        //}
        //InvalidateRect(hWnd, NULL, false);
        break;
    case WM_SIZE:
        GetClientRect(hWnd, &rectView);
        break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        // DrawBitmap(hWnd, hdc);
        DrawBitmapDoubleBuffering(hWnd, hdc);

        TextOut(hdc, 10, 10, sKeyState, _tcslen(sKeyState));

        EndPaint(hWnd, &ps);
    }
    break;
  /*  case WM_TIMER:
        switch (wParam)
        {
        case TIMER_ANI:
            break;
        case TIMER_KEYSTATE:
            break;
        }

    //    InvalidateRe*///ct(hWnd, NULL, FALSE);
        break;
    case WM_DESTROY:
        DeleteBitmap();
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


// 비트맵
void CreateBitmap()
{
    // >> background image
    hBackImage = (HBITMAP)LoadImage(NULL, TEXT("../Data/arsene.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    if (hBackImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("배경 이미지 파일을 열 수 없습니다."), _T("에러"), MB_OK);
    }
    else
    {
        GetObject(hBackImage, sizeof(BITMAP), &bitBack);
    }
    // <<

    // >> : sigong image
    hTransParentImage = (HBITMAP)LoadImage(NULL, TEXT("../Data/images/sigong.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    if (hTransParentImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("시공 이미지 파일을 열 수 없습니다."), _T("에러"), MB_OK);
    }
    else
    {
        GetObject(hTransParentImage, sizeof(BITMAP), &bitTransParent);
    }
    // <<

    // >> : animation image
    hAniImage = (HBITMAP)LoadImage(NULL, TEXT("../Data/images/zero_run.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    if (hAniImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("애니메이션 이미지 파일을 열 수 없습니다."), _T("에러"), MB_OK);
    }
    else
    {
        GetObject(hAniImage, sizeof(BITMAP), &bitAni);
    }
    Run_Frame_Max = bitAni.bmWidth / SPRITE_SIZE_X - 1;
    Run_Frame_Min = 2; // 달리기 프레임 최소 프레임(시작?)
    curFrame = Run_Frame_Min;
    // <<
}

void DrawBitmap(HWND hWnd, HDC hdc)
{
    HDC hMemDC;
    HBITMAP hOldBitmap;
    int bx, by;

    // >> : 배경
    {
        hMemDC = CreateCompatibleDC(hdc); // hdc와 호환되는 메모리 DC 생성
        hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBackImage); // hMemDC에 hBackImage를 선택 -> 이미지가 올라와 있는 상태
        bx = bitBack.bmWidth;
        by = bitBack.bmHeight;

        BitBlt(hdc, 0, 0, bx, by, hMemDC, 0, 0, SRCCOPY); // hMemDC의 이미지를 hdc로 복사
        //BitBlt(hdc, 100, 100, bx - 100, by - 100, hMemDC, 100, 100, SRCCOPY); // hMemDC의 이미지를 hdc로 복사

        StretchBlt(hdc, bx, 0, bx / 4, by / 4, hMemDC, 0, 0, bx, by, SRCCOPY); // hMemDC의 이미지를 hdc로 복사

        SelectObject(hMemDC, hOldBitmap); // hMemDC에 선택된 이미지를 해제
        DeleteDC(hMemDC); // 메모리 DC 삭제
    }
    // <<
    // >> : sigong image
    {
        hMemDC = CreateCompatibleDC(hdc); // hdc와 호환되는 메모리 DC 생성
        hOldBitmap = (HBITMAP)SelectObject(hMemDC, hTransParentImage); // hMemDC에 hTransParentImage를 선택 -> 이미지가 올라와 있는 상태
        bx = bitTransParent.bmWidth;
        by = bitTransParent.bmHeight;

        TransparentBlt(hdc, 130, 30, bx, by, hMemDC, 0, 0, bx, by, RGB(255, 0, 255)); // hMemDC의 이미지를 hdc로 복사 , 해당 색을 제외하고 전부 전송됨

        SelectObject(hMemDC, hOldBitmap); // hMemDC에 선택된 이미지를 해제
        DeleteDC(hMemDC); // 메모리 DC 삭제

    }
    // >> : sigong image
    // >> : animation image
    {
        hMemDC = CreateCompatibleDC(hdc); // hdc와 호환되는 메모리 DC 생성
        hOldBitmap = (HBITMAP)SelectObject(hMemDC, hAniImage); // hMemDC에 hAniImage를 선택 -> 이미지가 올라와 있는 상태
        /*bx = bitAni.bmWidth / SPRITE_COUNT;
        by = bitAni.bmHeight / SPRITE_DIRECTION;*/
        bx = SPRITE_SIZE_X;
        by = SPRITE_SIZE_Y;

        int xStart = curFrame * bx;
        int yStart = 0;
        // hMemDC의 이미지를 hdc로 복사 , 해당 색을 제외하고 전부 전송됨
        TransparentBlt(hdc, ptAni.x, ptAni.y, bx, by, hMemDC, xStart, yStart, bx, by, RGB(255, 0, 255));


        SelectObject(hMemDC, hOldBitmap); // hMemDC에 선택된 이미지를 해제
        DeleteDC(hMemDC); // 메모리 DC 삭제
    }
    // << : animation image
}

void DeleteBitmap()
{
    DeleteObject(hBackImage);
    DeleteObject(hTransParentImage);
    DeleteObject(hAniImage);
    DeleteObject(hDoubleBufferImage);
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
        ptAni.x -= 10;
    }
    else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        ptAni.x += 10;
    }
    else if (GetAsyncKeyState(VK_UP) & 0x8000)
    {
        ptAni.y -= 10;
    }
    else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        ptAni.y += 10;
    }
}
void UpdateFrame(HWND hwnd)
{
    curFrame++;
    if (curFrame > Run_Frame_Max)
        curFrame = Run_Frame_Min;
}

VOID CALLBACK AniProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
    UpdateFrame(hwnd);
    InvalidateRect(hwnd, NULL, false);
}

VOID CALLBACK KeyStateProc(HWND hwnd, UINT message, UINT iTimerID, DWORD dwTime)
{
    if (GetKeyState('A') & 0x8000)
    {
        wsprintf(sKeyState, TEXT("%s"), _T("A-Key pressed"));
    }
    else if (GetKeyState('D') & 0x8000)
    {
        wsprintf(sKeyState, TEXT("%s"), _T("D-Key pressed"));
    }
    else if (GetKeyState('W') & 0x8000)
    {
        wsprintf(sKeyState, TEXT("%s"), _T("W-Key pressed"));
    }
    else if (GetKeyState('S') & 0x8000)
    {
        wsprintf(sKeyState, TEXT("%s"), _T("S-Key pressed"));
    }
    else
    {
        wsprintf(sKeyState, TEXT(""));
    }

    UpdateFrame(hwnd);
    InvalidateRect(hwnd, NULL, false);
}

void DrawBitmapDoubleBuffering(HWND hwnd, HDC hdc)
{
    HDC hDoubleBufferDC;
    HBITMAP hDoubleBufferBitmap;
    
    hDoubleBufferDC = CreateCompatibleDC(hdc);
    if ( hDoubleBufferImage == NULL )
        hDoubleBufferImage = CreateCompatibleBitmap(hdc, rectView.right, rectView.bottom);
    hOldDoubleBufferBitmap = (HBITMAP)SelectObject(hDoubleBufferDC,
        hDoubleBufferImage);

    DrawBitmap(hwnd, hDoubleBufferDC);

    BitBlt(hdc, 0, 0, rectView.right, rectView.bottom, hDoubleBufferDC, 0, 0, SRCCOPY);
    SelectObject(hDoubleBufferDC, hOldDoubleBufferBitmap);
    DeleteDC(hDoubleBufferDC);
}
