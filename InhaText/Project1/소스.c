#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <crtdbg.h>		// 메모리 릭이 일어났는지 확인하기 위함

/*
Q1. p.540 성적 처리 프로그램
	학번, 이름, 학점(국/영/수)을 입력받을 수 있는
	구조체를 만들고, 임의 수의 학생에 대한 데이터를 입력받아
	출력하는 프로그램을 작성하라.
	다음 4개의 메뉴를 구성하고, 각 메뉴의 선택시 작동은 다음과 같다.

	1. 입력 - 학번, 이름, 성적 순으로 입력
	2. 출력 - 성적(평균)에 따라 (정렬된 형태로) 출력
	3. 검색 - 이름으로 해당 학생의 학점, 성적을 출력
	4. 종료
	조건>
		1. 번호 중복 불가, 이름은 중복 가능
		2. 검색 -> 이름 검색으로 하고 먼저 찾은 것을 우선 출력
		3. 메모리 할당 활용, 자기 참조 구조체 활용
		4. 입력/출력/검색은 각각 개별 함수로 구현한다.

p.582 도전 실전 예제
	단어 검출 프로그램 작성

Q3. 구구단 출력 -> 99.txt
	원하는 구구단을 찾아 출력하는 프로그램을 작성하라.
	= fseek() 이용
	ex>
		99.txt ( 구구단 정보가 저장된 파일 )
		2 x 1 = 2 ...

		출력을 원하는 구구단은 ? 3
		3 x 1 = 3 ...
*/

#define MAX_LENGTH 15

int main()
{
	// 구구단 저장하는 파일 만들기
	FILE* ofp = NULL;
	char buffer[MAX_LENGTH + 1] = {0};
	int n = 0;
	ofp = fopen("99.txt", "wt");

	if (ofp == NULL) {
		printf("파일 읽기 실패\n");
		return 0;
	}

	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			fprintf(ofp, "%2d × %2d = %2d\n", i, j, i * j);
		}
		fprintf(ofp, "\n");
	}

	fclose(ofp);

	// 구구단 저장 파일 불러와서 출력하기
	ofp = fopen("99.txt", "rt");

	printf("출력을 원하는 구구단은?\n> ");
	scanf("%d", &n);


	// + 2 * (n-2)를 하는 이유는 2칸짜리 엔터가 n-2번만큼 더 들어가기 때문
	fseek(ofp, (15 * (n-2) * 9 + 2 * (n-2)), SEEK_SET);

	for (int i = 0; i < 9; i++) {
		fgets(buffer, MAX_LENGTH, ofp);
		printf("%s", buffer);
	}

	fclose(ofp);
}