#define _CRT_SECURE_NO_WARNINGS
/*
*/
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

/*
Q1. 삼각형의 3개의 점 (x1, y1), (x2, y2), (x3, y3)를 알고 있을 때
	이 삼각형의 면적을 구하는 프로그램을 작성하라.
	ex > 세 점 입력: 1.5 -3.4 4.6 5 9.5 -3.4 (순서대로 x1,y1~x3,y3)
		 삼각형의 면적: 33.6

		 헤론의 공식 적용

struct POINT
{
	float x, y;
};

int main()
{
	POINT t1, t2, t3;
	float length1, length2, length3, s, a;

	cout << "> 세 점 입력: ";
	cin >> t1.x >> t1.y >> t2.x >> t2.y >> t3.x >> t3.y;

	length1 = sqrt(pow(t2.x - t1.x, 2) + pow(t2.y - t1.y, 2));
	length2 = sqrt(pow(t3.x - t2.x, 2) + pow(t3.y - t2.y, 2));
	length3 = sqrt(pow(t1.x - t3.x, 2) + pow(t1.y - t3.y, 2));

	s = (length1 + length2 + length3) / 2;
	a = sqrt(s * (s - length1) * (s - length2) * (s - length3));
	cout << "삼각형의 면적: " << a << endl;
}
*/

/*
Q2. 게임에서 비밀번호에 어떤 규칙을 요구하는 경우가 있다.
	다음과 같이 비밀번호를 만들어야 한다고 하자.
	1. 비밀번호는 적어도 8개의 문자여야 한다.
	2. 비밀번호는 문자와 숫자로만 구성되어야 한다.
	3. 비밀번호는 적어도 두 개의 숫자가 포함되어야 한다.
	사용자가 비밀번호를 입력했을 때
	위 규칙에 맞으면 "Valid Password"를 출력하고
	그렇지 않으면 "Invalid Password"를 출력하라. 
	isAlpha 이런 거 써도 된다. 
*/

int main()
{
	string password;
	int numCnt;
	bool isValid = true;
	while (1)
	{
		cout << "> password: ";
		cin >> password;
		numCnt = 0;
		isValid = true;

		if (password.length() < 8)
		{
			cout << "#Invalid Password: 비밀번호는 적어도 8개의 문자여야 합니다.\n\n";
			isValid = false;
			continue;
		}

		
		for (auto c : password)
		{
			if (!isalnum(c))
			{
				cout << "#Invalid Password: 비밀번호는 문자와 숫자로만 구성되어야 합니다.\n\n";
				isValid = false;
				break;
			}

			if (isdigit(c)) numCnt++;
		}

		if (numCnt < 2)
		{
			cout << "#Invalid Password: 비밀번호는 적어도 두 개의 숫자가 포함되어야 합니다.\n\n";
			isValid = false;
			continue;
		}

		if (isValid == false) continue;

		cout << "Valid Password\n";
		return 0;
	}
}