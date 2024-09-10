#include "GameObject.h"

GameObject::GameObject(int x, int y, int halfSize, EGameObjectType type) : x(x), y(y), halfSize(halfSize), type(type)
{
    SetCollisionBox();
}

void GameObject::SetX(int x)
{
    this->x = x;
}

void GameObject::SetY(int y)
{
    this->y = y;
}

int GameObject::GetX()
{
    return x;
}

int GameObject::GetY()
{
    return y;
}

void GameObject::SetCollisionBox()
{
    collisionBox.left   = x - halfSize;
    collisionBox.right  = x + halfSize;
    collisionBox.top    = y - halfSize;
    collisionBox.bottom = y + halfSize;
}

RECT GameObject::GetCollisionBox()
{
    return collisionBox;
}

void GameObject::SetHalfSize(int halfSize)
{
    this->halfSize = halfSize;
}

int GameObject::GetHalfSize()
{
    return halfSize;
}
