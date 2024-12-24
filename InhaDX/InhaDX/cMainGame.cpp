#include "framework.h"
#include "cMainGame.h"

cMainGame::cMainGame()
{
}

cMainGame::~cMainGame()
{
	g_pDeviceManager->Destroy();
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

void cMainGame::Draw_Line()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);	// 행렬 만든 뒤 초기화
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

void cMainGame::SetUp()
{
	Setup_Line();
	Setup_Triangle();

	// 2D일 때는 조명 끄고, 3D일 때는 조명 켜면 된다.
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);	// D3DRenderState_Lighting 이라는 뜻. 3D에서는 설정해줘야 색깔이 나온다.
}

void cMainGame::Update()
{
	RECT rc;
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
										
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);
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
	Draw_Line();
	Draw_Triangle();

	g_pD3DDevice->EndScene();

	// 전체 모두 옮겨버린다. 
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
