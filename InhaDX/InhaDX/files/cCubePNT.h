#pragma once
class cCubePNT
{
public:
	cCubePNT();
	virtual ~cCubePNT();

protected:
	std::vector<ST_PNT_VERTEX>	m_vecVertex;
	LPDIRECT3DTEXTURE9			m_pTexture;

public:
	virtual void Setup();
	virtual void Update();
	virtual void Render();
};

