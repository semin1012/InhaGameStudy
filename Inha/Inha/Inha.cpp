#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <limits>
using namespace std;

/*
Q1. p.557 문제 5, 6
*/
// 문제 5번 
#define MAX 5
template<class T>
T max5(T nums[]);
template<class T>
void show(T nums[]);

// 문제 6번 
template<class T>
T maxn(T nums[], int n);
template<class T>
void shown(T nums[], int n);
template<>
const char* maxn<const char*>(const char* str[], int n);
template<>
void shown<const char*>(const char* str[], int n);

int main()
{
	int a[5] = { 0, 1, 2, 3, 4 };
	double b[5] = { 0.0, 1.1, 2.2, 3.3, 4.4 };

	// 5번
	cout << "5번\n";
	cout << "int형 배열: ";
	show(a);
	cout << "int형 배열의 최댓값: " << max5(a) << endl;
	cout << "double형 배열: ";
	show(b);
	cout << "double형 배열의 최댓값: " << max5(b) << endl << endl;

	// 6번
	cout << "6번\n";
	int a2[6] = { 0, 1, 2, 3, 4, 5 };
	double b2[4] = { 0.0, 1.1, 2.2, 3.3 };
	const char* c[5] = {"aa aa", "bb", "c", "ddd ddd", "eee"};

	cout << "a2(int)의 배열: ";
	shown(a2, 6);
	cout << "a2(int)의 최댓값: " << maxn(a2, 6) << endl;
	cout << "b2(double)의 배열: ";
	shown(b2, 4);
	cout << "b2(double)의 최댓값 : " << maxn(b2, 4) << endl;
	cout << "c(const char*)의 배열: ";
	shown(c, 5);
	cout << "c(const char*)의 가장 긴 문자열: " << maxn(c, 5) << endl;
}

template<class T>
T max5(T nums[])
{
	T max = nums[0];
	for (int i = 1; i < MAX; i++)
	{
		if (nums[i] > max)
			max = nums[i];
	}
	return max;
}

template<class T>
void show(T nums[])
{
	for (int i = 0; i < MAX; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

template<class T>
T maxn(T nums[], int n)
{
	T max = nums[0];
	for (int i = 1; i < n; i++)
	{
		if (nums[i] > max)
			max = nums[i];
	}
	return max;
}

template<class T>
void shown(T nums[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
}

template<>
const char* maxn<const char*>(const char* str[], int n)
{
	int max_len = 0;
	int max_idx = 0;
	for (int i = 0; i < n; i++)
	{
		if (strlen(str[i]) > max_len)
		{
			max_len = strlen(str[i]);
			max_idx = i;
		}
	}
	return str[max_idx];
}

template<>
void shown(const char* str[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << str[i] << " / ";
	}
	cout << endl;
}
