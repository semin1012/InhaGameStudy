#include "framework.h"
#include "cMainGame.h"
#include "cDeviceManager.h"
#include "cCubePC.h"
#include "cGrid.h"
#include "cCamera.h"
#include "cCubeMan.h"
#include "cFrustum.h"

#include "cObjLoader.h"
#include "cGroup.h"

cMainGame::cMainGame()
	: m_pCubePC(NULL)
	, m_pGrid(NULL)
	, m_pCamera(NULL)
	, m_pCubeMan(NULL)
	, m_pTexture(NULL)
	, m_pFrustum(NULL)
{
	srand(time(0));
}

cMainGame::~cMainGame()
{
	for (auto p : m_vecGroup)
	{
		Safe_Release(p);
	}
	m_vecGroup.clear();
	Safe_Delete(m_pFrustum);
	for (auto p : m_vecCullingSphere)
	{
		Safe_Delete(p);
	}
	m_vecCullingSphere.clear();
	Safe_Release(m_pTexture);
	Safe_Delete(m_pCamera);
	Safe_Delete(m_pGrid);
	Safe_Delete(m_pCubePC);
	Safe_Delete(m_pCubeMan);
	g_pDeviceManager->Destroy();
	g_pObjectManager->Destroy();
	g_pTextureManager->Destroy();
}

void cMainGame::Setup_Line()
{
	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(255, 0, 0); // color 설정
	v.p = D3DXVECTOR3(0, 1, 0);		// position 설정
	m_vecLineVertext.push_back(v);

	v.p = D3DXVECTOR3(0, -1, 0);
	m_vecLineVertext.push_back(v);	// position 변경 후 다시 추가
}

void cMainGame::Setup_Triangle()
{
	ST_PC_VERTEX v;
	v.c = D3DCOLOR_XRGB(255, 255, 0);			
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);	m_vecTriangleVertex.push_back(v);
	v.c = D3DCOLOR_XRGB(255, 0, 255);
	v.p = D3DXVECTOR3(-1.0f,  1.0f, 0.0f);	m_vecTriangleVertex.push_back(v);
	v.c = D3DCOLOR_XRGB(0, 255, 255);
	v.p = D3DXVECTOR3( 1.0f,  1.0f, 0.0f);	m_vecTriangleVertex.push_back(v);
}

void cMainGame::Setup_Texture()
{
	D3DXCreateTextureFromFile(g_pD3DDevice, L"cat.jpg", &m_pTexture);
	ST_PT_VERTEX v;
	v.p = D3DXVECTOR3(0, 0, 0);
	v.t = D3DXVECTOR2(0, 1);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0, 2, 0);
	v.t = D3DXVECTOR2(0, 0);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(2, 2, 0);
	v.t = D3DXVECTOR2(1, 0);
	m_vecVertex.push_back(v);
	
	v.p = D3DXVECTOR3(0, 0, 0);
	v.t = D3DXVECTOR2(0, 1);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-2, 2, 0);
	v.t = D3DXVECTOR2(1, 0);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0, 2, 0);
	v.t = D3DXVECTOR2(0, 0);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(0, 0, 0);
	v.t = D3DXVECTOR2(0, 1);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(2, 2, 0);
	v.t = D3DXVECTOR2(1, 0);
	m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(2, 0, 0);
	v.t = D3DXVECTOR2(1, 1);
	m_vecVertex.push_back(v);
}

void cMainGame::Setup_Obj()
{
	cObjLoader loader;
	loader.Load(m_vecGroup, (char*)"obj", (char*)"box.obj");
}

void cMainGame::Draw_Line()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);		// 행렬 만든 뒤 초기화
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);	// 장치 위치 초기화

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);			// 장치에게 나의 포맷을 알려줌 (SP_PC_VERTEX) 
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST,		// 선 그릴 때는 LINELIST, 삼각형 그릴 때는 TRIANGLELIST 많이 쓴다. 
		m_vecLineVertext.size() / 2,	// 몇 개인지 계산
		&m_vecLineVertext[0],			// 0번째부터 그려라 
		sizeof(ST_PC_VERTEX));			// ST_PC_VERTEXT의 크기만큼 잘라라
}

void cMainGame::Draw_Triangle()
{
	// 밑에 세 줄은 이미 설정되어있으면 또 안 해도 되긴 하지만 일단 써둔다.
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);	
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);			
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,	// 삼각형 그릴 때는 TRIANGLELIST 
		m_vecTriangleVertex.size() / 3,	// 삼각형이니까 3을 나눈다
		&m_vecTriangleVertex[0],			
		sizeof(ST_PC_VERTEX));			
}

void cMainGame::Draw_Texture()
{
	//g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);	// 앞에서는 보이는데 뒤에서는 안 보임
	// g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW);	// 앞에서는  안 보이는데 뒤에서는 보임
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);		// CULL MODE를 안 쓰겠다는 말, 양쪽에서 그린다

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);		// 따로 빛 설정 안 함
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);


	g_pD3DDevice->SetTexture(0, m_pTexture);	// 여러개 텍스처를 사용할 수 있다.
	g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PT_VERTEX));

	g_pD3DDevice->SetTexture(0, NULL);		// 쓴 이후에 텍스처 꺼줘야 한다 	

	// g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);		// true로 해줘도 되고 다른 곳 세팅에 남길거면 없애도 된다
}

