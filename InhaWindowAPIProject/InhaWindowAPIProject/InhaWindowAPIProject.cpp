// InhaWindowAPIProject.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "InhaWindowAPIProject.h"
#include <commdlg.h>
#include <CommCtrl.h>
#include <stdio.h>
#pragma comment(lib, "Msimg32.lib")

#include <winsock.h>
#pragma comment(lib, "ws2_32.lib")

#define MAX_LOADSTRING 100

#define Buf_Size 1024
void Error(const char* msg);
void Log(const char* msg);

char strServerIP[] = "172.30.1.85";
// char strServerIP[] = "127.0.0.1";    // 내 컴퓨터의 IP

char strPort[] = "12345";   // 8080(인터넷 열때)처럼 많이 알려진 포트는 사용하지 말것

/*
Q1. 

Q2. 갈소패닉 게임을 모작하시오.


*/

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.


// User Define
HINSTANCE   g_hInst;
HWND        g_hWnd;

#define TIMER_ID1 1
#define TIMER_ID2 2
#define TIMER_ANI 3
#define TIMER_KEYSTATE 4

#define CIRCLE_RADIUS 50

#define IDC_CHILD2_BTN 100


void Update();

// >> : for gid+
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")

ULONG_PTR g_GdipPlusToken;
void Gdi_Init();
void Gdi_Draw(HDC hdc);
void Gdi_End();

// >> : Modeless Window
HWND g_hDlg = nullptr;
void MakeColumn(HWND hDlg);
void InsertData(HWND hDlg);
// << : Modeless Window

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

    Gdi_Init();

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

    Gdi_End();

    return (int) msg.wParam;
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

   g_hWnd = hWnd;
   g_hInst = hInstance;

   ShowWindow(hWnd, SW_SHOW);   // SW_MAXIMIZE로 하면 최대창으로 시작
   UpdateWindow(hWnd);

   return TRUE;
}

// >> : image

// : background image
HBITMAP hBackImage;
BITMAP bitBack;

// : front Image
HBITMAP hFrontImage;
BITMAP bitFront;

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
BOOL CALLBACK Dialog1_Proc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK Dialog2_Proc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);

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

