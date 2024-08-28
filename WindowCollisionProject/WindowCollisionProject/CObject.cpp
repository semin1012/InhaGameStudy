#include "framework.h"
#include <random>
#include "CObject.h"
#include <time.h>



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

BOOL CObject::Collision(CObject& object)
{
    currentTime = clock();

    if (currentTime - startTime < 500)
        return false;

    if (pow(pos.x - object.pos.x, 2) + pow(pos.y - object.pos.y, 2) < pow(size + object.size, 2))
    {
        //std::pair<Vector2D, Vector2D> v = calculateReflectionAngle(object, 1, 1);

        //// 충돌 후 각도 계산
        //double angle_v1_new = v.first.angle() * 180 / 3.141592;
        //double angle_v2_new = v.second.angle() * 180 / 3.141592;

        //dirX = cos(angle_v1_new);
        //dirY = sin(angle_v1_new);

        //object.dirX = cos(angle_v2_new);
        //object.dirY = sin(angle_v2_new);

        float tempDirX = dirX, tempDirY = dirY;
        dirX = object.dirX, dirY = object.dirY;
        object.dirX = tempDirY, object.dirY = tempDirY;

        vec.x = dirX;
        vec.y = dirY;

        object.vec.x = object.dirX;
        object.vec.y = object.dirY;

        pos.x = pos.x - vec.normalize().x * 5;
        pos.y = pos.y - vec.normalize().y * 5;
        object.pos.x = object.pos.x - vec.normalize().x * 5;
        object.pos.y = object.pos.y - vec.normalize().y * 5;

        startTime = clock();
        return true;
    }

    return false;
}

std::pair<Vector2D, Vector2D> CObject::calculateReflectionAngle(CObject& v2, double m1, double m2)
{
    // 속도 차이
    Vector2D relative_velocity = v2.vec - vec;

    // 법선 벡터 계산
    Vector2D normal_vector = relative_velocity.normalize();

    // 물체 A의 새로운 속도 (탄성 충돌 가정)
    Vector2D v1_new = vec - normal_vector * (2 * m2 / (m1 + m2)) * relative_velocity.dot(normal_vector);

    // 물체 B의 새로운 속도 (탄성 충돌 가정)
    Vector2D v2_new = v2.vec - normal_vector * (2 * m1 / (m1 + m2)) * relative_velocity.dot(normal_vector);

    // 충돌 후 위치 조정
    Vector2D displacement_vector = normal_vector * 5;
    pos.x = pos.x + displacement_vector.x;
    pos.y = pos.y + displacement_vector.y;
    v2.pos.x = v2.pos.x + displacement_vector.x;
    v2.pos.y = v2.pos.y + displacement_vector.y;

    return { v1_new, v2_new };
}

void CCircle::CheckCircleCollision(CObject& circle)
{
}

void CRect::Update(RECT& rectView)
{
    pos.x += dirX * speed;
    pos.y += dirY * speed;

    SetRectangle();
    CheckWindowCollision(rectView);
}

void CRect::Draw(HDC hdc)
{
    Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
}

//BOOL CRect::Collision(CObject& object)
//{
//    currentTime = clock();
//
//    if (currentTime - startTime < 500)
//        return false;
//    if (pow(pos.x - object.pos.x, 2) + pow(pos.y - object.pos.y, 2) < pow(size + object.size, 2))
//    {
//        //std::pair<Vector2D, Vector2D> v = calculateReflectionAngle(object, 1, 1);
//
//        //// 충돌 후 각도 계산
//        //double angle_v1_new = v.first.angle() * 180 / 3.141592;
//        //double angle_v2_new = v.second.angle() * 180 / 3.141592;
//
//        //dirX = cos(angle_v1_new);
//        //dirY = sin(angle_v1_new);
//
//        //object.dirX = cos(angle_v2_new);
//        //object.dirY = sin(angle_v2_new);
//
//
//        float tempDirX = dirX, tempDirY = dirY;
//        dirX = object.dirX, dirY = object.dirY;
//        object.dirX = tempDirY, object.dirY = tempDirY;
//
//
//        vec.x = dirX;
//        vec.y = dirY;
//
//        object.vec.x = object.dirX;
//        object.vec.y = object.dirY;
//
//        startTime = clock();
//        return true;
//    }
//
//    return false;
//}

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
