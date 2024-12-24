#include "framework.h"

cDeviceManager::cDeviceManager() : m_pD3D(NULL), m_pD3DDevice(NULL)
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
	stD3Dpp.EnableAutoDepthStencil = TRUE;			// 그림자 안 만들거기 때문에 쓸모없는 설정이긴 하지만 쓴다
	stD3Dpp.AutoDepthStencilFormat = D3DFMT_D16;	// Depth 쓸 거기 때문에 포맷 설정해 줘야 됨

	// 이 설정을 가지고 디바이스를 만들어 준다.
	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		g_hWnd,
		nVertextProcessing,
		&stD3Dpp,
		&m_pD3DDevice);
}

cDeviceManager::~cDeviceManager()
{

}

LPDIRECT3DDEVICE9 cDeviceManager::GetDevice()
{
	return m_pD3DDevice; 
}

void cDeviceManager::Destroy()
{
	Safe_Release(m_pD3DDevice);
	Safe_Release(m_pD3D);
}
