#pragma once
#include "framework.h"
#include "GameObject.h"
class Ball : public GameObject
{
private:
	float speed = 1;
	float dirX;
	float dirY;
	float radius = 10;

public:
	Ball(POINT pos, int halfSize, float dirX, float dirY) : GameObject(pos, halfSize, EObjectType::Ball), dirX(dirX), dirY(dirY)
	{
		SetCollisionRect();
	}

	virtual void	SetCollisionRect();

	void Draw(HDC hdc, HBRUSH hBrush) override;
	void Update() override;
	void Collision() override;
};

