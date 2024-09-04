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

void Obstacle::SetCollisionRect()
{
	rect.left	= pos.x - halfSize;
	rect.right	= pos.x + halfSize;
	rect.top	= pos.y - HEIGHT_HALF_SIZE + 10;
	rect.bottom = pos.y + HEIGHT_HALF_SIZE - 10;
}

void Obstacle::Update(RECT rectView)
{
	// SetCollisionRect();
}

int Obstacle::Collision(GameObject& object)
{
	if (object.GetType() != EObjectType::Ball)
		return 0;

	// ball�� �ε����� 1�� �� �������� return
	if (clock() - object.GetCollisedTime() < 1000)
		return 0;

	if (IsCollised(object) == true)
	{
		object.SetReverseDirY();
		object.SetCollisedTime(clock());
		level--;
		if (level <= 0)
		{
			// ������� �� ��� true�� ����
			return -1;
		}
		// �װ� �ƴϰ� �Ϲ� �浹�̸� 1
		else return 1;
	}
	return 0;
}

int Obstacle::GetLevel()
{
	return level;
}
