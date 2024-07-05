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
*/
// 파일 입출력 실습
/*
int main(int argc, char** argv)
{
	FILE* fp, *fp2;
	char str[] = "banana";


	// :: read file
	fp = fopen("../data/a.txt", "r");
	if (fp == NULL)
	{
		printf("fail! \n");
		return 0;
	}
	printf("read file success!\n");

	// :: write file
	fp2 = fopen("../data/b.txt", "w");
	if (fp2 == NULL) 
	{
		printf("\nfail! \n");
		return 0;
	}
	printf("\nwrite file success!\n");

	char ch;
	while (1)
	{
		ch = fgetc(fp);
		if (ch == EOF) {
			break;
		}
		fputc(ch, fp2);
	}

	fputc('\n', fp2);
	
	fclose(fp);
	fclose(fp2);
}
// 예제 18-6
int main()
{
	FILE* fp;
	int ary[10] = { 13, 10, 13, 13, 10, 26, 13, 10, 13, 10 };
	int i, res;

	fp = fopen("a.txt", "wb");
	for (i = 0; i < 10; i++)
	{
		fputc(ary[i], fp);
	}
	fclose(fp);

	fp = fopen("a.txt", "rt");
	while (1)
	{
		res = fgetc(fp);
		if (res == EOF) break;
		printf("%4d", res);
	}
	fclose(fp);
}
// 예제 18-7
int main()
{
	FILE* fp;
	char str[20];

	fp = fopen("a.txt", "a+");
	if (fp == NULL)
	{
		printf("파일을 만들지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		printf("과일 이름: ");
		scanf("%s", str);
		if (strcmp(str, "end") == 0)
		{
			break;
		}
		else if (strcmp(str, "list") == 0)
		{
			fseek(fp, 0, SEEK_SET);
			while (1)
			{
				fgets(str, sizeof(str), fp);
				if (feof(fp))
				{
					break;
				}
				printf("%s", str);
			}
		}
		else
		{
			fprintf(fp, "%s\n", str);
		}
	}
	fclose(fp);
}
// 예제 18-9
int main()
{
	FILE* ifp, * ofp;
	char name[20];
	int kor, eng, math;
	int total;
	double avg;
	int res;

	ifp = fopen("a.txt", "r");
	if (ifp == NULL)
	{
		printf("입력 파일을 열지 못했습니다.\n");
		return 1;
	}

	ofp = fopen("b.txt", "w");
	if (ofp == NULL)
	{
		printf("출력 파일을 열지 못했습니다.\n");
		return 1;
	}

	while (1)
	{
		res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &math);
		if (res == EOF) 
		{
			break;
		}
		total = kor + eng + math;
		avg = total / 3.f;
		fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
	}

	fclose(ifp);
	fclose(ofp);
}
// 예제 18-11
int main()
{
	FILE* afp, * bfp;
	int num = 10;
	int res;

	afp = fopen("a.txt", "wt");
	fprintf(afp, "%d", num);	// 파일에 출력
	
	bfp = fopen("b.txt", "wb");
	fwrite(&num, 4, sizeof(num), bfp);

	fclose(afp);

	fclose(bfp);

	bfp = fopen("b.txt", "rb");
	fread(&res, sizeof(res), 1, bfp);
	printf("%d", res);

	fclose(bfp);
}
*/