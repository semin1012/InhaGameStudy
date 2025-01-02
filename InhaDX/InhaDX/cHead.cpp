#include "framework.h"
#include "cHead.h"

cHead::cHead()
{
}

cHead::~cHead()
{
}

void cHead::Setup()
{
	cCubeNode::Setup();
	D3DXCreateTextureFromFile(g_pD3DDevice, L"skin.png", &m_pTexture);

	// front
	m_vecVertex[0].t = D3DXVECTOR2(0.125, 0.25);
	m_vecVertex[1].t = D3DXVECTOR2(0.125, 0.125);
	m_vecVertex[2].t = D3DXVECTOR2(0.25, 0.125);

	m_vecVertex[3].t = D3DXVECTOR2(0.125, 0.25);
	m_vecVertex[4].t = D3DXVECTOR2(0.25, 0.125);
	m_vecVertex[5].t = D3DXVECTOR2(0.25, 0.25);

	// back
	m_vecVertex[6].t = D3DXVECTOR2(0.39, 0.25);
	m_vecVertex[7].t = D3DXVECTOR2(0.48, 0.125);
	m_vecVertex[8].t = D3DXVECTOR2(0.39, 0.125);

	m_vecVertex[9].t = D3DXVECTOR2(0.39, 0.25);
	m_vecVertex[10].t = D3DXVECTOR2(0.48, 0.25);
	m_vecVertex[11].t = D3DXVECTOR2(0.48, 0.125);

	// left
	m_vecVertex[12].t = D3DXVECTOR2(0, 0.25);
	m_vecVertex[13].t = D3DXVECTOR2(0, 0.125);
	m_vecVertex[14].t = D3DXVECTOR2(0.125, 0.125);

	m_vecVertex[15].t = D3DXVECTOR2(0, 0.25);
	m_vecVertex[16].t = D3DXVECTOR2(0.125, 0.125);
	m_vecVertex[17].t = D3DXVECTOR2(0.125, 0.25);

	// right
	m_vecVertex[18].t = D3DXVECTOR2(0.25, 0.25);
	m_vecVertex[19].t = D3DXVECTOR2(0.25, 0.125);
	m_vecVertex[20].t = D3DXVECTOR2(0.375, 0.125);

	m_vecVertex[21].t = D3DXVECTOR2(0.25, 0.25);
	m_vecVertex[22].t = D3DXVECTOR2(0.375, 0.125);
	m_vecVertex[23].t = D3DXVECTOR2(0.375, 0.25);

	// top
	m_vecVertex[24].t = D3DXVECTOR2(0.125, 0.125);
	m_vecVertex[25].t = D3DXVECTOR2(0.125, 0);
	m_vecVertex[26].t = D3DXVECTOR2(0.25, 0);
								   
	m_vecVertex[27].t = D3DXVECTOR2(0.125, 0.125);
	m_vecVertex[28].t = D3DXVECTOR2(0.25, 0);
	m_vecVertex[29].t = D3DXVECTOR2(0.25, 0.125);

	// bottom
	m_vecVertex[30].t = D3DXVECTOR2(0.25, 0);
	m_vecVertex[31].t = D3DXVECTOR2(0.25, 0.125);
	m_vecVertex[32].t = D3DXVECTOR2(0.375, 0.125);
									
	m_vecVertex[33].t = D3DXVECTOR2(0.25, 0);
	m_vecVertex[34].t = D3DXVECTOR2(0.375, 0.125);
	m_vecVertex[35].t = D3DXVECTOR2(0.375, 0);


	g_pD3DDevice->SetTexture(0, NULL);		// 쓴 이후에 텍스처 꺼줘야 한다 	
	D3DXMATRIXA16 matS, matT, matW;
	D3DXMatrixScaling(&matS, 0.4f, 0.4f, 0.4f);
	D3DXMatrixTranslation(&matT, 0.0f, 0.0f, 0.0f);
	matW = matS * matT;

	for (size_t i = 0; i < m_vecVertex.size(); i++)
	{
		// 각각의 버텍스 정보에 이 scale, translation 정보(matW)를 넘긴다.
		D3DXVec3TransformCoord(&m_vecVertex[i].p,
			&m_vecVertex[i].p,
			&matW);
	}

	// 몸통 y = 0.6f (이것의 반은 0.3f)
	// 머리 y = 0.4f (이것의 반은 0.2f) 둘을 더해서 0.5f만큼 올리면 됨
	m_vLocalPos.y += 0.5f;
}
