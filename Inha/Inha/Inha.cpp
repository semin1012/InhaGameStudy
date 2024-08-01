#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <math.h>
#include <limits>
#include <iomanip>
#include <cmath>
using namespace std;

/*
Q1. 두 개의 원에 대해 중심점 좌표와 반지름을 입력받아
	두 번째 원이 첫 번째 원의 내부에 있는지
	첫 번째 원과 겹치는지를 결정하는 프로그램을 작성하라.
	
	ex>
	첫 번째 원 x,y,r: 0.5 5.1 13
	두 번째 원 x,y,r: 1 1.7 4.5
	두 번째 원은 첫 번째 원의 내부에 있다. 

Q2. 두 직사각형에 대해 중심점 (x,y), 폭 w, 높이 h를 입력받아
	두 번째 직사각형이 첫 번째 직사각형의 내부에 있는지,
	첫 번째 직사각형과 겹치는지를 결정하는 프로그램을 작성하라. 
	ex>
	첫 번째 사각형 x,y,w,h: 1 2 3 5.5
	두 번째 사각형 x,y,w,h: 3 4 4.5 5
	>> 두 번째 사각형은 첫 번째 사각형과 겹쳤다.
	ex 2>
	...
	>> 내부에 있다.
	ex 3>
	...
	>> 겹치지 않는다. 

Q3. 동전을 백만 번 던지는 것을 시뮬레이션 하고
	앞면과 뒷면이 나오는 수를 출력하는 프로그램을 작성하라. 
	다음과 같이 각각 앞뒤삭 몇 %씩 나오는지 계산해 출력하라.
	ex> 
		100			번째일 때 ... 앞면 00 % 뒷면 00 %
		1'000		번째일 때 ... 앞면 00 % 뒷면 00 %
		10'000		번째일 때 ... 앞면 00 % 뒷면 00 %
		100'000		번째일 때 ... 앞면 00 % 뒷면 00 %
		1'000'000	번째일 때 ... 앞면 00 % 뒷면 00 %

Q4. 아이템 목록이 다음과 같을 때
	등급		아이템		확률		아이템		확률
	-----------------------------------------------------
	5star		A-Item		1%
	-----------------------------------------------------
	4star		B-Item		3%			C-Item		 3%
	-----------------------------------------------------
	3star		D-Item		5%			E-Item		 5%
				F-Item		5%
	-----------------------------------------------------
	2star		G-Item		10%			H-Item		10%
				I-Item		10%			J-Item		10%
	-----------------------------------------------------
	1star		K-Item		38%
	-----------------------------------------------------
	각 아이템이 지정된 확률에 맞게 정확히 나올 수 있도록 프로그램을 작성하시오.
	ex> 횟수 ? 100		A : 1, B : 3, C : 3, D : 5 .....................
		횟수 ? 1000		A : 10, B : 30, C : 30, D : 50 .................
*/

#define ITEM_COUNT	11

struct Item
{
	char type;
	int count = 0;
};

const int itemPercent[ITEM_COUNT] = { 1, 3, 3, 5, 5, 5, 10, 10, 10, 10, 38 };

void setItemPercentage(int item[]);

int main()
{
	int item[100];
	int idx = 0;
	int rand_num;
	int unit = 100;
	Item itemCnt[ITEM_COUNT] = { {'A', 0},{'B', 0},{'C', 0},{'D', 0},{'E', 0},{'F', 0},{'G', 0},{'H', 0},{'I', 0},{'J', 0},{'K', 0}};
	
	setItemPercentage(item);

	for (int i = 1; i <= 1'000'000; i++)
	{
		while (1)
		{
			rand_num = rand() % 100;
			if (item[rand_num] != 99)	// 이미 뽑힌 공간이 아니라면 랜덤 돌리는 거 그만함
				break;
		}

		itemCnt[item[rand_num]].count++;
		item[rand_num] = 99;			// 이미 뽑힌 공간이라는 의미로 99 넣음

		if (i % 100 == 0) setItemPercentage(item);

		if (i == unit)
		{
			cout << "횟수 " << std::left << setw(7) << i << "  A: " << itemCnt[0].count << "  B: " << itemCnt[1].count <<
				"  C: " << itemCnt[2].count << "  D: " << itemCnt[3].count << "  E: " << itemCnt[4].count << "  F: " << itemCnt[5].count << 
				"  G: " << itemCnt[6].count << "  H: " << itemCnt[7].count << "  I: " << itemCnt[8].count << "  J: " << itemCnt[9].count << 
				"  K: " << itemCnt[10].count << endl;
			unit *= 10;
		}
	}
}

void setItemPercentage(int item[])
{
	int idx = 0;
	for (int i = 0; i < ITEM_COUNT; i++)
	{
		for (int j = 0; j < itemPercent[i]; j++)
		{
			item[idx++] = i;
		}
	}
}



/*
int main()
{
	srand(time(NULL));

	int front = 0, back = 0;
	bool randNum;
	int unit = 100;

	for (int i = 1; i <= 1'000'000; i++)
	{
		randNum = rand() % 2;
		if (randNum == 1) front++;
		else back++;
		if (i == unit)
		{
			//cout << front << " , " << back << endl;
			cout << setw(6) << i << "번째일 때 앞면 " << (front / (float)unit) * 100 << " %  뒷면 " << (back/(float)unit)*100 << "%\n";
			unit *= 10;
		}
	}
}
*/
