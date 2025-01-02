#pragma once

class cCamera
{
public:
	cCamera();
	~cCamera();

private:
	D3DXVECTOR3		m_vEye;
	D3DXVECTOR3		m_vLookAt;
	D3DXVECTOR3		m_vUp;
	D3DXVECTOR3* m_pvTarget;
	D3DXVECTOR3		m_vCamRotAngle;

	POINT			m_ptPrevMouse;
	bool			m_isLButtonDown;
	float			m_fCameraDistance;

public:
	void Setup(D3DXVECTOR3* pvTarget = NULL);
	void Update();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

