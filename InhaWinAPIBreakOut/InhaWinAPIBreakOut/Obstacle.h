#pragma once
#include "GameObject.h"

class Obstacle : public GameObject
{
private:
	int		score;
	int		level;

public:
	Obstacle(POINT pos, int halfSize, int score, int level) : GameObject(pos, halfSize, EObjectType::Obstacle), score(score), level(level)
	{
		SetCollisionRect();
	}
	
	virtual void Draw(HDC hdc, HBRUSH hBrush) override;
	virtual void Update() override;
	virtual void Collision() override;
	
	int		GetScore();
	int		GetLevel();
};