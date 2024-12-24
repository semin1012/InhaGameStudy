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
	v.c = D3DCOLOR_XRGB(255, 0, 0); // color ����
	v.p = D3DXVECTOR3(0, 1, 0);		// position ����
	m_vecLineVertext.push_back(v);

	v.p = D3DXVECTOR3(0, -1, 0);
	m_vecLineVertext.push_back(v);	// position ���� �� �ٽ� �߰�
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
	D3DXMatrixIdentity(&matWorld);	// ��� ���� �� �ʱ�ȭ
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);	// ��ġ ��ġ �ʱ�ȭ

	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);			// ��ġ���� ���� ������ �˷��� (SP_PC_VERTEX) 
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST,		// �� �׸� ���� LINELIST, �ﰢ�� �׸� ���� TRIANGLELIST ���� ����. 
		m_vecLineVertext.size() / 2,	// �� ������ ���
		&m_vecLineVertext[0],			// 0��°���� �׷��� 
		sizeof(ST_PC_VERTEX));			// ST_PC_VERTEXT�� ũ�⸸ŭ �߶��
}

void cMainGame::Draw_Triangle()
{
	// �ؿ� �� ���� �̹� �����Ǿ������� �� �� �ص� �Ǳ� ������ �ϴ� ��д�.
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);	
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);			
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,	// �ﰢ�� �׸� ���� TRIANGLELIST 
		m_vecTriangleVertex.size() / 3,	// �ﰢ���̴ϱ� 3�� ������
		&m_vecTriangleVertex[0],			
		sizeof(ST_PC_VERTEX));			
}

void cMainGame::SetUp()
{
	Setup_Line();
	Setup_Triangle();

	// 2D�� ���� ���� ����, 3D�� ���� ���� �Ѹ� �ȴ�.
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);	// D3DRenderState_Lighting �̶�� ��. 3D������ ��������� ������ ���´�.
}

void cMainGame::Update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);
	
	// ��ġ ����
	D3DXVECTOR3 vEye	= D3DXVECTOR3(0, 0, -5.0F);
	D3DXVECTOR3 vLookAt = D3DXVECTOR3(0, 0, 0);
	D3DXVECTOR3 vUp		= D3DXVECTOR3(0, 1, 0);

	// view ��Ʈ���� ����
	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &vEye, &vLookAt, &vUp); // Left Hand
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj,
								D3DX_PI / 4.0F,
								(float)rc.right / rc.bottom, // ȭ�� ���� ����
								1.0F,		// Near
								1000.0F);	// Far
										
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}

void cMainGame::Render()
{ 
	// �����ش�.
	g_pD3DDevice->Clear(NULL,
						NULL,
						D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
						D3DCOLOR_XRGB(127, 127, 127),	// X�� alpha ���� ���� �ʰڴٴ� ���̴�.
						1.0F, 0);

	// ���� �ɾ��ش�.
	g_pD3DDevice->BeginScene();

	// Begin , end ���̿��� �׸�
	Draw_Line();
	Draw_Triangle();

	g_pD3DDevice->EndScene();

	// ��ü ��� �Űܹ�����. 
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
