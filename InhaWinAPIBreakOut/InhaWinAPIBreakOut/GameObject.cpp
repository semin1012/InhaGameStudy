#include "GameObject.h"

void GameObject::SetCollisionRect()
{
	rect.left	= pos.x - halfSize;
	rect.right	= pos.x + halfSize;
	rect.top	= pos.y - halfSize;
	rect.bottom = pos.y + halfSize;
}

RECT& GameObject::GetCollisionRect()
{
	return rect;
}

bool GameObject::IsCollised(GameObject& object)
{
	if (this->rect.left >= object.GetCollisionRect().right)
		return false;
	if (this->rect.right <= object.GetCollisionRect().left)
		return false;
	if (this->rect.top >= object.GetCollisionRect().bottom)
		return false;
	if (this->rect.bottom <= object.GetCollisionRect().top)
		return false;

	return true;
}

POINT GameObject::GetPos()
{
	return pos;
}

int GameObject::GetSize()
{
	return halfSize * 2;
}

void GameObject::SetPos(POINT pos)
{
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

void GameObject::SetHalfSize(int halfSize)
{
	this->halfSize = halfSize;
}

EObjectType GameObject::GetType()
{
	return type;
}

void GameObject::SetReverseDirY()
{
	dirY *= -1;
}

void GameObject::SetCollisedTime(clock_t time)
{
	collisedTime = time;
}

clock_t GameObject::GetCollisedTime()
{
	return collisedTime;
}

bool GameObject::GetIsOver()
{
	return isOver;
}

int GameObject::GetScore()
{
	return score;
}

void GameObject::SetScore(int score)
{
	this->score = score;
}
