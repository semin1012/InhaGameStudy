#pragma once
#include "framework.h"
#define RECT_WIDTH 50;
#define RECT_HEIGHT 50;

enum class ENodeType
{
	Basic,
	StartPoint,
	EndPoint,
	Obstacle,
	Road
};

class Node
{
private:
	int			posX, posY;
	int			width	= RECT_WIDTH;
	int			height	= RECT_HEIGHT;
	RECT		rect;
	int			indexX;
	int			indexY;
	ENodeType	type;

	int			g;
	int			h;
	int			f;
	std::pair<int, int>	parent;

public:

	Node();
	Node(int x, int y);
	Node(int x, int y, int width, int height, int indexX, int indexY);

	void		Initialize();

	void		SetParent(std::pair<int, int> parent);
	void		SetWidth(int width);
	void		SetHeight(int height);
	void		SetPosX(int x);
	void		SetPosY(int y);
	void		SetRectangle();
	void		SetCost(int g, int h);
	void		SetGCost(int g);
	void		SetHCost(int h);
	void		SetFCost(int f);
	void		SetFCost();
	void		SetIndexX(int x);
	void		SetIndexY(int y);
	void		SetNodeType(ENodeType type);

	void		Draw(HDC& hdc);
	bool		IsOnClick(float x, float y);
	
	std::pair<int, int> GetParent();
	int			GetWidth();
	int			GetHeight();
	int			GetPosX();
	int			GetPosY();
	RECT		GetRectangle();
	int			GetGCost();
	int			GetHCost();
	int			GetFCost();
	int			GetIndexX();
	int			GetIndexY();
	ENodeType	GetNodeType();
};

