#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <array>
using namespace std;

struct POS
{
    double x, y;
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

enum class Mode
{
    Basic,
    Merge,
    Decompose
};

struct Vector2D {
    double x;
    double y;

    Vector2D operator+(const Vector2D& other) const {
        return { x + other.x, y + other.y };
    }

    Vector2D operator-(const Vector2D& other) const {
        return { x - other.x, y - other.y };
    }

    Vector2D operator*(double scalar) const {
        return { x * scalar, y * scalar };
    }

    // 내적 계산
    double dot(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    // 벡터의 크기 계산
    double norm() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2D normalize() const {
        double n = norm();
        if (n == 0) return { 0, 0 }; 
        return { x / n, y / n };
    }

    // 벡터의 각도 계산 (라디안)
    double angle() const {
        return std::atan2(y, x);
    }
};

class CObject
{
public:
    Vector2D vec;
    POS pos;
    float speed;
    float rad;
    float dirX, dirY;
    ObjectType objectType;
    int size;
    float m;
    clock_t startTime; 
    clock_t currentTime;
    bool isCollided = false;

public:
    CObject(POS pos, float speed, float rad, ObjectType type, int size) : pos(pos), speed(speed), rad(rad), objectType(type), size(size)
    {
        this->size = size * 10 + 20;
        this->speed = speed;
        dirX = cos(rad);
        dirY = sin(rad);
        m = size / (float)10 - 30;
        vec.x = dirX;
        vec.y = dirY;
        startTime = clock();
        currentTime = clock();
    };
    virtual void Update(RECT& rectView) = 0;        // 좌표 갱신
    virtual void Draw(HDC hdc) = 0;                 // 그리기
    virtual BOOL Collision(CObject& object, Mode mode);        // 충돌
    void CheckWindowCollision(RECT& rectView);
    std::pair<Vector2D, Vector2D> calculateReflectionAngle(CObject& v2, double m1, double m2);

    float degreeToRadian(float de)
    {
        return de * 3.141592 / 180.0f;
    }
};

class CCircle : public CObject
{
protected:
public: 
    CCircle(POS pos, float speed, float rad, ObjectType type, int sizeNum) : CObject(pos, speed, rad, type, sizeNum) {   }
    void Update(RECT& rectView) override;
    void Draw(HDC hdc) override;
};

struct Point
{
    double x, y;
};

class CRect : public CObject
{
private:
    RECT rect;
    float ct = 90;
    POINT point[4];
public:
    CRect(POS pos, float speed, float rad, ObjectType type, int size) : CObject(pos, speed, rad, type, size)
    {
        SetRectangle();
    };
    void Update(RECT& rectView) override;
    void Draw(HDC hdc) override;

    void SetRectangle();
};



class CStar : public CObject
{
private:
    POINT pts[6] = {};
    float ct = 90;
    const double PI = 3.141592;

public:
    CStar(POS pos, float speed, float rad, ObjectType type, int size) : CObject(pos, speed, rad, type, size) 
    {
        UpdateToPoint();
    };

    void Update(RECT& rectView) override;
    void Draw(HDC hdc) override;
    void UpdateToPoint()
    {
        for (int i = 0; i < 6; i++)
        {
            pts[i].x = cosf(degreeToRadian(ct + 144 * i)) * this->size + pos.x;
            pts[i].y = sinf(degreeToRadian(ct + 144 * i)) * this->size + pos.y;
        }

        ct += 3.0f;
    }
};