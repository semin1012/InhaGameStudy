#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
Q1. 학교에 100개의 사물함과 100명의 학생이 있다.
	모든 사물함이 첫날에는 닫혀 있다.
	학생이 교실로 들어가면서
		s1이라는 첫번째 학생은 모든 사물함을 연다.
		s2라는 두번째 학생은 L2부터 시작하여 1개씩 건너뛰면서 사물함을 닫는다.
		s3라는 세번째 학생은 L3부터 시작하여 2개씩 건너뛰면서 사물함의 상태를 변경한다. 
		( 열림 <-> 닫힘 )
		...
	학생 s100이 L100 사물함을 변경할 때까지 계속된다. 
	모든 학생이 교실을 통과하고 난 다음, 어떤 사물함이 열려있는지 
	열려있는 모든 사물함의 번호를 출력하는 프로그램을 작성하라.
*/

#define COUNT 100

bool SetLocker(bool locker);
void PrintLocker(bool locker[]);

int main()
{
	bool locker[100] = { 0 };		// false는 닫힘, true는 열림 

	for (int i = 0; i < COUNT; i++)
	{
		for (int j = i; j < COUNT; j += (i + 1)) 
			locker[j] = SetLocker(locker[j]);
	}

	PrintLocker(locker);
}

bool SetLocker(bool locker)
{
	if (locker == false)
		return true;
	return false;
}

void PrintLocker(bool locker[])
{
	for (int i = 0; i < COUNT; i++)
	{
		if (locker[i] == true) cout << i+1<< endl;
	}
}
