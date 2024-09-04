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
	
	virtual void Draw(HDC& hdc) override;
	virtual void Update(RECT rectView) override;
	virtual void Collision(GameObject& object) override;
	
	int		GetScore();
	int		GetLevel();
};