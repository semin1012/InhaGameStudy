#pragma once
#include "framework.h"
#include "GameObject.h"
#include "Ball.h"
#include "Item.h"
#include "time.h"

class Player : public GameObject
{
private:
	int			speed;
	int			ballCount;
	bool		isDeath;
	int			gameScore;
	clock_t		attackDelayTime;
	bool		canHasBall;
	GameObject*	attachBall;

public:
	Player(POINT pos, int halfSize, int speed) : GameObject(pos, halfSize, EObjectType::Player), speed(speed)
	{
		SetCollisionRect();
		attachBall = NULL;
		ballCount = 1;
		isDeath = false;
		gameScore = 0;
		attackDelayTime = 0;
		canHasBall = false;
	}

	virtual void Draw(HDC& hdc);
	virtual void Update(RECT rectView);
	virtual int  Collision(Item& item);
	virtual int  Collision(GameObject& object);
	virtual void SetCollisionRect();

	Ball*	Attack();
	int		GetSpeed();
	void	SetSpeed(int speed);
	void	MoveTo(RECT rectView, POINT pos);
	void	SetBallCount(int maxCount);
	int		GetBallCount();
	void	AddScore(int value);
	virtual int GetScore();
};

