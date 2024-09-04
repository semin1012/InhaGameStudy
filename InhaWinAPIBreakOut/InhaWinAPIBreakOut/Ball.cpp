#include "Ball.h"

Ball::Ball(POINT pos, int radius) : GameObject(pos, radius, EObjectType::Ball), radius(radius)
{
	SetCollisionRect();
	this->dirX = cos((rand() % 90 + 45) * 3.141592 / 180) * 10;
	this->dirY = sin((rand() % 90 + 180) * 3.141592 / 180) * 10;
}

void Ball::SetCollisionRect()
{
	rect.left	= pos.x - radius - 7;
	rect.right	= pos.x + radius + 7;
	rect.top	= pos.y - radius - 7;
	rect.bottom = pos.y + radius + 7;
}

void Ball::Draw(HDC& hdc)
{
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 200, 200));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	
	Ellipse(hdc, pos.x - radius, pos.y - radius, pos.x + radius, pos.y + radius);

	SelectObject(hdc, oldBrush);
	DeleteObject(hBrush);
}

void Ball::Update(RECT rectView)
{
	MoveTo(rectView);
	SetCollisionRect();
}

bool Ball::Collision(GameObject& object)
{
	return false;
}

void Ball::MoveTo(RECT rectView)
{
	if (this->pos.x + radius + speed * dirX > rectView.right)
	{
		dirX *= -1;
		return;
	}
	if (this->pos.x - radius + speed * dirX < rectView.left)
	{
		dirX *= -1;
		return;
	}
	if (this->pos.y + radius + speed * dirY > rectView.bottom)
	{
		dirY *= -1;
		return;
	}
	if (this->pos.y - radius + speed * dirY < rectView.top)
	{
		dirY *= -1;
		return;
	}

	pos.x += speed * dirX;
	pos.y += speed * dirY;
	return;
}
