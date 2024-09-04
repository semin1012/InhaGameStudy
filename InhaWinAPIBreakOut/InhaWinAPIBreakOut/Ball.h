#pragma once
#include "framework.h"
#include "GameObject.h"
#include <math.h>


class Ball : public GameObject
{
private:
	float speed = 3;
	float dirX;
	float dirY;
	float radius = 10;

public:
	Ball(POINT pos, int halfSize);
	virtual void	SetCollisionRect();

	void Draw(HDC& hdc) override;
	void Update(RECT rectView) override;
	void Collision(GameObject& object) override;

	void MoveTo(RECT rectView);
};

