#include "Obstacle.h"

void Obstacle::Draw(HDC hdc, HBRUSH hBrush)
{
	switch (level)
	{
	case 1:
		hBrush = CreateSolidBrush(RGB(255, 100, 100));
		break;
	case 2:
		hBrush = CreateSolidBrush(RGB(255, 200, 100));
		break;
	case 3:
		hBrush = CreateSolidBrush(RGB(135, 206, 235));
		break;
	case 4:
		hBrush = CreateSolidBrush(RGB(218, 192, 255));
		break;
	}
	SelectObject(hdc, hBrush);
	Rectangle(hdc, pos.x - halfSize, pos.y - HEIGHT_HALF_SIZE, pos.x + halfSize, pos.y + HEIGHT_HALF_SIZE);
}

void Obstacle::Update()
{
	SetCollisionRect();
}

void Obstacle::Collision()
{
}

int Obstacle::GetScore()
{
	return score;
}

int Obstacle::GetLevel()
{
	return level;
}
