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

#define MAX_WORD_SIZE 80

FILE* openFile(FILE* file, char fileName[], char mode[]);		// 파일 읽기 성공/실패 출력하려고 만듬
char** readWordListInFile(FILE* file, int* count, int* size, char** res, char buffer[]);	// 파일에서 단어 목록 읽어오는 함수
void inputWords(FILE* ofp, FILE* cfp, char buffer[], int* count, char** res);		// 파일에 단어 입력하는 함수

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	FILE* ifp = NULL, * ofp = NULL, * cfp = NULL;
	int size = 2;
	int count = 0;
	char buffer[MAX_WORD_SIZE] = { 0 };
	char** res = (char**)calloc(size, sizeof(char*));


	// 단어 파일 불러오기
	ifp = openFile(ifp, "a.txt", "rt");
	// 단어 파일의 단어 목록을 읽어서 res에 저장해두기
	res = readWordListInFile(ifp, &count, &size, res, buffer);
	fclose(ifp);
	
	
	ofp = openFile(ofp, "b.txt", "wt");		// 입력하는 단어를 저장할 파일 열기
	cfp = openFile(cfp, "c.txt", "wt");		//  겹치지 않는 단어만 저장할 파일 열기
	// 파일에 입력한 단어 저장하기
	inputWords(ofp, cfp, buffer, &count, res);

	// 동적할당 해제
	for (int i = 0; i < count; i++)
	{
		free(res[i]);
	}

	free(res);
	fclose(ofp);
	fclose(cfp);

	_CrtDumpMemoryLeaks();
}


FILE* openFile(FILE* file, char fileName[], char mode[])
{
	file = fopen(fileName, mode);
	if (file == NULL)
	{
		printf("\"%s\" 파일 읽기 실패\n", fileName);
		exit(0);	// 실패하면 프로그램 종료
	}
	printf("\"%s\" 파일 읽기 성공!\n", fileName);
	return file;
}

char** readWordListInFile(FILE* file, int* count, int* size, char** res, char buffer[])
{
	while (fgets((buffer), sizeof(buffer), file))
	{
		if ((*count) == (*size))
		{
			*size += 5;
			res = (char**)realloc(res, (*size) * sizeof(char*));
			printf("size 변경, 현재 size : %d\n", *size);
		}

		buffer[strlen(buffer) - 1] = '\0';
		res[*count] = (char*)calloc(sizeof(char), strlen(buffer) + 1);
		strcpy(res[*count], buffer);
		//printf("%s\n", buffer);
		(*count)++;
		_strset(buffer, '\0');
	}

	return res;
}

void inputWords(FILE* ofp, FILE* cfp, char buffer[], int* count, char** res)
{
	printf("\n단어를 입력하세요. quit 입력 시 종료합니다.\n\n");

	while (1)
	{
		_strset(buffer, '\0');

		printf("> ");
		scanf("%s", buffer);


		if (strcmp(buffer, "quit") == 0)
			return;

		// res에 저장된 단어랑 중복되는지 확인
		bool duplicate = false;
		for (int i = 0; i < (*count); i++)
		{
			if (strcmp(res[i], buffer) == 0) {
				duplicate = true;
			}
		}

		buffer[strlen(buffer)] = '\n';
		buffer[strlen(buffer)+1] = '\0';

		// 중복되지 않으면 c.txt에 저장
		if (duplicate == false)
		{
			fprintf(cfp, "%s", buffer);
		}
		// 입력된 단어 모두 b.txt에 저장
		fprintf(ofp, "%s", buffer);

	}
}