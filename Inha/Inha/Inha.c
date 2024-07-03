#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)

/*
Q1. 야구 게임
	세 개의 숫자를 입력 받아서 다음과 같이 숫자가 있지만
	그 위치가 틀렸을 때는 "ball"을 출력하고 
	숫자와 위치가 맞으면 "strike"를 출력한다. 
	숫자와 위치가 다 틀리면 "out"을 출력하도록 한다.
	무엇이 볼이고 스트라이크인지는 출력하지 않는다.
	세 개의 숫자와 위치가 다 맞으면 "homerun"을 표시하고 게임을
	끝낸다.

	ex> 정답: 2 1 6 ( 보여지면 안 됨 + 중복 불가 )
	1 > 8 3 5 -> out
	2 > 6 5 9 -> 0s 1b (6이 있으나 위치가 달라 ball)
	3 > 2 6 4 -> 1s 1b (2의 위치가 맞으나 6은 위치가 다름)
	4 > 2 1 6 -> HR 

*/

#define MAX 3

void setNumbers(int* correct);
void printNumbers(int* arr);
int getStrike(int* correct, int* arr);
int getBall(int* correct, int* arr);
int getResult(int strike, int ball);

int main()
{
	srand(time(NULL));	// 난수 
	int correct[MAX];

	setNumbers(correct);
	printNumbers(correct);

	int answerCnt = 1;
	int answer[MAX];
	int strike = 0, ball = 0;

	while (1)
	{
		printf("%d > ", answerCnt);
		for (int i = 0; i < MAX; i++)
			scanf("%d", &answer[i]);

		printf("-> ");

		strike = getStrike(correct, answer);
		ball = getBall(correct, answer);

		if (getResult(strike, ball) == -1)
			return 0;

		answerCnt++;
	}
}

// 정답 난수 생성
void setNumbers(int* correct) 
{
	for (int i = 0; i < MAX; i++) {
		int random = rand() % 9 + 1;
		bool duplication = false;
		for (int j = 0; j < MAX; j++) {
			if (random == *(correct+j)) {
				duplication = true;
				break;
			}
		}
		if (duplication == true) i--;
		else *(correct+i) = random;
	}
}

// 정답 출력 (편의용)
void printNumbers(int* arr)
{
	for (int i = 0; i < MAX; i++) {
		printf("%d ", *(arr+i));
	}
	printf("\n\n");
}

// strike 개수 리턴
int getStrike(int* correct, int* arr)
{
	int strike = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (*(correct + i) == *(arr + i))
			strike++;
	}
	return strike;
}

// ball 개수 리턴
int getBall(int* correct, int* arr)
{
	int ball = 0;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (i == j)
				continue;
			if (*(correct + i) == *(arr + j))
				ball++;
		}
	}
	return ball;
}

// 결과 출력 및 Homerun 여부 리턴 (홈런일 경우 -1 리턴)
int getResult(int strike, int ball)
{
	if (strike == 0 && ball == 0)
	{
		printf("out\n\n");
		return 0;
	}

	if (strike == MAX)
	{
		printf("HR\n");
		return -1;
	}

	printf("%ds %db\n\n", strike, ball);
	return 0;
}