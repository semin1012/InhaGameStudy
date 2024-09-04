#pragma once
#include "framework.h"
#include "time.h"
#define HEIGHT_HALF_SIZE 10

enum class EObjectType
{
	Player = 0,
	Obstacle,
	Ball,
	Item
};

class GameObject
{
protected:
	POINT		pos;
	RECT		rect;
	int			halfSize;
	EObjectType type;
	float		dirX = 0;
	float		dirY = 0;
	clock_t		collisedTime = 0.0f;
	bool		isOver = false;
	int			score = 10;

public:
	GameObject(POINT pos, int halfSize, EObjectType type) : pos(pos), halfSize(halfSize), type(type)
	{
		SetCollisionRect();
	}

	virtual void	Draw(HDC& hdc) = 0;
	virtual void	Update(RECT rectView) = 0;
	virtual int		Collision(GameObject& object) = 0;
	virtual void	SetCollisionRect();
	virtual RECT&	GetCollisionRect();
	virtual bool	IsCollised(GameObject& object);

	POINT		GetPos();
	int			GetSize();
	void		SetPos(POINT pos);
	void		SetHalfSize(int size);
	EObjectType GetType();
	void		SetReverseDirY();
	void		SetCollisedTime(clock_t time);
	clock_t		GetCollisedTime();
	bool		GetIsOver();
	virtual int	GetScore();
	void		SetScore(int score);
};

