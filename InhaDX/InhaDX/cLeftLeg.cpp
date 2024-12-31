#include "framework.h"
#include "cLeftLeg.h"

cLeftLeg::cLeftLeg()
{
}

cLeftLeg::~cLeftLeg()
{
}

void cLeftLeg::Setup()
{
	cCubeNode::Setup();

	D3DXMATRIXA16 matS, matT, matW;
	D3DXMatrixScaling(&matS, 0.2f, 0.6f, 0.2f);
	D3DXMatrixTranslation(&matT, -0.1f, -0.3f, 0.0f);	// ȸ������ �̵���Ų��.
	matW = matS * matT;

	for (size_t i = 0; i < m_vecVertex.size(); i++)
	{
		// ������ ���ؽ� ������ �� scale, translation ����(matW)�� �ѱ��.
		D3DXVec3TransformCoord(&m_vecVertex[i].p,
			&m_vecVertex[i].p,
			&matW);
	}

	// position�� �ű��.
	m_vLocalPos.y = -0.3f;
}
