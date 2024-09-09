#pragma once
#include "framework.h"

class GameObject
{
private:
	int			x;
	int			y;
	RECT		collisionBox;
	int			halfSize;

public:
	GameObject(int x, int y, int halfSize);

	virtual void	Update() = 0;
	virtual void	Draw(HDC hdc) = 0;
	virtual void	Collision() = 0;

	void			SetX(int x);
	void			setY(int y);
	int				GetX();
	int				GetY();
	void			SetCollisionBox();
	RECT			GetCollisionBox();
	void			SetHalfSize(int halfSize);
	int				GetHalfSize();
};

