#pragma once

class cGizmo
{
public:
	cGizmo();
	~cGizmo();

private:
	std::vector<ST_PC_VERTEX>	m_vecVertex;
	D3DXMATRIXA16				m_matR;

public:
	void Setup(D3DCOLOR c, D3DXMATRIXA16& mat);
	void Render();
};

