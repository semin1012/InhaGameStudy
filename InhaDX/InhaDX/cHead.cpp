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
