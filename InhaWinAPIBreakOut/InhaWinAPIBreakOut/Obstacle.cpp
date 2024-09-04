#include "Obstacle.h"

void Obstacle::Draw(HDC& hdc)
{
	static HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 100, 100));

	switch (level)
	{
	case 1:
		hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 100, 100));
		break;
	case 2:
		hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 200, 100));
		break;
	case 3:
		hBrush = (HBRUSH)CreateSolidBrush(RGB(135, 206, 235));
		break;
	case 4:
		hBrush = (HBRUSH)CreateSolidBrush(RGB(218, 192, 255));
		break;
	}

	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc, pos.x - halfSize, pos.y - HEIGHT_HALF_SIZE, pos.x + halfSize, pos.y + HEIGHT_HALF_SIZE);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
}

void Obstacle::Update(RECT rectView)
{
	SetCollisionRect();
}

void Obstacle::Collision(GameObject& object)
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
