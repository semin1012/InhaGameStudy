#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

/*
// P.514 Listing 08.10
unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n = 1);

int main() 
{
	char* trip = new char[9];
	strcpy(trip, "Hawaii!!");
	// 위의 두 줄을 
	// const char* trip = "Hawaii!!"; // 라고 써도 됨
	unsigned long n = 12345678;
	int i;
	char* temp;
	for (i = 1; i < 10; i++)
	{
		cout << left(n, i) << endl;
		temp = left(trip, i);
		cout << temp << endl;
		delete[] temp;
	}
	return 0;
}

unsigned long left(unsigned long num, unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;

	if (ct == 0 || num == 0)
		return 0;
	while (n /= 10)
		digits++;
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;
	}
	else return num;
}

char* left(const char* str, int n)
{
	if (n < 0)
		n = 0;
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; i++)
		p[i] = str[i];
	while (i <= n)
		p[i++] = '\0';
	return p;
}
*/
/*
// p.520 Listing 08.11
template <class T>
void Swap(T& a, T& b);
template <class T>
void Swap(T a[], T b[], int n);
void Show(int a[]);
const int Lim = 8;

int main()
{
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "컴파일러가 생성한 int형 교환기를 사용하면\n";
	Swap(i, j);
	cout << "이제 i, j = " << i << ", " << j << ".\n";

	int d1[Lim] = { 0, 7, 0, 4, 1, 7, 7, 6 };
	int d2[Lim] = { 0, 6, 2, 0, 1, 9, 6, 9};

	cout << "원본 배열: \n";
	Show(d1);
	Show(d2);
	Swap(d1, d2, Lim);
	cout << "교환된 배열: \n";
	Show(d1);
	Show(d2);
	return 0;
}

template<class T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<class T>
void Swap(T a[], T b[], int n)
{
	T temp;
	for (int i = 0; i < n; i++)
	{
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void Show(int a[])
{
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim; i++)
		cout << a[i];
	cout << endl;
}
*/
/*
// p.542 listing 08.15
template <class T>
T lesser(T a, T b)
{
	return a < b ? a : b;
}

int lesser(int a, int b)
{
	a = a < 0 ? -a : a;
	b = b < 0 ? -b : b;
	return a < b ? a : b;
}

int main()
{
	int m = 20;
	int n = -30;
	double x = 15.5;
	double y = 25.9;

	cout << lesser(m, n) << endl;
	cout << lesser(x, y) << endl;
	cout << lesser<>(m, n) << endl;
	cout << lesser<int>(x, y) << endl;
}
*/