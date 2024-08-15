#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "StopWatch.h"
using namespace std;

/*
Q1. StopWatch class 설계
	다음의 내용을 포함하는 클래스를 설계하라.
	- get 함수를 갖는 데이터 필드 startTime과 endTime
	- startTime을 현재 시간으로 초기화하는 인수 없는 생성자
	- startTime을 현재 시간으로 재설정하는 start() 함수
	- endTime을 현재 시간으로 설정하는 stop() 함수
	- 스톱워치의 경과 시간을 밀리초(milliseconds)로 반환하는 
	  getElpasedTime() 함수
	- UML 클래스 다이어그램 작성
*/

vector<int> top[3];

int Factorial(int n)
{
	if (n == 1)
		return 1;
	int j = n * Factorial(n - 1);
	return j;
}

void print_top(int num)
{
	vector<int> temptop[3] = { top[0], top[1], top[2] };

	cout << "==============\n";

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (temptop[j].size() > 0 && i >= num - top[j].size())
			{
				printf("[%2d] ", temptop[j].back());
				temptop[j].pop_back();
			}
			else
			{
				printf("[%2d] ", 0);
			}
		}
		cout << '\n';
	}
	cout << '\n';
}


void Hanoi_top(int n, int from, int temp, int to, int num)
{
	static int i = 0;

	if (n == 0)
		return;

	Hanoi_top(n - 1, from, to, temp, num);

	i++;
	top[to - 1].push_back(top[from - 1].back());
	top[from - 1].pop_back();

	cout << i << "번째 이동\n";
	print_top(num);

	Hanoi_top(n - 1, temp, from, to, num);
}

int main()
{
	StopWatch watch;
	watch.start();


	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		top[0].push_back(i + 1);
	}


	print_top(n);
	Hanoi_top(n, 1, 2, 3, n);


	watch.stop();

	cout  << "시간: " << watch.getElpasedTime() << " ms" << endl;
}