// >> : Window Split ...
HWND ChildWnd[3];
LRESULT CALLBACK ChildWndProc1(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWndProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ChildWndProc3(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
// << : Window Split

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_INHAWINDOWAPIPROJECT));
    wcex.hCursor = LoadCursor(nullptr, IDC_CROSS);
    wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255)); //RGB(230, 210, 210));// GetStockObject(DKGRAY_BRUSH);//(COLOR_WINDOW+3);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_INHAWINDOWAPIPROJECT);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(NULL, IDI_QUESTION);

    RegisterClassExW(&wcex);

    wcex.lpfnWndProc = ChildWndProc1;
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = _T("Child Window Class 1");
    RegisterClassExW(&wcex);

    wcex.lpfnWndProc = ChildWndProc2;
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = _T("Child Window Class 2");
    RegisterClassExW(&wcex);

    wcex.lpfnWndProc = ChildWndProc3;
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = _T("Child Window Class 3");
    RegisterClassExW(&wcex);

    return NULL;
}

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

        // >> : Child Window
        ChildWnd[0] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child Window Class 1"), NULL,
            WS_CHILD | WS_VISIBLE, 0, 0, rectView.right, rectView.bottom / 2 - 1, hWnd, NULL, hInst, NULL);
        ChildWnd[1] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child Window Class 2"), NULL,
            WS_CHILD | WS_VISIBLE, 0, rectView.bottom / 2 + 1, rectView.right / 2 - 1, rectView.bottom, hWnd, NULL, hInst, NULL);
        ChildWnd[2] = CreateWindowEx(WS_EX_CLIENTEDGE, _T("Child Window Class 3"), NULL,
            WS_CHILD | WS_VISIBLE, rectView.right / 2 + 1, rectView.bottom / 2 + 1, rectView.right, rectView.bottom, hWnd, NULL, hInst, NULL);
        // << : Child Window

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
        flag = true;
        break;
    case WM_KEYUP:
        flag = false;
        break;
    case WM_CHAR:
        break;
    case WM_LBUTTONDOWN:
    {
        int x, y;
    }
    break;
    case WM_LBUTTONUP:
        mouseFlag = FALSE;
        break;
    case WM_RBUTTONDOWN:
    {
        // DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Dialog1_Proc);
        if (!IsWindow(g_hDlg))
        {
            g_hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_MODELESS), hWnd, Dialog2_Proc);
            ShowWindow(g_hDlg, SW_SHOW);
        }
    }
    break;
    case WM_RBUTTONUP:
        break;
    case WM_SIZE:
        GetClientRect(hWnd, &rectView);
        break;
    //case WM_PAINT:
    //{
    //    PAINTSTRUCT ps;
    //    HDC hdc = BeginPaint(hWnd, &ps);

    //    // DrawBitmap(hWnd, hdc);
    //    DrawBitmapDoubleBuffering(hWnd, hdc);

    //    TextOut(hdc, 10, 10, sKeyState, _tcslen(sKeyState));

    //    EndPaint(hWnd, &ps);
    //}
    //break;
       // break;
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
#pragma region DoubleBuffering & Bitmap

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
    // << :

    // >> : front Image
    hFrontImage = (HBITMAP)LoadImage(NULL, TEXT("../Data/front.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
    if (hFrontImage == NULL)
    {
        DWORD dwError = GetLastError();
        MessageBox(NULL, _T("front 이미지 파일을 열 수 없습니다."), _T("에러"), MB_OK);
    }
    else
    {
        GetObject(hFrontImage, sizeof(BITMAP), &bitFront);
    }
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

        StretchBlt(hdc, 0, 0, rectView.right, rectView.bottom, hMemDC, 0, 0, bx, by, SRCCOPY); // hMemDC의 이미지를 hdc로 복사

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

    // >> : Front Image
    {
        hMemDC = CreateCompatibleDC(hdc); // hdc와 호환되는 메모리 DC 생성
        hOldBitmap = (HBITMAP)SelectObject(hMemDC, hFrontImage); // hMemDC에 hBackImage를 선택 -> 이미지가 올라와 있는 상태
        bx = bitFront.bmWidth;
        by = bitFront.bmHeight;

        HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 255));
        HBRUSH oldBrush = (HBRUSH)SelectObject(hMemDC, hBrush);
        Ellipse(hMemDC, 50, 250, 400, 470);

        SelectObject(hMemDC, oldBrush);
        DeleteObject(hBrush);

        TransparentBlt(hdc, 0, 0, rectView.right, rectView.bottom, hMemDC, 0, 0, bx, by, RGB(255, 0, 255));

        SelectObject(hMemDC, hOldBitmap); // hMemDC에 선택된 이미지를 해제
        DeleteDC(hMemDC); // 메모리 DC 삭제
    }
    // << : Front Image

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

    Gdi_Draw(hdc);
}

void DeleteBitmap()
{
    DeleteObject(hBackImage);
    DeleteObject(hTransParentImage);
    DeleteObject(hAniImage);
    DeleteObject(hDoubleBufferImage);
}

void Gdi_Init()
{
    GdiplusStartupInput gpsi;

    GdiplusStartup(&g_GdipPlusToken, &gpsi, NULL);
}

