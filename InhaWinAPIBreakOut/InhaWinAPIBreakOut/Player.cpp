#include "Player.h"

void Player::Draw(HDC& hdc)
{
	HBRUSH hBrush;
	hBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectObject(hdc, hBrush);
	Rectangle(hdc, pos.x - halfSize, pos.y - HEIGHT_HALF_SIZE, pos.x + halfSize, pos.y + HEIGHT_HALF_SIZE);
	DeleteObject(hBrush);
}

void Player::Update(RECT rectView)
{
	SetCollisionRect();
}

void Player::Collision(GameObject& object)
{
}

Ball* Player::Attack()
{
	if (useBallCount < maxBallCount)
	{
		useBallCount++;
		Ball* attackBall = new Ball({ pos.x, pos.y - HEIGHT_HALF_SIZE * 2}, 40);
		return attackBall;
	}

	return NULL;

}

int Player::GetSpeed()
{
	return speed;
}

void Player::SetSpeed(int speed)
{
	this->speed = speed;
}

void Player::MoveTo(RECT rectView, POINT pos)
{
	if (pos.y == 0)
	{
		if (this->pos.x + halfSize + pos.x > rectView.right)
			return;
		if (this->pos.x - halfSize + pos.x < rectView.left)
			return;
	}
	
	else 
	{
		if (this->pos.y + HEIGHT_HALF_SIZE + pos.y > rectView.bottom)
			return;
		if (this->pos.y + HEIGHT_HALF_SIZE + pos.y < 500)
			return;
	}

	this->pos.x += pos.x;
	this->pos.y += pos.y;
}

void Player::SetMaxBallCount(int maxCount)
{
	this->maxBallCount = maxCount;
}
