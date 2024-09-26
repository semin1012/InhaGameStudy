#include "Node.h"

Node::Node()
{
    posX = 0;
    posY = 0;
    width = 0;
    height = 0;
    rect = { 0, 0, 0, 0 };
    g = -1;
    h = -1;
    f = -1;
}

Node::Node(int x, int y)
{
    this->posX = x;
    this->posY = y;
    g = -1;
    h = -1;
    f = -1;
    SetRectangle();
}

Node::Node(int x, int y, int width, int height)
{
    this->posX = x;
    this->posY = y;
    this->width = width;
    this->height = height;
    g = -1;
    h = -1;
    f = -1;
    SetRectangle();
}

void Node::SetWidth(int width)
{
    this->width = width;
}

void Node::SetHeight(int height)
{
    this->height = height;  
}

void Node::SetPosX(int x)
{
    this->posX = x;
}

void Node::SetPosY(int y)
{
    this->posY = y;
}

void Node::SetRectangle()
{
    rect = { posX, posY, posX + width, posY + height};
}

void Node::SetCost(int g, int h)
{
    this->g = g;
    this->h = h;
    this->f = g + h;
}

void Node::SetGCost(int g)
{
    this->g = g;
}

void Node::SetHCost(int h)
{
    this->h = h;
}

void Node::SetFCost(int f)
{
    this->f = f;
}

void Node::Draw(HDC& hdc)
{
    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
}

bool Node::IsOnClick(float x, float y)
{
    if (rect.right > x)   return false;
    if (rect.left < x)    return false;
    if (rect.top > y)     return false;
    if (rect.bottom < y)  return false;

    return true;
}

int Node::GetWidth()
{
    return this->width;
}

int Node::GetHeight()
{
    return this->height;
}

int Node::GetPosX()
{
    return this->posX;
}

int Node::GetPosY()
{
    return this->posY;
}

RECT Node::GetRectangle()
{
    return rect;
}

int Node::GetGCost()
{
    return this->g;
}

int Node::GetHCost()
{
    return this->h;
}

int Node::GetFCost()
{
    return this->f;
}
