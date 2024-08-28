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

// 0: 충돌, 1: 상대 삭제, -1: 나 삭제, 그 외: 충돌도 아님
int CObject::Collision(CObject& object, Mode mode)
{
    currentTime = clock();

    if (currentTime - startTime < 200)
        return 3;

    isCollided = false;

    switch (mode)
    {
    case Mode::Basic:
        if (CollisionInBasicMode(object))
            return 0;
        break;
    case Mode::Merge:
        if (pow(pos.x - object.pos.x, 2) + pow(pos.y - object.pos.y, 2) < pow(size + object.size, 2))
        {
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

            isCollided = true;
            object.isCollided = true;

            if (objectSize >= 13)
                return 1;
            objectSize++;
            size = objectSize * 10 + 20;
            startTime = clock();
            return 1;
        }
        break;
    case Mode::Decompose:
        break;
    }
    return 3;
}

BOOL CObject::CollisionInBasicMode(CObject& object)
{
    if (pow(pos.x - object.pos.x, 2) + pow(pos.y - object.pos.y, 2) < pow(size + object.size, 2))
    {
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
        isCollided = true;
        object.startTime = clock();
        object.isCollided = true;
    }
    return isCollided;
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

void CRect::Update(RECT& rectView)
{
    pos.x += dirX * speed;
    pos.y += dirY * speed;

    SetRectangle();
    CheckWindowCollision(rectView);
}

void CRect::Draw(HDC hdc)
{
    Polygon(hdc, point, 4);
    ct += 3;
    if (((int)ct) > 360 )
        ct = 0;
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
    float angle = 90;

    double tempSin = sin(angle);
    double tempCos = cos(angle);

    for (int i = 0; i < 4; i++)
    {
        point[i].x = cosf(degreeToRadian(angle * i) + ct) * this->size + pos.x;
        point[i].y = sinf(degreeToRadian(angle * i) + ct) * this->size + pos.y;
    }
}                                             
                                              
void CStar::Update(RECT& rectView)
{
    pos.x += dirX * speed;
    pos.y += dirY * speed;

    UpdateToPoint();
    CheckWindowCollision(rectView);
}

void CStar::Draw(HDC hdc)
{
    Polygon(hdc, pts, 6);
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
