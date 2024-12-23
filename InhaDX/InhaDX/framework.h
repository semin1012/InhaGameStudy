// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// 다렉 헤더
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern HWND g_hWnd;
// 실질적으로 삭제하지는 않는다. Release()가 불리면 가르키는 애가 줄어듬. 가르키는 애가 0개가 되면 그때 Delete를 해서 삭제한다. 
#define Safe_Release(p) { if(p) p->Release(); p=NULL;}
#define Safe_Delete(p) { if(p) delete p; p=NULL;}