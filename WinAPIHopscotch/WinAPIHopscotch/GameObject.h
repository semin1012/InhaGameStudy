#pragma once
#include "framework.h"

enum class EGameObjectType
{
	Map = 0,
	Player
};

class GameObject
{
private:
	int				x;
	int				y;
	RECT			collisionBox;
	int				halfSize;
	EGameObjectType type;

public:
	GameObject(int x, int y, int halfSize, EGameObjectType type);

	virtual void	Update() = 0;
	virtual void	Draw(HDC hdc) = 0;
	virtual void	Collision() = 0;
	virtual void	CreateBitmap() = 0;

	void			SetX(int x);
	void			SetY(int y);
	int				GetX();
	int				GetY();
	void			SetCollisionBox();
	RECT			GetCollisionBox();
	void			SetHalfSize(int halfSize);
	int				GetHalfSize();
};

