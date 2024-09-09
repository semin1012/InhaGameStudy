#include "Player.h"

Player::Player(int x, int y, int halfSize) : GameObject(x, y, halfSize)
{
	speed = 1;
}

void Player::MoveTo(RECT& rectView, int x, int y)
{
	int moveX = this->GetX() + speed * x;
	int moveY = this->GetY() + speed * y;

	if (moveX >= rectView.right)	return;
	if (moveX <= rectView.left)		return;
	if (moveY >= rectView.bottom)	return;
	if (moveY <= rectView.top)		return;

	this->SetX(moveX);
	this->setY(moveY);
}

void Player::Update()
{

}

void Player::Draw(HDC hdc)
{
	RECT pos = GetCollisionBox();
	Ellipse(hdc, pos.left, pos.top, pos.right, pos.bottom);
}

void Player::Collision()
{
}
