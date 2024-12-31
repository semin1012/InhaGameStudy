#include "framework.h"
#include "cCubeNode.h"

cCubeNode::cCubeNode()
	: m_fRotDeltaX(0.0f)
	, m_pParentWorldTM(NULL)
	, m_vLocalPos(0, 0, 0)
{
	D3DXMatrixIdentity(&m_matLocalTM);
	D3DXMatrixIdentity(&m_matWorldTM);
}

cCubeNode::~cCubeNode()
{
}

void cCubeNode::AddChild(cCubeNode* pChild)
{
	pChild->m_pParentWorldTM = &m_matWorldTM;
	m_vecChild.push_back(pChild);
}

void cCubeNode::Destroy()
{
	for (auto p : m_vecChild)
	{
		p->Destroy();
	}
	delete this;
}

void cCubeNode::Setup()
{
	cCubePNT::Setup();
}

void cCubeNode::Update()
{
	cCubePNT::Update();

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);

	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);

	m_matLocalTM = matR * matT;
	m_matWorldTM = m_matLocalTM;

	// �θ� �ִٸ� �θ� �ͱ��� �������
	if (m_pParentWorldTM)
		m_matWorldTM *= *m_pParentWorldTM;

	// �ڽ��� �ִٸ� �ڽ����׵� �������. �ڽ� Update�� �θ��� ����� �� ��.
	for (auto p : m_vecChild)
	{
		p->Update();
	}
}

void cCubeNode::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
	
	// �� �Ÿ� �׸� �� �ڽ� �͵� ��� �׸�
	cCubePNT::Render();
	for (auto p : m_vecChild)
		p->Render();
}
