#pragma once

class cMainGame
{
public:
	cMainGame();
	~cMainGame();

private:
	LPDIRECT3D9			m_pD3D;
	LPDIRECT3DDEVICE9	m_pD3DDevice;

public:
	void SetUp();
	void Update();
	void Render();
};

