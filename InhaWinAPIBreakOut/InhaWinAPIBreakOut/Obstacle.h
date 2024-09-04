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
	virtual bool Collision(GameObject& object) override;
	
	void	SetCollisionRect();
	int		GetScore();
	int		GetLevel();
};