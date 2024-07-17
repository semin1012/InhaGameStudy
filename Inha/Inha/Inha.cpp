#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

/*
Q2. p.42, 17, 18
    
    Q.17
         * * * * *
           * * *
             *
           * * *
         * * * * *
    Q.18
         1 1 1 1 1
           2 2 2
             3
           2 2 2
         1 1 1 1 1

*/

void spira(int n)
{
    int a = n / 2;
    for (int i = 0; i < n; i++)
    {
        int temp = abs((n / a * i / 2) - n /2 );
        for (int j = 0; j < n / 2 - temp; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < (n - ( n / 2 - temp) * 2); j++ )
        {
            cout << "* ";
        }
        cout << "\n";
    }
}

void nrpira(int n)
{
    int a = n / 2;
    for (int i = 0; i < n; i++)
    {
        int temp = abs((n / a * i / 2) - n / 2);
        for (int j = 0; j < n / 2 - temp; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < (n - (n / 2 - temp) * 2); j++)
        {
            cout << temp + 1 << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    cout << " > n을 입력하세요: ";
    cin >> n;
    
    spira(n);

    nrpira(n);
}