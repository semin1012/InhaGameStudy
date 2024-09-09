#pragma once
#include "framework.h"
#include "GameObject.h"

class Player : public GameObject
{
	float		speed;


public:
	Player(int x, int y, int halfSize);

	void		Update() override;
	void		Draw(HDC hdc) override;
	void		Collision() override;

	void		MoveTo(RECT& rectView, int x, int y);
};