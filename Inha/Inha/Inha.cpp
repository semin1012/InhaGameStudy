#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

/*
// p.406 Listing 07.8
const int ArSize = 8;
int sum_arr(const int* begin, const int* end);
int main()
{
	int cookies[ArSize] = { 1, 2, 4, 8, 16, 32, 64, 128 };

	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "먹은 과자 수 합계: " << sum << endl;
	sum = sum_arr(cookies, cookies + 3);
	cout << "처음 세 사람은 과자 " << sum << "개를 먹었습니다.\n";
	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "마지막 네 사람은 과자 " << sum << "개를 먹었습니다.\n";	// 과자 240개 너무하는거아님?
	
	return 0;
}

int sum_arr(const int* begin, const int* end)
{
	const int* pt;
	int total = 0;

	for (pt = begin; pt != end; pt++)
		total = total + *pt;
	
	return total;
}
*/

// case 1. 함수 포인터로 하고 싶은 동작 변경하기
void (*update)(void);	// 함수 포인터로 쓰면 하고 싶은 내용 변경시키기 유용하다
void lobby();
void menu();

int main()
{
	update = menu;
	while (1)
		update();
	update = lobby;
}

void lobby()
{
	update = menu;
}

void menu()
{
	update = lobby;
}

/*
// case 2. switch-case 문으로 하고 싶은 동작 변경하기
int main()
{
	int select;
	switch (select)
	{
	case 1:
		menu();
		break;
	case 2:
		lobby();
		break;
	}
}
*/