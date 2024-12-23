#include "framework.h"
#include "cMainGame.h"

cMainGame::cMainGame() : m_pD3D(NULL), m_pD3DDevice(NULL)
{
}

cMainGame::~cMainGame()
{
	Safe_Release(m_pD3DDevice);
	Safe_Release(m_pD3D);
}

void cMainGame::SetUp()
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	
	D3DCAPS9	stCaps;
	int			nVertextProcessing;
	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &stCaps);
	if (stCaps.DevCaps && D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		nVertextProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else
	{
		nVertextProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	D3DPRESENT_PARAMETERS stD3Dpp;
	ZeroMemory(&stD3Dpp, sizeof(D3DPRESENT_PARAMETERS));
	stD3Dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	stD3Dpp.Windowed = TRUE;
	stD3Dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	stD3Dpp.EnableAutoDepthStencil = TRUE;			// �׸��� �� ����ű� ������ ������� �����̱� �ϴ�
	stD3Dpp.AutoDepthStencilFormat = D3DFMT_D16;	// Depth �� �ű� ������ ���� ������ ��� ��

	// �� ������ ������ ����̽��� ����� �ش�.
	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, 
						D3DDEVTYPE_HAL, 
						g_hWnd, 
						nVertextProcessing, 
						&stD3Dpp, 
						&m_pD3DDevice);
}

void cMainGame::Update()
{
}

void cMainGame::Render()
{
	// �����ش�.
	m_pD3DDevice->Clear(NULL,
						NULL,
						D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
						D3DCOLOR_XRGB(127, 127, 127),	// X�� alpha ���� ���� �ʰڴٴ� ���̴�.
						1.0F, 0);

	// ���� �ɾ��ش�.
	m_pD3DDevice->BeginScene();

	// Begin , end ���̿��� �׸�

	m_pD3DDevice->EndScene();

	// ��ü ��� �Űܹ�����. 
	m_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}
