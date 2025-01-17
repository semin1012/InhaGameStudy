#pragma once

class cCubePC;
class cGrid;
class cCamera;
class cCubeMan;
class cGroup;
class cFrustum;

class cMainGame
{
private:
	std::vector<ST_PC_VERTEX>	m_vecLineVertext;
	std::vector<ST_PC_VERTEX>	m_vecTriangleVertex;

	cCubePC*					m_pCubePC;
	cCubeMan*					m_pCubeMan;

	std::vector<cGroup*>		m_vecGroup;

	cGrid*						m_pGrid;
	cCamera*					m_pCamera;

	LPDIRECT3DTEXTURE9			m_pTexture;
	std::vector<ST_PT_VERTEX>	m_vecVertex;

	// >> :
	LPD3DXMESH					m_pSphere;
	std::vector<ST_SPHERE*>		m_vecCullingSphere;
	D3DMATERIAL9				m_stCullingMtl;
	cFrustum*					m_pFrustum;
	// << :

public:
	cMainGame();
	~cMainGame();

public:
	void Setup_Line();
	void Setup_Triangle();
	void Setup_Texture();
	void Setup_Obj();

	void Draw_Line();
	void Draw_Triangle();
	void Draw_Texture();
	void Draw_Obj();

	void SetUp();
	void Update();
	void Render();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Setup_Light();

	void Setup_Frustum();
	void Draw_Frustum();
};