void cMainGame::Draw_Obj()
{
	D3DXMATRIXA16 matWorld, matS, matR;
	D3DXMatrixScaling(&matS, 0.1f, 0.1f, 0.1f);		// 크기가 커서 줄임
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0F);	// 좌표계가 달라서 변환
	matWorld = matS * matR;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	for (auto p : m_vecGroup)
	{
		p->Render();
	}
}

void cMainGame::SetUp()
{
	Setup_Line();
	Setup_Triangle();
	Setup_Texture();
	Setup_Obj();
	Setup_Frustum();

	// 2D일 때는 조명 끄고, 3D일 때는 조명 켜면 된다.

	m_pCubePC = new cCubePC;
	m_pCubePC->Setup();

	m_pCubeMan = new cCubeMan;
	m_pCubeMan->Setup();

	m_pGrid = new cGrid;
	m_pGrid->Setup();

	m_pCamera = new cCamera;
	// m_pCamera->Setup(&m_pCubePC->GetPosition());
	m_pCamera->Setup(&m_pCubeMan->GetPosition());

	Setup_Light();

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);	// D3DRenderState_Lighting 이라는 뜻. 3D에서는 설정해줘야 색깔이 나온다.
}

void cMainGame::Update()
{
	/*RECT rc;
	GetClientRect(g_hWnd, &rc);
	
	// 위치 설정
	D3DXVECTOR3 vEye	= D3DXVECTOR3(0, 0, -5.0F);
	D3DXVECTOR3 vLookAt = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 vUp		= D3DXVECTOR3(0, 1, 0);

	// view 매트릭스 설정
	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp); // Left Hand
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj,
								D3DX_PI / 4.0F,
								(float)rc.right / rc.bottom, // 화면 비율 구함
								1.0F,		// Near
								1000.0F);	// Far
										
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);*/

	if (m_pCubePC)
		m_pCubePC->Update();

	if (m_pCubeMan)
		m_pCubeMan->Update();

	if (m_pCamera)
		m_pCamera->Update();

	if (m_pFrustum)
		m_pFrustum->Update();
}

void cMainGame::Render()
{ 
	// 지워준다.
	g_pD3DDevice->Clear(NULL,
						NULL,
						D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
						D3DCOLOR_XRGB(127, 127, 127),	// X는 alpha 값을 쓰지 않겠다는 뜻이다.
						1.0F, 0);

	// 락을 걸어준다.
	g_pD3DDevice->BeginScene();

	// Begin , end 사이에서 그림
	//Draw_Line();
	//Draw_Triangle();
	//Draw_Texture();
	//Draw_Obj();

	Draw_Frustum();

	if (m_pGrid)
		m_pGrid->Render();

	//if (m_pCubePC)
	//	m_pCubePC->Render();

	if (m_pCubeMan)
		m_pCubeMan->Render();

	g_pD3DDevice->EndScene();

	// 전체 모두 옮겨버린다. 
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}


void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);

	switch (message)
	{
	case WM_RBUTTONDOWN:
		{
			for (ST_SPHERE* s : m_vecCullingSphere)
			{
				s->isPicked = m_pFrustum->IsIn(s);
			}
		}
		break;
	}
}

void cMainGame::Setup_Light()
{
	D3DLIGHT9		stLight;
	ZeroMemory(&stLight, sizeof(D3DLIGHT9));
	
	stLight.Type = D3DLIGHT_DIRECTIONAL;
	stLight.Ambient = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Diffuse = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	stLight.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);

	D3DXVECTOR3 vDir(1.0f, -1.0f, 1.0f);
	D3DXVec3Normalize(&vDir, &vDir);
	stLight.Direction = vDir;

	g_pD3DDevice->SetLight(0, &stLight);
	g_pD3DDevice->LightEnable(0, true);
}

void cMainGame::Setup_Frustum()
{
	D3DXCreateSphere(g_pD3DDevice, 0.5f, 10, 10, &m_pSphere, NULL);

	for (int i = -20; i <= 20; ++i)
	{
		for (int j = -20; j <= 20; ++j)
		{
			for (int k = -20; k <= 20; ++k)
			{
				ST_SPHERE* s = new ST_SPHERE;
				s->fRadius = 0.5;
				s->vCenter = D3DXVECTOR3((float)i, (float)j, (float)k);
				s->isPicked = true;
				m_vecCullingSphere.push_back(s);
			}
		}
	}

	ZeroMemory(&m_stCullingMtl, sizeof(D3DMATERIAL9));
	m_stCullingMtl.Ambient = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stCullingMtl.Diffuse = D3DXCOLOR(0.7f, 1.0f, 1.0f, 1.0f);
	m_stCullingMtl.Specular = D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);

	m_pFrustum = new cFrustum;
	m_pFrustum->Setup();
}

void cMainGame::Draw_Frustum()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	for (ST_SPHERE* sphere : m_vecCullingSphere)
	{
		if (sphere->isPicked)
		{
			D3DXMatrixIdentity(&matWorld);
			matWorld._41 = sphere->vCenter.x;
			matWorld._42 = sphere->vCenter.y;
			matWorld._43 = sphere->vCenter.z;
			g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
			g_pD3DDevice->SetMaterial(&m_stCullingMtl);		// < 이거는 매번 할 필요 없음
			m_pSphere->DrawSubset(0);
		}
	}
}
