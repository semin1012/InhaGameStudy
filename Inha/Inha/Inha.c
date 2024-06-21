#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Q3. 학생의 전체 평균 점수에 대한 학점을 출력하는 프로그램을 
	작성하라.
	성적이 90 이상 A, 성적이 80 이상 B,
	성적이 70 이상 C, 성적이 60 이상 D,
	그 미만은 F로 처리한다.
	
	프로그램 실행시 국어, 영어, 수학의 점수를 입력 받는다.
	그 평균을 구하고, 위 평가 기준을 참고하여 적절한 학점을
	출력하라. */

int main()
{
	int a, b, c;
	printf("국어, 영어, 수학의 점수를 입력하세요: ");
	scanf("%d%d%d", &a, &b, &c);
	double avg = (double)(a + b + c) / 3;
	if (avg >= 90)
		printf("평균: %.1lf, 성적: A\n", avg);
	else if ( avg >= 80 )
		printf("평균: %.1lf, 성적: B\n", avg);
	else if ( avg >= 70 )
		printf("평균: %.1lf, 성적: C\n", avg);
	else if ( avg >= 60)
		printf("평균: %.1lf, 성적: D\n", avg);
	else
		printf("평균: %.1lf, 성적: F\n", avg);
}