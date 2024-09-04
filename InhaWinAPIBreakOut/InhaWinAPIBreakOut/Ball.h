#pragma once
#include "framework.h"
#include "GameObject.h"
#include <math.h>


class Ball : public GameObject
{
private:
	float speed = 2;
	float radius = 10;

public:
	Ball(POINT pos, int radius);
	virtual void	SetCollisionRect();

	void Draw(HDC& hdc) override;
	void Update(RECT rectView) override;
	bool Collision(GameObject& object) override;

	void MoveTo(RECT rectView);
};

