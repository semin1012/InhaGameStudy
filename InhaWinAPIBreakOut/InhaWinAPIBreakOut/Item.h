#pragma once
#include "GameObject.h"
#include "framework.h"

class Item : public GameObject
{
private:
	int			speed;

public:
	Item(POINT pos, int halfSize);
	void Draw(HDC& hdc) override;
	void Update(RECT rectView) override;
	int Collision(GameObject& object) override;

	void SetCollisionRect() override;
	void MoveTo(RECT rectView);
};

