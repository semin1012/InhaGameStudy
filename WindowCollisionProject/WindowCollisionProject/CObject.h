#pragma once
#include <vector>
using namespace std;

struct POS
{
    int x, y;
};

enum ObjectType
{
    Circle = 0,
    Rect,
    Star
};

enum ObjectSize
{
    ExtraSmall = 1,
    Small ,
    Medium,
    Large ,
    ExtraLarge
};

class CObject
{
public:
    POS pos;
    float speed;
    float rad;
    float dirX, dirY;
    ObjectType objectType;
    int size;

public:
    CObject(POS pos, float speed, float rad, ObjectType type, int size) : pos(pos), speed(speed), rad(rad), objectType(type), size(size) 
    { 
        this->size = size * 10 + 30;
        this->speed = speed * 2;
        dirX = cos(rad);
        dirY = sin(rad);
    };
    virtual void Update(RECT &rectView) = 0;       // 좌표 갱신
    virtual void Draw(HDC hdc) = 0;         // 그리기
    virtual BOOL Collision(CObject& object) = 0;    // 충돌
    void CheckWindowCollision(RECT& rectView);
};

class CCircle : public CObject
{
protected:
public: 
    CCircle(POS pos, float speed, float rad, ObjectType type, int sizeNum) : CObject(pos, speed, rad, type, sizeNum) {   }
    void Update(RECT& rectView) override;
    void Draw(HDC hdc) override;
    BOOL Collision(CObject& object) override;
    void CheckCircleCollision(CObject& circle);
};

class CRect : public CObject
{
private:
    RECT rect;
public:
    CRect(POS pos, float speed, float rad, ObjectType type, int size) : CObject(pos, speed, rad, type, size)
    {
        SetRectangle();
    };

    void Update(RECT& rectView) override;
    void Draw(HDC hdc) override;
    BOOL Collision(CObject& object) override;

    void SetRectangle();
};

class CStar : public CObject
{
private:
private:
public:
    CStar(POS pos, float speed, float rad, ObjectType type, int size) : CObject(pos, speed, rad, type, size) {};

    void Update(RECT& rectView) override;
    void Draw(HDC hdc) override;
    BOOL Collision(CObject& object) override;
};