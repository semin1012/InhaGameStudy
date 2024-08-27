#include "framework.h"
#include <random>
#include "CObject.h"

void CCircle::Update(RECT& rectView)
{
    pos.x += dirX * speed;
    pos.y += dirY * speed;
    CheckWindowCollision(rectView);
}

void CCircle::Draw(HDC hdc)
{
    Ellipse(hdc, pos.x - size, pos.y - size, pos.x + size, pos.y + size);
}

BOOL CCircle::Collision(CObject& object)
{
    switch (object.objectType)
    {
    case ObjectType::Circle:
        if (pow(pos.x - object.pos.x, 2) + pow(pos.y - object.pos.y, 2) < pow(size + object.size, 2))
        {
            float tempDirX, tempDirY;
            tempDirX = dirX, tempDirY = dirY;
            dirX = object.dirX, dirY = object.dirY;
            object.dirX = tempDirX, object.dirY = tempDirY;
            return true;
        }
        break;
    }

    return false;
}

void CCircle::CheckCircleCollision(CObject& circle)
{
}

void CRect::Update(RECT& rectView)
{
}

void CRect::Draw(HDC hdc)
{
}

BOOL CRect::Collision(CObject& object)
{
	return 0;
}

void CRect::SetRectangle()
{
    rect.left   = pos.x - size / 2;
    rect.right  = pos.x + size / 2;
    rect.top    = pos.y - size / 2;
    rect.bottom = pos.y + size / 2;
}

void CStar::Update(RECT& rectView)
{
}

void CStar::Draw(HDC hdc)
{
}

BOOL CStar::Collision(CObject& object)
{
	return 0;
}

void CObject::CheckWindowCollision(RECT& rectView)
{
    if (pos.x + size > rectView.right)
    {
        dirX *= -1;
        pos.x = rectView.right - size;
    }
    if (pos.x - size < rectView.left)
    {
        dirX *= -1;
        pos.x = rectView.left + size;
    }
    if (dirX == 0) dirX = 0.1;

    if (pos.y + size > rectView.bottom)
    {
        dirY *= -1;
        pos.y = rectView.bottom - size;
    }
    if (pos.y - size < rectView.top)
    {
        dirY *= -1;
        pos.y = rectView.top + size;
    }
    if (dirY == 0) dirY = 0.1;
}