void Gdi_Draw(HDC hdc)
{
    Graphics graphics(hdc);
    // 원래는 Draw 하고 Load 하면 안 된다, Load 따로 해야 함

    // :
    SolidBrush brush(Color(255, 255, 0, 0));
    FontFamily fontFamily(L"Times New Roman");
    Font font(&fontFamily, 24, FontStyleRegular, UnitPixel);
    PointF pointF(10.0f, 20.0f);
    graphics.DrawString(L"Hello GDI+!", -1, &font, pointF, &brush);

    // :
    Pen pen(Color(255, 0, 255, 255));
    graphics.DrawLine(&pen, 0, 0, 200, 100);

    // : png 출력
    Image img((WCHAR*)L"../images/sigong.png");
    int w = img.GetWidth();
    int h = img.GetHeight();
    graphics.DrawImage(&img, 100, 100, w, h);

    // : 컬러 키값 빼고 png 출력
    Image img2((WCHAR*)L"../images/zero_run.png");
    w = img2.GetWidth() / SPRITE_COUNT;
    h = img2.GetHeight() / SPRITE_DIRECTION;
    int xStart = curFrame * w;
    int yStart = 0; // 한쪽 방향

    ImageAttributes imgAttr0;
    imgAttr0.SetColorKey(Color(245, 0, 245), Color(255, 10, 255));  // 블렌드를 해서 색깔 빼줄 수 있음
    graphics.DrawImage(&img2, Rect(200, 100, w, h), xStart, yStart, w, h, UnitPixel, &imgAttr0);

    // :
    brush.SetColor(Color(64, 255, 0, 0));
    graphics.FillRectangle(&brush, 100, 100, 200, 300);

    // :
    Image* pImg = nullptr;
    pImg = Image::FromFile((WCHAR*)L"../images/sigong.png");
    int xPos = 300;
    int yPos = 200;
    if (pImg)
    {
        w = pImg->GetWidth();
        h = pImg->GetHeight();

        Gdiplus::Matrix mat;
        static int rot = 0;
        mat.RotateAt((rot % 360), Gdiplus::PointF(xPos + ((float)w / 2), yPos + ((float)h / 2)));
        graphics.SetTransform(&mat);
        graphics.DrawImage(pImg, xPos, yPos, w, h);
        rot += 10;

        mat.Reset();
        graphics.SetTransform(&mat);
    }

    // : 
    ImageAttributes imgAttr;
    imgAttr.SetColorKey(Color(245, 0, 245), Color(255, 10, 255));  // 블렌드를 해서 색깔 빼줄 수 있음
    yPos = 300;

    graphics.DrawImage(pImg, Rect(xPos, yPos, w, h), 0, 0, w, h, UnitPixel, &imgAttr);

    // : 반투명 이미지
    if (pImg)
    {
        REAL transparency = 0.5f;
        ColorMatrix colorMatrix =
        {
            1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 0.0f, transparency, 0.0f,
            0.0f, 0.0f, transparency, 0.0f, 1.0f
        };
        imgAttr.SetColorMatrix(&colorMatrix);
        xPos = 400;

        graphics.DrawImage(pImg, Rect(xPos, yPos, w, h), 0, 0, w, h, UnitPixel, &imgAttr);


        // : 흑백 이미지
        ColorMatrix colorMatrix2 =
        { // R     G     B      
            0.3f, 0.3f, 0.3f, 0.0f, 0.0f,   // R
            0.6f, 0.6f, 0.6f, 0.0f, 0.0f,   // G
            0.1f, 0.1f, 0.1f, 0.0f, 0.0f,   // B
            0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f, 1.0f
        };
        imgAttr.SetColorMatrix(&colorMatrix2);
        xPos = 500;

        graphics.DrawImage(pImg, Rect(xPos, yPos, w, h), 0, 0, w, h, UnitPixel, &imgAttr);

        // : x축 반전
        xPos = 600;
        pImg->RotateFlip(RotateNoneFlipX);
        graphics.DrawImage(pImg, Rect(xPos, yPos, w, h), 0, 0, w, h, UnitPixel, &imgAttr);
    }

    if (pImg) delete pImg;
}

