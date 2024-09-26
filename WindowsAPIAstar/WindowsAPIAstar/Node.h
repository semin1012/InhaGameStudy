#pragma once
#include "framework.h"

class Node
{
private:
	int			width;
	int			height;
	RECT		rect;

	int			g = -1;
	int			h = -1;
	int			f = -1;

public:
	Node();
	Node(int width, int height);

	void		SetWidth(int width);
	void		SetHeight(int height);
	void		SetRectangle();
	void		SetCost(int g, int h);
	void		SetGCost(int g);
	void		SetHCost(int h);
	void		SetFCost(int f);

	int			GetWidth();
	int			GetHeight();
	RECT		GetRectangle();
	int			GetGCost();
	int			GetHCost();
	int			GetFCost();
};

