#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)


/*
// 예제 11-4 
int main()
{
	char ch;

	//int i;
	//for (i = 0; i < 3; i++)
	//{
	//	scanf("%c", &ch);
	//	printf("%c", ch);
	//}

	while (1)
	{
		scanf("%c", &ch);
		if (ch == '\n')
			break;
		printf("%c", ch);
	}
}
*/


void my_gets(char* str, int size);

int main()
{
	char str[7];
	
	while (1)
	{
		my_gets(str, sizeof(str));
		printf("입력한 문자열: %s\n", str);
	}
}

void my_gets(char* str, int size)
{
	int ch;
	int i = 0;

	ch = getchar();
	while ((ch != '\n') && (i < size - 1))
	{
		str[i] = ch;
		i++;
		ch = getchar();
	}
	str[i] = '\0';
}