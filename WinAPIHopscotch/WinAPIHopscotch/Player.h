#pragma once
#include "GameObject.h"

class Player : public GameObject
{
	float		speed;


public:
	Player(int x, int y);
};

