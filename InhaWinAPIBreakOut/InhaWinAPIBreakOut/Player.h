#pragma once
#include "framework.h"
#include "GameObject.h"
#include "Ball.h"
#include "time.h"

class Player : public GameObject
{
private:
	int		speed;
	int		maxBallCount = 0;
	int		useBallCount = 0;

public:
	Player(POINT pos, int halfSize, int speed) : GameObject(pos, halfSize, EObjectType::Player), speed(speed)
	{
		SetCollisionRect();
	}

	virtual void Draw(HDC hdc, HBRUSH hBrush);
	virtual void Update();
	virtual void Collision();
	
	Ball*	Attack();

	int		GetSpeed();
	void	SetSpeed(int speed);
	void	MoveTo(RECT rectView, POINT pos);
	void	SetMaxBallCount(int maxCount);
};

