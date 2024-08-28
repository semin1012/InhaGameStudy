#include <iostream>
#include <cmath>
#include <array>

// 2D 벡터를 표현하기 위한 구조체
struct Vector2D {
    double x;
    double y;

    // 벡터 덧셈
    Vector2D operator+(const Vector2D& other) const {
        return { x + other.x, y + other.y };
    }

    // 벡터 뺄셈
    Vector2D operator-(const Vector2D& other) const {
        return { x - other.x, y - other.y };
    }

    // 스칼라 곱셈
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

    // 벡터를 정규화
    Vector2D normalize() const {
        double n = norm();
        if (n == 0) return { 0, 0 };  // 제로 디비전 방지
        return { x / n, y / n };
    }

    // 벡터의 각도 계산 (라디안)
    double angle() const {
        return std::atan2(y, x);
    }
};

// 충돌 후 반사각을 계산하는 함수
std::pair<Vector2D, Vector2D> calculateReflectionAngle(const Vector2D& v1, const Vector2D& v2, double m1, double m2) {
    // 속도 차이
    Vector2D relative_velocity = v1 - v2;

    // 법선 벡터 계산
    Vector2D normal_vector = relative_velocity.normalize();

    // 물체 A의 새로운 속도 (탄성 충돌 가정)
    Vector2D v1_new = v1 - normal_vector * (2 * m2 / (m1 + m2)) * relative_velocity.dot(normal_vector);

    // 물체 B의 새로운 속도 (탄성 충돌 가정)
    Vector2D v2_new = v2 - normal_vector * (2 * m1 / (m1 + m2)) * relative_velocity.dot(normal_vector);

    return { v1_new, v2_new };
}

int main() {
    // 물체 A와 B의 초기 속도 및 질량
    Vector2D v1 = { 3, 4 };  // 물체 A의 속도 벡터
    Vector2D v2 = { -1, -1 };  // 물체 B의 속도 벡터
    double m1 = 2.0;  // 물체 A의 질량
    double m2 = 3.0;  // 물체 B의 질량

    std::cout << "물체 A의 충돌 후 반사각: " << v1.angle() << "도" << std::endl;
    std::cout << "물체 B의 충돌 후 반사각: " << v2.angle() << "도" << std::endl;

    // 충돌 후 속도 벡터 계산
    std::pair<Vector2D, Vector2D> v = calculateReflectionAngle(v1, v2, m1, m2);

    // 충돌 후 각도 계산
    double angle_v1_new = v.first.angle() * 180 / 3.141592;  // 라디안을 도(degree)로 변환
    double angle_v2_new = v.second.angle() * 180 / 3.141592;  // 라디안을 도(degree)로 변환

    std::cout << "물체 A의 충돌 후 반사각: " << angle_v1_new << "도" << std::endl;
    std::cout << "물체 B의 충돌 후 반사각: " << angle_v2_new << "도" << std::endl;

    return 0;
}