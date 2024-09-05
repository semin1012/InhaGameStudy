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
	rect.left	= pos.x - halfSize;
	rect.right	= pos.x + halfSize;
	rect.top	= pos.y - HEIGHT_HALF_SIZE - 5;
	rect.bottom = pos.y + HEIGHT_HALF_SIZE + 5;
}

int Player::Collision(GameObject& object)
{
	if (object.GetType() == EObjectType::Obstacle)
		return 0;

	// ballÀÌ ºÎµúÈùÁö 1ÃÊ ¾È Áö³µÀ¸¸é return
	if (clock() - object.GetCollisedTime() < 500)
		return 0;

	switch (object.GetType())
	{
	case EObjectType::Ball:
		if (IsCollised(object) == true)
		{
			if (canHasBall == true && attachBall == NULL)
			{
				attachBall = &object;
				attachBall->SetAttach(true);
				ballCount++;
				canHasBall = false;
			}

			else {
				object.SetReverseDirY();
				object.SetCollisedTime(clock());
			}
		}
		break;
	case EObjectType::Item:
		if (IsCollised(object) == true)
		{
			object.SetCollisedTime(clock());

			switch (object.GetItemType())
			{
			case EItemType::PlusBallCount:
				ballCount++;
				break;
			case EItemType::AttachBall:
				canHasBall = true;
				break;
			case EItemType::Length:
				halfSize += 10;
				break;
			}

			return 1;
		}
		break;
	}
	return 0;
}

int Player::Collision(Item& item)
{
	// ballÀÌ ºÎµúÈùÁö 1ÃÊ ¾È Áö³µÀ¸¸é return
	if (clock() - item.GetCollisedTime() < 1000)
		return 0;

	if (IsCollised(item) == true)
	{
		item.SetCollisedTime(clock());
		return 1;
	}

	return 0;
}

Ball* Player::Attack()
{
	if (ballCount > 0)
	{
		if (clock() - attackDelayTime < 1000)
			return NULL;

		if (attachBall != NULL)
		{
			attachBall->SetPos({ this->pos.x, this->pos.y - HEIGHT_HALF_SIZE * 2 - 30 });
			attachBall->SetReverseDirY();
			attachBall->SetAttach(false);
			attachBall->SetCollisedTime(clock());
			attachBall = NULL;
			ballCount--;
			attackDelayTime = clock();
			return NULL;
		}
		else
		{
			ballCount--;
			Ball* attackBall = new Ball({ pos.x, pos.y - HEIGHT_HALF_SIZE * 2 - 20 }, 10);
			attackDelayTime = clock();
			return attackBall;
		}
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

	if (attachBall != NULL)
	{
		attachBall->SetPos({this->pos.x, this->pos.y - HEIGHT_HALF_SIZE * 2});
	}
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
