#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 자료구조 p.33 8번, 9번

int GaussAdd(int n)
{
    int sum;
    sum = (1 + n) * (n / 2);
    if (n % 2 != 0)
        sum += (n / 2) + 1;
    return sum;
}

int sumof(int a, int b)
{
    int sum = 0;
    for (int i = a; i <= b; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int n, n2;
    cout << "***** 가우스 덧셈 ***** " << endl;
    cout << "> n을 입력하세요: ";
    cin >> n;

    cout << "> 1부터 n까지의 합: " << GaussAdd(n) << endl << endl;


    cout << "***** sumof(int, int) ***** " << endl;
    cout << "> 1부터 n까지의 합: " << sumof(1, n) << endl << endl;
    cout << "> 정수 두 개를 입력하세요: ";
    cin >> n >> n2;
    cout << "> " << n << "부터 "<< n2 << "까지의 합 : " << sumof(n, n2) << endl;
}