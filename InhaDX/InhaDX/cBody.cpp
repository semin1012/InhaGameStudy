#include "framework.h"
#include "cBody.h"

cBody::cBody()
{
}

cBody::~cBody()
{
}

void cBody::Setup()
{
	cCubeNode::Setup();
	D3DXCreateTextureFromFile(g_pD3DDevice, L"skin.png", &m_pTexture);

	// front
	m_vecVertex[0].t = D3DXVECTOR2(0.3125, 0.48);
	m_vecVertex[1].t = D3DXVECTOR2(0.3125, 0.31);
	m_vecVertex[2].t = D3DXVECTOR2(0.4375, 0.31);

	m_vecVertex[3].t = D3DXVECTOR2(0.3125, 0.48);
	m_vecVertex[4].t = D3DXVECTOR2(0.4375, 0.31);
	m_vecVertex[5].t = D3DXVECTOR2(0.4375, 0.48);
	
	// back
	m_vecVertex[6].t = D3DXVECTOR2(0.5, 0.48);
	m_vecVertex[7].t = D3DXVECTOR2(0.625, 0.31);
	m_vecVertex[8].t = D3DXVECTOR2(0.5, 0.31);

	m_vecVertex[9].t = D3DXVECTOR2(0.5, 0.48);
	m_vecVertex[10].t = D3DXVECTOR2(0.625, 0.48);
	m_vecVertex[11].t = D3DXVECTOR2(0.625, 0.31);
	// left
	m_vecVertex[12].t = D3DXVECTOR2(0.25, 0.48);
	m_vecVertex[13].t = D3DXVECTOR2(0.25, 0.31);
	m_vecVertex[14].t = D3DXVECTOR2(0.3, 0.31);

	m_vecVertex[15].t = D3DXVECTOR2(0.25, 0.48);
	m_vecVertex[16].t = D3DXVECTOR2(0.3, 0.31);
	m_vecVertex[17].t = D3DXVECTOR2(0.3, 0.48);
	
	// right
	m_vecVertex[18].t = D3DXVECTOR2(0.453, 0.48);
	m_vecVertex[19].t = D3DXVECTOR2(0.453, 0.31);
	m_vecVertex[20].t = D3DXVECTOR2(0.5, 0.31);

	m_vecVertex[21].t = D3DXVECTOR2(0.453, 0.48);
	m_vecVertex[22].t = D3DXVECTOR2(0.5, 0.31);
	m_vecVertex[23].t = D3DXVECTOR2(0.5, 0.48);

	// bottom
	m_vecVertex[30].t = D3DXVECTOR2(0.453, 0.3125);
	m_vecVertex[31].t = D3DXVECTOR2(0.453, 0.25);
	m_vecVertex[32].t = D3DXVECTOR2(0.5625, 0.25);

	m_vecVertex[33].t = D3DXVECTOR2(0.453, 0.3125);
	m_vecVertex[34].t = D3DXVECTOR2(0.5625, 0.25);
	m_vecVertex[35].t = D3DXVECTOR2(0.5625, 0.3125);
	/*
	// top
	m_vecVertex[24].t = D3DXVECTOR2(
	m_vecVertex[25].t =	D3DXVECTOR2(
	m_vecVertex[26].t =	D3DXVECTOR2(

	m_vecVertex[27].t =	D3DXVECTOR2(
	m_vecVertex[28].t =	D3DXVECTOR2(
	m_vecVertex[29].t =	D3DXVECTOR2(
	*/
	g_pD3DDevice->SetTexture(0, NULL);		// 쓴 이후에 텍스처 꺼줘야 한다 	
	D3DXMATRIXA16 matS, matT, matW;
	D3DXMatrixScaling(&matS, 0.4f, 0.6f, 0.2f);
	D3DXMatrixTranslation(&matT, 0.0f, 0.0f, 0.0f);
	matW = matS * matT;

	for (size_t i = 0; i < m_vecVertex.size(); i++)
	{
		// 각각의 버텍스 정보에 이 scale, translation 정보(matW)를 넘긴다.
		D3DXVec3TransformCoord(&m_vecVertex[i].p, 
			&m_vecVertex[i].p, 
			&matW);
	}
}
