﻿#include "framework.h"
#include "cCamera.h"

cCamera::cCamera()
	: m_fCameraDistance(5.0f)
	, m_isLButtonDown(false)
	, m_pvTarget(NULL)
	, m_vCamRotAngle(0, 0, 0)
	, m_vEye(0, 0, -5)
	, m_vLookAt(0, 0, 0)
	, m_vUp(0, 1, 0)
{
	m_ptPrevMouse.x = 0;
	m_ptPrevMouse.y = 0;
}

cCamera::~cCamera()
{
}

void cCamera::Setup(D3DXVECTOR3* pvTarget)
{
	m_pvTarget = pvTarget;

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj,
		D3DX_PI / 4.0f,
		(float)rc.right / rc.bottom,
		1.0f, 1000.0f);

	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);

}

void cCamera::Update()
{
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIXA16 matR, matRX, matRY;
	D3DXMatrixRotationX(&matRX, m_vCamRotAngle.x);
	D3DXMatrixRotationY(&matRY, m_vCamRotAngle.y);

	matR = matRX * matRY;

	m_vEye = D3DXVECTOR3(0, 0, -m_fCameraDistance);

	D3DXVec3TransformCoord(&m_vEye, &m_vEye, &matR);

	// >> : target ����ٴϴ� �ڵ�
	if (m_pvTarget)
	{
		m_vLookAt = *m_pvTarget;
		m_vEye = m_vEye + *m_pvTarget;
	}
	// << :

	D3DXMATRIXA16 matView;
	D3DXMatrixLookAtLH(&matView, &m_vEye, &m_vLookAt, &m_vUp);
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);


}

void cCamera::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		m_isLButtonDown = true;
		m_ptPrevMouse.x = LOWORD(lParam);
		m_ptPrevMouse.y = HIWORD(lParam);
		break;

	case WM_LBUTTONUP:
		m_isLButtonDown = false;
		break;

	case WM_MOUSEMOVE:
		if (m_isLButtonDown)
		{
			POINT ptCurMouse;
			ptCurMouse.x = LOWORD(lParam);
			ptCurMouse.y = HIWORD(lParam);

			float fDeltaX = (float)(ptCurMouse.x - m_ptPrevMouse.x);
			float fDeltaY = (float)(ptCurMouse.y - m_ptPrevMouse.y);

			m_vCamRotAngle.y += (fDeltaX / 100.f);
			m_vCamRotAngle.x += (fDeltaY / 100.f);

			if (m_vCamRotAngle.x <= -D3DX_PI / 2.0F + 0.0001F)
				m_vCamRotAngle.x = -D3DX_PI / 2.0F + 0.0001F;

			if (m_vCamRotAngle.x >= D3DX_PI / 2.0F - 0.0001F)
				m_vCamRotAngle.x = D3DX_PI / 2.0F - 0.0001F;

			m_ptPrevMouse = ptCurMouse;
		}
		break;

	case WM_MOUSEWHEEL:
		m_fCameraDistance -= (GET_WHEEL_DELTA_WPARAM(wParam) / 30.0f);
		if (m_fCameraDistance <= 0.0001f)
			m_fCameraDistance = 0.0001f;
		break;
	default:
		break;
	}
}
