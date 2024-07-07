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

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	FILE* ifp, * ofp;

	int size = 14;
	int count = 0;

	char buffer[100];

	char** res = (char**)calloc(size, sizeof(char));

	ifp = fopen("a.txt", "rt");
	if (ifp == NULL) {
		printf("등록 단어 파일 읽기 실패\n");
		return 1;
	}
	printf("등록 단어 파일 읽기 성공\n");

	while (fgets(buffer, sizeof(buffer), ifp))
	{
		buffer[strlen(buffer) - 1] = '\0';
		res[count] = (char*)malloc(101);
		strcpy(res[count], buffer);
		printf("입력: %s\n", buffer);
		count++;
	}

	res[count] = NULL;
	//count = 0;


	ofp = fopen("b.txt", "wt");
	if (ofp == NULL)
	{
		printf("입력 단어 파일 읽기 실패\n");
		return 1;
	}
	printf("입력 단어 파일 읽기 성공!\n");

	printf("\n단어를 입력하세요. quit 입력 시 종료합니다.\n\n");

	//while (1)
	//{
	//	printf("> ");
	//	scanf("%s", buffer);
	//	break;
	//	/*if (strcmp(buffer, "quit") == 0)
	//		break;*/
	//	
	//	//fscanf(ofp, "%s", buffer);
	//	//if (res[count] == NULL)
	//	//	break;
	//	//fprintf(ofp, "%s\n", res[count]);
	//	//printf("%s\n", res[count]);
	//	//count++;
	//}

	for (int i = 0; i < count; i++)
	{
		free(res[i]);
	}

	fclose(ifp);
	fclose(ofp);

	_CrtDumpMemoryLeaks();
}