#pragma once
class cGizmo;

class cGrid
{
public:
	cGrid();
	~cGrid();

private:
	std::vector<ST_PC_VERTEX>	m_vecVertex;
	std::vector<cGizmo*>		m_vecGizmo;

public:
	//Ÿ�� ����, ���� ����
	void Setup(int nNumHalfTile = 15, float fInterval = 0.2f);
	void Render();
};

