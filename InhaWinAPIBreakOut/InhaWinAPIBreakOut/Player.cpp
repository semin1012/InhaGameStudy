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

void Player::SetCollisionRect()
{
	rect.left = pos.x - halfSize;
	rect.right = pos.x + halfSize;
	rect.top = pos.y - HEIGHT_HALF_SIZE + 10;
	rect.bottom = pos.y + HEIGHT_HALF_SIZE - 10;
}

int Player::Collision(GameObject& object)
{
	if (object.GetType() == EObjectType::Obstacle)
		return 0;

	// ballÀÌ ºÎµúÈùÁö 1ÃÊ ¾È Áö³µÀ¸¸é return
	if (clock() - object.GetCollisedTime() < 1000)
		return 0;

	switch (object.GetType())
	{
	case EObjectType::Ball:
		if (IsCollised(object) == true)
		{
			object.SetReverseDirY();
			object.SetCollisedTime(clock());
		}
		break;
	}
	return 0;
}

Ball* Player::Attack()
{
	if (ballCount > 0)
	{
		ballCount--;
		Ball* attackBall = new Ball({ pos.x, pos.y - HEIGHT_HALF_SIZE * 2}, 10);
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

void Player::SetBallCount(int maxCount)
{
	this->ballCount = maxCount;
}

int Player::GetBallCount()
{
	return ballCount;
}

void Player::AddScore(int value)
{
	gameScore += value;
}

int Player::GetScore()
{
	return gameScore;
}
