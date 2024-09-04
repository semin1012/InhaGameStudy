#include "GameObject.h"

void GameObject::SetCollisionRect()
{
	rect.left	= pos.x - halfSize;
	rect.right	= pos.x + halfSize;
	rect.top	= pos.y - halfSize;
	rect.bottom = pos.y + halfSize;
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
