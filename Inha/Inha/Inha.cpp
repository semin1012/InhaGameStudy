#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

/**/
// p.465 Q.10
#define OPTION_NUM 2

double add(double x, double y);
double sub(double x, double y);
double calculate(double x, double y, double (*option)(double, double));

int main()
{
	double x, y;
	double (*options[OPTION_NUM])(double, double) = { add, sub };

	cout << "> x, y 입력: ";
	cin >> x >> y;

	for (int i = 0; i < OPTION_NUM; i++)
	{
		cout << calculate(x, y, options[i]) << endl;
	}
}

double add(double x, double y)
{
	cout << "x + y: ";
	return x + y;
}

double sub(double x, double y)
{
	cout << "x - y: ";
	return x - y;
}

double calculate(double x, double y, double(*option)(double, double))
{
	return option(x, y);
}
