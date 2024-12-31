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
		// ������ ���ؽ� ������ �� scale, translation ����(matW)�� �ѱ��.
		D3DXVec3TransformCoord(&m_vecVertex[i].p,
			&m_vecVertex[i].p,
			&matW);
	}

	// ���� y = 0.6f (�̰��� ���� 0.3f)
	// �Ӹ� y = 0.4f (�̰��� ���� 0.2f) ���� ���ؼ� 0.5f��ŭ �ø��� ��
	m_vLocalPos.y += 0.5f;
}
