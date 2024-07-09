#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <crtdbg.h>		// 메모리 릭이 일어났는지 확인하기 위함

/*
Q1. 파일 복사 프로그램 만들기
	복사할 파일명과 복사 후 생성되는 파일명을
	입력받아서 파일을 복사하는 프로그램을 작성하라.
	단, txt 파일 뿐만 아니라 이미지 파일 등...
	모든 종류의 파일에 다 동일하게 적용할 수 있어야
	한다.
	복사 진행 과정을 백분율로 화면에 표시해주도록
	하고 한번에 n 바이트씩 복사하도록 한다.
	ex > 4바이트
		원본파일: source.txt
		대상파일: dest.txt
*/

void gotoxy(int x, int y);

int main()
{
	char origin[80];
	char copy[80];

	char data[4];

	printf("원본 파일: ");
	scanf("%s", &origin);
	printf("대상 파일: ");
	scanf("%s", &copy);

	FILE* ofp, *cfp;
	ofp = fopen(origin, "rb");
	cfp = fopen(copy, "wb");
	
	fseek(ofp, 0, SEEK_END);

	int size = ftell(ofp);

	fseek(ofp, 0, SEEK_SET);

	int currentSize = 0;
	float printSize = 0.f;

	for (int i = 1;  i < (size / 4) + 1; i++) {
		fread(&data, sizeof(data), 1, ofp);
		fwrite(&data, sizeof(data), 1, cfp);
		fseek(ofp, sizeof(data) * i, SEEK_SET);

		currentSize += sizeof(data);
		printSize = ((float)currentSize / size) * 100;

		// 백분율 표시
		gotoxy(0, 3);
		for (int i = 0; i < printSize / 10; i++) {
			printf("■");
		}
		gotoxy(22, 3);
		printf("%.1f %\n", printSize);

		//Sleep(10);	// 속도 느리게 하려고 추가
	}


	fclose(ofp);
	fclose(cfp);
}


void gotoxy(int x, int y) 
{ 
	COORD Pos = { x, y };	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); 
}
