#pragma once
#include "GameObject.h"

class Obstacle : public GameObject
{
private:
	int		level;

public:
	Obstacle(POINT pos, int halfSize, int level) : GameObject(pos, halfSize, EObjectType::Obstacle), level(level)
	{
		SetCollisionRect();
		SetScore(level * 10);
	}
	
	virtual void Draw(HDC& hdc) override;
	virtual void Update(RECT rectView) override;
	virtual int  Collision(GameObject& object) override;
	
	void	SetCollisionRect();
	int		GetLevel();
};