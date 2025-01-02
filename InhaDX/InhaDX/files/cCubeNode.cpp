#include "framework.h"
#include "cCubeNode.h"

cCubeNode::cCubeNode()
	: m_fRotDeltaX(0.0f)
	, m_pParentWorldTM(NULL)
	, m_vLocalPos(0, 0, 0)
	, m_fRotX(0.0f)
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

	{	// 애니메이션
		m_fRotX += m_fRotDeltaX;
		if (m_fRotX > D3DX_PI / 6.0f)	// 30도만 회전
		{
			m_fRotX = D3DX_PI / 6.0f;
			m_fRotDeltaX *= -1;	// 방향 전환
		}

		if (m_fRotX < -D3DX_PI / 6.0f)	// 30도만 회전
		{
			m_fRotX = -D3DX_PI / 6.0f;
			m_fRotDeltaX *= -1;	// 방향 전환
		}
	}

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);

	D3DXMatrixRotationX(&matR, m_fRotX);	// 애니메이션 회전 값 적용시킴
	D3DXMatrixTranslation(&matT, m_vLocalPos.x, m_vLocalPos.y, m_vLocalPos.z);

	// : S x R x T 순서로 넣을 것
	m_matLocalTM = matR * matT;
	m_matWorldTM = m_matLocalTM;

	// 부모가 있다면 부모 것까지 계산해줌
	if (m_pParentWorldTM)
		m_matWorldTM *= *m_pParentWorldTM;

	// 자식이 있다면 자식한테도 계산해줌. 자식 Update를 부르면 계산이 될 것.
	for (auto p : m_vecChild)
	{
		p->Update();
	}
}

void cCubeNode::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorldTM);
	
	// 내 거를 그린 뒤 자식 것들 모두 그림
	cCubePNT::Render();
	for (auto p : m_vecChild)
		p->Render();
}
