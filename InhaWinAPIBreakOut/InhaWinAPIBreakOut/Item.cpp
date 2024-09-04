#include "Item.h"

Item::Item(POINT pos, int halfSize, EObjectType type) : GameObject(pos, halfSize, type)
{
    int random = rand() % 3;
    speed = rand() % 5 + 7;

    switch (random)
    {
    case 0:
        itemType = EItemType::PlusBallCount;
        break;
    case 1:
        itemType = EItemType::AttachBall;
        break;
    case 2:
        itemType = EItemType::Length;
        break;
    default:
        itemType = EItemType::None;
        break;
    }
}

void Item::Draw(HDC& hdc)
{
    static HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 100, 100));

    switch (itemType)
    {
    case EItemType::PlusBallCount:
        hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 100));
        break;
    case EItemType::AttachBall:
        hBrush = (HBRUSH)CreateSolidBrush(RGB(100, 255, 255));
        break;
    case EItemType::Length:
        hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 100, 255));
        break;
    }

    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

    Ellipse(hdc, pos.x - halfSize - 3, pos.y - halfSize - 3, pos.x + halfSize + 3, pos.y + halfSize + 3);
    Ellipse(hdc, pos.x - halfSize, pos.y - halfSize, pos.x + halfSize, pos.y + halfSize);

    SelectObject(hdc, oldBrush);
    DeleteObject(hBrush);
}

void Item::Update(RECT rectView)
{
    SetCollisionRect();
    MoveTo();
}

void Item::SetCollisionRect()
{
    rect.left   = pos.x - halfSize - 7;
    rect.right  = pos.x + halfSize + 7;
    rect.top    = pos.y - halfSize - 7;
    rect.bottom = pos.y + halfSize + 7;
}

void Item::MoveTo()
{
    pos.y += speed;
}

int Item::Collision(GameObject& object)
{
    return 0;
}
