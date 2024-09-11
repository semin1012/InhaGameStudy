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

// >> : for gid+
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;

#pragma comment(lib, "Msimg32.lib")
#pragma comment(lib, "Gdiplus.lib")


#define WINDOW_WIDTH_SIZE   1280
#define WINDOW_HEIGHT_SIZE  800

#define BOARD_SIZE_X (WINDOW_WIDTH_SIZE / 10)
#define BOARD_SIZE_Y (WINDOW_HEIGHT_SIZE / 10)
