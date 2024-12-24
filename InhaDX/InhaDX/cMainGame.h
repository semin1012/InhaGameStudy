#pragma once
class cMainGame
{
private:
	std::vector<ST_PC_VERTEX> m_vecLineVertext;
	std::vector<ST_PC_VERTEX> m_vecTriangleVertex;

public:
	cMainGame();
	~cMainGame();

public:
	void Setup_Line();
	void Setup_Triangle();

	void Draw_Line();
	void Draw_Triangle();

	void SetUp();
	void Update();
	void Render();
};

