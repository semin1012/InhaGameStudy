#pragma once
#include "framework.h"
#define HEIGHT_HALF_SIZE 10

enum class EObjectType
{
	Player = 0,
	Obstacle,
	Ball
};

class GameObject
{
protected:
	POINT		pos;
	RECT		rect;
	int			halfSize;
	EObjectType type;

public:
	GameObject(POINT pos, int halfSize, EObjectType type) : pos(pos), halfSize(halfSize), type(type)
	{
		SetCollisionRect();
	}

	virtual void	Draw(HDC hdc, HBRUSH hBrush) = 0;
	virtual void	Update() = 0;
	virtual void	Collision() = 0;
	virtual void	SetCollisionRect();

	POINT		GetPos();
	int			GetSize();
	void		SetPos(POINT pos);
	void		SetHalfSize(int size);
	EObjectType GetType();
};