void Gdi_End()
{
    GdiplusShutdown(g_GdipPlusToken);
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
#pragma endregion

LRESULT CALLBACK ChildWndProc1(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        SetTimer(hWnd, TIMER_ANI, 33, AniProc);
        SetTimer(hWnd, TIMER_KEYSTATE, 100, KeyStateProc);
        break;
    case WM_COMMAND:
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
    case WM_DESTROY:
        KillTimer(hWnd, TIMER_ANI);
        KillTimer(hWnd, TIMER_KEYSTATE);
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK ChildWndProc2(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static POINT ptMouse;
    HWND hBtn;
    static bool bToggle;

    switch (message)
    {
    case WM_CREATE:
        hBtn = CreateWindow(_T("button"), _T("OK"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 100, 100, 30, hWnd, (HMENU)IDC_CHILD2_BTN, hInst, NULL);
        break;
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_CHILD2_BTN:
            bToggle = !bToggle;
            InvalidateRect(hWnd, NULL, true);
            break;
        }
        break;
    case WM_MOUSEMOVE:
        // GetCursorPos(&ptMouse);
        ptMouse.x = LOWORD(lParam);
        ptMouse.y = HIWORD(lParam);
        InvalidateRect(hWnd, NULL, false);
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // >> : mouse 
            TCHAR str[128];
            wsprintf(str, TEXT("World Position : (%04d,%04d)"), ptMouse.x, ptMouse.y);
            TextOut(hdc, 10, 30, str, lstrlen(str));

            /*ScreenToClient(hWnd, &ptMouse);*/
            wsprintf(str, TEXT("Local Position : (%04d,%04d)"), ptMouse.x, ptMouse.y);
            TextOut(hdc, 10, 50, str, lstrlen(str));
            // << : mouse

            // >> : button text
            if (bToggle)
                TextOut(hdc, 200, 50, _T("Button Clicked"), lstrlen(_T("Button Clicked")));
            // << : button text
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK ChildWndProc3(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HWND hBtn;
    switch (message)
    {
    case WM_CREATE:
        hBtn = CreateWindow(_T("button"), _T("OK"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 100, 100, 30, hWnd, (HMENU)IDC_CHILD2_BTN, hInst, NULL);
        break;
    case WM_COMMAND:
        break;
    case WM_PAINT:
    {

    }
    break;
    case WM_DESTROY:
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}


#pragma region  Timer Proc

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
#pragma endregion


BOOL CALLBACK Dialog1_Proc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static int Check[3], Radio;
    TCHAR hobby[][30] = { _T("독서"), _T("음악 감상"), _T("게임") };
    TCHAR sex[][30] = { _T("여성"), _T("남성") };
    TCHAR output[200];

    // >> : Combo
    static HWND hCombo;
    static HWND hList;
    static int selection;
    TCHAR name[20];
    // << : Combo

    switch (uMsg)
    {
    case WM_INITDIALOG:
        {
            HWND btn = GetDlgItem(hDlg, IDC_BTN_PAUSE);
            EnableWindow(btn, FALSE);

            CheckRadioButton(hDlg, IDC_RADIO_FEMALE, IDC_RADIO_MALE, IDC_RADIO_FEMALE);

            hCombo = GetDlgItem(hDlg, IDC_COMBO_LIST);
            hList = GetDlgItem(hDlg, IDC_LIST_NAMES);
        }
        return 1;
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BTN_START:
            {
                HWND btn = GetDlgItem(hDlg, IDC_BTN_START);
                EnableWindow(btn, FALSE);
                btn = GetDlgItem(hDlg, IDC_BTN_PAUSE);
                EnableWindow(btn, TRUE);
                SetDlgItemText(hDlg, IDC_BTN_INFO, _T("게임 시작"));
            }
            break;
        case IDC_BTN_PAUSE:
            {
                HWND btn = GetDlgItem(hDlg, IDC_BTN_START);
                EnableWindow(btn, TRUE);
                btn = GetDlgItem(hDlg, IDC_BTN_PAUSE);
                EnableWindow(btn, FALSE);
                SetDlgItemText(hDlg, IDC_BTN_INFO, _T("게임 정지"));
            }
            break;
        case IDC_BTN_COPY:
            {
                TCHAR word[100];
                GetDlgItemText(hDlg, IDC_EDIT_SOURCE, word, _tcsclen(word));
                SetDlgItemText(hDlg, IDC_EDIT_DEST, word);
            }
            break;
        case IDC_BTN_CLEAR:
            SetDlgItemText(hDlg, IDC_EDIT_SOURCE, _T(""));
            SetDlgItemText(hDlg, IDC_EDIT_DEST, _T(""));
            break;
        case IDC_CHECK_READING:
            Check[0] = 1 - Check[0];
            break;
        case IDC_CHECK_MUSIC:
            Check[1] = 1 - Check[1];
            break;
        case IDC_CHECK_GAME:
            Check[2] = 1 - Check[2];
            break;
        case IDC_RADIO_FEMALE:
            Radio = 0;
            break;
        case IDC_RADIO_MALE:
            Radio = 1;
            break;
        case IDC_BNT_OUTPUT:
            _stprintf_s(output, _T("선택한 취미는 %s %s %s 입니다.\r\n")
                _T("선택한 성별은 %s 입니다."),
                Check[0] ? hobby[0] : _T(""),
                Check[1] ? hobby[1] : _T(""),
                Check[2] ? hobby[2] : _T(""),
                sex[Radio]);
            SetDlgItemText(hDlg, IDC_EDIT_OUTPUT, output);
            break;
        case IDC_BTN_EXIT:
            EndDialog(hDlg, 0);
            break;
        case IDC_BTN_CLOSE:
            EndDialog(hDlg, 0);
            break;
        // >> : Combo
        case IDC_BTN_INSERT:
            GetDlgItemText(hDlg, IDC_EDIT_NAME, name, _tcslen(name));
            if (_tcscmp(name, _T(""))) 
            {
                SendMessage(hList, LB_ADDSTRING, 0, (LPARAM)name);
                SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)name);
                SetDlgItemText(hDlg, IDC_EDIT_NAME, L"");
            }
            break;
        case IDC_BTN_DELETE:
            SendMessage(hCombo, CB_DELETESTRING, selection, 0);
            SendMessage(hList, LB_DELETESTRING, selection, 0);
            break;
        case IDC_COMBO_LIST:
            if ( HIWORD(wParam) == CBN_SELCHANGE )
                selection = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
            break;
        case IDC_LIST_NAME:
            if (HIWORD(wParam) == LBN_SELCHANGE)
                selection = SendMessage(hList, LB_GETCURSEL, 0, 0);
            break;
        // << : Combo
        }
    }
    return 0;
}


void MakeColumn(HWND hDlg)
{
    LPCTSTR name[2] = { _T("이름"), _T("전화번호") };
    LVCOLUMN lvCol = { 0, };
    HWND hList;

    hList = GetDlgItem(hDlg, IDC_LIST_CTRL);
    lvCol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
    lvCol.fmt = LVCFMT_LEFT;
    
    for (int i = 0; i < 2; i++)
    {
        lvCol.cx = 90;
        lvCol.iSubItem = i;
        lvCol.pszText = (LPWSTR)name[i];
        SendMessage(hList, LVM_INSERTCOLUMN, (WPARAM)i, (LPARAM)&lvCol);
    }
}

void InsertData(HWND hDlg)
{
    LVITEM item;
    LPCTSTR name[20] = { _T("홍길동"), _T("카리나") };
    LPCTSTR phone[20] = { _T("000-0000-0000"), _T("010-9384-3189") };

    HWND hList = GetDlgItem(hDlg, IDC_LIST_CTRL);

    for (int i = 0; i < 2; i++)
    {
        item.mask = LVIF_TEXT;
        item.iItem = i;
        item.iSubItem = 0;
        item.pszText = (LPWSTR)name[i];
        ListView_InsertItem(hList, &item);
        ListView_SetItemText(hList, i, 1, (LPWSTR)phone[i]);
    }
}

BOOL CALLBACK Dialog2_Proc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        SetDlgItemText(hDlg, IDC_STATIC, _T("모달리스 대화상자"));
        MakeColumn(hDlg);
        break;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            DestroyWindow(hDlg);
            g_hDlg = nullptr;
            return 0;
        }

        switch (LOWORD(wParam))
        {
        case IDC_BTN_LIST_INSERT:
            InsertData(hDlg);
            return 0;
            break;
        }
        break;
    }
    return 0;
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
