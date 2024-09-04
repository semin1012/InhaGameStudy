#include "Ball.h"

void Ball::SetCollisionRect()
{
	rect.left	= pos.x - radius;
	rect.right	= pos.x + radius;
	rect.top	= pos.y - radius;
	rect.bottom = pos.y + radius;
}

void Ball::Draw(HDC hdc, HBRUSH hBrush)
{

}

void Ball::Update()
{
}

void Ball::Collision()
{
}
