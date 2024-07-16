#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int max4(int a, int b, int c, int d)
{
    int max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    if (max < d) max = d;
    return max;
}

int main()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;
    
    int max = max4(a, b, c, d);
    cout << "max: " << max << endl;
}