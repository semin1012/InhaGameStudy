#pragma once
#include "GameObject.h"
#include "framework.h"

enum class EItemType
{
	PlusBallCount,
	AttachBall,
	Length
};

class Item : public GameObject
{
private:
	EItemType type;

public:
	Item(POINT pos, int halfSize, EObjectType type)
	void Draw(HDC& hdc) override;
	void Update(RECT rectView) override;
	int Collision(GameObject& object) override;
};

