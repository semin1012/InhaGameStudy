#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int med3(int a, int b, int c)
{
    if (a >= b && a >= c)
    {
        if (b > c)
            return b;
        else return c;
    }
    else if (b >= a && b >= c)
    {
        if (a > c)
            return a;
        else return c;
    }
    else
    {
        if (a > b)
            return a;
        else return b;
    }
}

int main()
{
    int a, b, c;
    cout << "세 정수를 입력하세요: ";
    cin >> a >> b >> c;

    int med = med3(a, b, c);
    cout << "중앙값: " << med << endl;
}