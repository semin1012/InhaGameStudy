#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)

/*
// 예제 16-1
int main()
{
	int* pi;
	double* pd;

	pi = (int*)malloc(sizeof(int) * 1000000000);
	pd = (double*)malloc(sizeof(double));

	for (int i = 0; i < 1000000000; i++) {
		if (pi[i] == NULL)
		{
			printf("i = %d\n", i);
			printf("# 메모리가 부족합니다.\n");
			exit(1);
		}


		pi[i] = i;
		*pd = 3.4;

		//printf("정수형으로 사용: %d\n", pi[i]);
		//printf("실수형으로 사용: %.1lf\n", *pd);

		//printf("\n");
	}

	printf("완료\n");
	free(pi);
	free(pd);
}
// 예제 16-3
int main()
{
	int* pi;
	int size = 5;
	int count = 0;
	int num;
	int i;

	pi = (int*)calloc(size, sizeof(int));
	while (1)
	{
		printf("양수만 입력하세요 => ");
		scanf("%d", &num);
		if (num <= 0) break;
		if (count == size)
		{
			size += 5;
			pi = (int*)realloc(pi, size * sizeof(int));
			printf("size 변경, 현재 size: %d\n", size);
		}
		pi[count++] = num;
	}
	for (i = 0; i < count; i++)
	{
		printf("%5d", pi[i]);
	}
	free(pi);
}
// 예제 16-5 수정
void print_str(char** ps);

int main()
{
	char temp[80];
	char* str;
	int size = 5;
	str = (char*)calloc(size, sizeof(char));
	int count = 0;
	
	while (1)
	{
		// 안되는디? 이중 포인터 써볼것
		printf("문자열을 입력하세요. (end는 종료): ");
		gets(temp);
		if (strcmp(temp, "end") == 0) break;
		if (count + 1 == size)
		{
			size += 5;
			str = (char*)realloc(str, sizeof(char) * size);
			printf("size 변화, size 크기: %d\n", size);
		}
		str[count] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[count++], temp);
	}

	print_str(str);
	for (int i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
}

void print_str(char** ps)
{
	while (*ps != NULL)
	{
		printf("%s\n", *ps);
		ps++;
	}
}
*/