#pragma once
#include "framework.h"
#include "GameObject.h"
#include <math.h>


class Ball : public GameObject
{
private:
	float	speed;
	float	radius;

public:
	Ball(POINT pos, int radius);
	virtual void	SetCollisionRect();

	void		Draw(HDC& hdc) override;
	void		Update(RECT rectView) override;
	int			Collision(GameObject& object) override;

	void		MoveTo(RECT rectView);
};

