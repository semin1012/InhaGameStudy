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

	virtual void	Draw(HDC& hdc) = 0;
	virtual void	Update(RECT rectView) = 0;
	virtual void	Collision(GameObject& object) = 0;
	virtual void	SetCollisionRect();

	POINT		GetPos();
	int			GetSize();
	void		SetPos(POINT pos);
	void		SetHalfSize(int size);
	EObjectType GetType();
};

