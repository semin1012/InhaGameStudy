#pragma once
#include "cCubePNT.h"

class cCubeNode : public cCubePNT
{
public:
	cCubeNode();
	virtual ~cCubeNode();

protected:
	D3DXVECTOR3				m_vLocalPos;		// 부모와 나와의 관계
	D3DXMATRIXA16			m_matLocalTM;		// 부모와 나와의 관계
	D3DXMATRIXA16			m_matWorldTM;		// real world에 적용되는 것, 최종적인 Matrix
	std::vector<cCubeNode*>	m_vecChild;

	Synthesize(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM);
	Synthesize(float, m_fRotDeltaX, RotDeltaX);

	float					m_fRotX;

public:
	virtual void AddChild(cCubeNode* pChild);
	virtual void Destroy();

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;
};

