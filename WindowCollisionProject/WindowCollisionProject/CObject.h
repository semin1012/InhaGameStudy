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




struct Vector2D {
    double x;
    double y;

    // ���� ����
    Vector2D operator+(const Vector2D& other) const {
        return { x + other.x, y + other.y };
    }

    // ���� ����
    Vector2D operator-(const Vector2D& other) const {
        return { x - other.x, y - other.y };
    }

    // ��Į�� ����
    Vector2D operator*(double scalar) const {
        return { x * scalar, y * scalar };
    }

    // ���� ���
    double dot(const Vector2D& other) const {
        return x * other.x + y * other.y;
    }

    // ������ ũ�� ���
    double norm() const {
        return std::sqrt(x * x + y * y);
    }

    // ���͸� ����ȭ
    Vector2D normalize() const {
        double n = norm();
        if (n == 0) return { 0, 0 };  // ���� ����� ����
        return { x / n, y / n };
    }

    // ������ ���� ��� (����)
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
    virtual void Update(RECT& rectView) = 0;       // ��ǥ ����
    virtual void Draw(HDC hdc) = 0;         // �׸���
    virtual BOOL Collision(CObject& object);    // �浹
    void CheckWindowCollision(RECT& rectView);
    std::pair<Vector2D, Vector2D> calculateReflectionAngle(CObject& v2, double m1, double m2);
};

class CCircle : public CObject
{
protected:
public: 
    CCircle(POS pos, float speed, float rad, ObjectType type, int sizeNum) : CObject(pos, speed, rad, type, sizeNum) {   }
    void Update(RECT& rectView) override;
    void Draw(HDC hdc) override;
    //BOOL Collision(CObject& object) override;
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
    //BOOL Collision(CObject& object) override;

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
   // BOOL Collision(CObject& object) override;
};