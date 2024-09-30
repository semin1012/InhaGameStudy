#include "Node.h"
#include <string>

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
    type = ENodeType::Basic;
}

Node::Node(int x, int y)
{
    this->posX = x;
    this->posY = y;
    g = -1;
    h = -1;
    f = -1;
    type = ENodeType::Basic;
    SetRectangle();
}

Node::Node(int x, int y, int width, int height, int indexX, int indexY)
{
    this->posX = x;
    this->posY = y;
    this->width = width;
    this->height = height;
    this->indexX = indexX;
    this->indexY = indexY;
    type = ENodeType::Basic;
    g = -1;
    h = -1;
    f = -1;
    SetRectangle();
}

void Node::Initialize()
{
    type = ENodeType::Basic;
    g = -1;
    f = -1;
    h = -1;
}

void Node::SetParent(std::pair<int, int> parent)
{
    this->parent = parent;
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
    SetFCost();
}

void Node::SetHCost(int h)
{
    this->h = h;
    SetFCost();
}

void Node::SetFCost(int f)
{
    this->f = f;
}

void Node::SetFCost()
{
    f = g + h;
}

void Node::SetIndexX(int x)
{
    indexX = x;
}

void Node::SetIndexY(int y)
{
    indexY = y;
}

void Node::SetNodeType(ENodeType type)
{
    this->type = type;
}

std::wstring s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

void Node::Draw(HDC& hdc)
{
    static HBRUSH hBrush;
    
    switch (type)
    {
    case ENodeType::Basic:
        hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 255));
        break;
    case ENodeType::StartPoint:
        hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 100, 100));
        break;
    case ENodeType::EndPoint:
        hBrush = (HBRUSH)CreateSolidBrush(RGB(100, 100, 255));
        break;
    case ENodeType::Obstacle:
        hBrush = (HBRUSH)CreateSolidBrush(RGB(150, 150, 150));
        break;
    case ENodeType::Road:
        hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 100));
        break;
    }

    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hBrush);
    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
    SelectObject(hdc, oldBrush);
    DeleteObject(hBrush);

    // g
    std::wstring temp = s2ws(std::to_string(g));
    LPCWSTR text = temp.c_str();
    TextOut(hdc, rect.left + 1, rect.top + 1, text, _tcslen(text));

    // h
    temp = s2ws(std::to_string(h));
    text = temp.c_str();
    TextOut(hdc, rect.left + 30, rect.top + 1, text, _tcslen(text));

    // f
    temp = s2ws(std::to_string(f));
    text = temp.c_str();
    TextOut(hdc, rect.left + 18, rect.top + 30, text, _tcslen(text));
}

bool Node::IsOnClick(float x, float y)
{
    if (rect.right < x)   return false;
    if (rect.left > x)    return false;
    if (rect.top > y)     return false;
    if (rect.bottom < y)  return false;

    return true;
}

std::pair<int, int> Node::GetParent()
{
    return parent;
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

int Node::GetIndexX()
{
    return indexX;
}

int Node::GetIndexY()
{
    return indexY;
}

ENodeType Node::GetNodeType()
{
    return type;
}
