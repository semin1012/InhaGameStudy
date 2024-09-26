#pragma once
#include "framework.h"
#define RECT_WIDTH 50;
#define RECT_HEIGHT 50;

class Node
{
private:
	int			posX, posY;
	int	width	= RECT_WIDTH;
	int	height	= RECT_HEIGHT;
	RECT		rect;

	int			g;
	int			h;
	int			f;

public:
	Node();
	Node(int x, int y);
	Node(int x, int y, int width, int height);

	void		SetWidth(int width);
	void		SetHeight(int height);
	void		SetPosX(int x);
	void		SetPosY(int y);
	void		SetRectangle();
	void		SetCost(int g, int h);
	void		SetGCost(int g);
	void		SetHCost(int h);
	void		SetFCost(int f);

	void		Draw(HDC& hdc);
	bool		IsOnClick(float x, float y);

	int			GetWidth();
	int			GetHeight();
	int			GetPosX();
	int			GetPosY();
	RECT		GetRectangle();
	int			GetGCost();
	int			GetHCost();
	int			GetFCost();
};

