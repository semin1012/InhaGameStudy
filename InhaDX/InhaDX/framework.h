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

// >> : 공용 포함 헤더
#include <vector>
#include <string>
#include <map>
#include <set>
#include <list>
#include <assert.h>
#include <time.h>
// << :

// 다렉 헤더
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

extern HWND g_hWnd;
// 실질적으로 삭제하지는 않는다. Release()가 불리면 가르키는 애가 줄어듬. 가르키는 애가 0개가 되면 그때 Delete를 해서 삭제한다. 
#define Safe_Release(p) { if(p) p->Release(); p=NULL;}
#define Safe_Delete(p) { if(p) delete p; p=NULL;}
#define Singleton(class_name) \
		private: \
			class_name(void) ; \
			~class_name(void) ; \
		public: \
			static class_name* GetInstance() \
			{ \
				static class_name instance; \
				return &instance; \
			}

#define Synthesize(varType, varName, funName) \
	protected : varType varName; \
	public : inline varType Get##funName(void) const { return varName; } \
	public : inline void Set##funName(varType var) { varName = var; }

#define Synthesize_Pass_By_Ref(varType, varName, funName) \
	protected : varType varName; \
	public : inline varType& Get##funName(void) { return varName; } \
	public : inline void Set##funName(varType& var) { varName = var; }
// 
#define Safe_Add_Ref(p) { if(p) p->AddRef(); }

#define Synthesize_Add_Ref(varType, varName, funName) \
   protected: varType varName; \
   public: inline varType Get##funName(void) const {return varName; } \
   public : inline void Set##funName(varType var) {\
					if ( varName != var ) {\
						Safe_Add_Ref(var) ; \
						Safe_Release(varName) ; \
						varName = var; \
					} \
				}

struct ST_PC_VERTEX		// 점의 정보
{
	D3DXVECTOR3 p;		// float을 안 쓴 이유: D3D를 상속받아 x, y, z 값을 포함하고 있는 자료형임
	D3DCOLOR c;
	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
};

struct ST_PNT_VERTEX	// Light를 포함하여 텍스처를 출력
{
	D3DXVECTOR3 p;
	D3DXVECTOR3 n;	
	D3DXVECTOR2 t;		// texture는 x, y 두가지 값만 가지고 있기 때문에 Vector2
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 };
};

struct ST_PT_VERTEX		// normal을 제외하면 Light를 사용하지 않게 된다. 
{
	D3DXVECTOR3 p;
	D3DXVECTOR2 t;	
	enum { FVF = D3DFVF_XYZ | D3DFVF_TEX1 };
};

#include "cDeviceManager.h"
#include "cObject.h"
#include "cObjectManager.h"
#include "cTextureManager.h"