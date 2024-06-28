#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)


/*
p.343 길이가 가장 긴 단어 찾기
*/

/*
// 예제 12-1
int main()
{
	printf("apple이 저장된 시작 주소 값: %p\n", "apple");
	printf("두 번째 문자의 주소 값: %p\n", "apple" + 1);
	printf("첫 번째 문자: %c\n", *"apple");
	printf("두 번째 문자: %c\n", *("apple" + 1));
	printf("배열로 표현한 세 번째 문자: %c\n", "apple"[2]);
}


int main()
{
	char str[80];
	printf("입력하세요: ");
	gets(str);
	printf("입력하세요: ");
	gets(str);

	for (int i = 0; i < 80; i++) 
	{
		printf("%c", str[i]);
	}
}
// 예제 12-5
int main()
{
	char str[80];
	printf("공백이 포함된 문자열 입력: ");
	fgets(str, sizeof(str), stdin);
	printf("입력된 문자열은 %s입니다\n", str);
}
// 예제 12-6
int main()
{
	int age;
	char name[20];

	printf("나이 입력: ");
	scanf("%d", &age);

	printf("이름 입력: ");
	//getchar();	// getchar 안 쓰면 입력버퍼에 개행문자 남아서 결과 이상함
	gets(name);
	printf("나이: %d, 이름: %s\n", age, name);
}
// 예제 12-7
int main()
{
	char str[80] = "apple juice";
	char* ps = "banana";

	puts(str);			// 자동 줄바꿈
	fputs(ps, stdout);	// 줄바꿈 X
	puts("milk");		// 자동 줄바꿈

}
// 예제 12-8 수정
void my_gets(char* ps, int size);
void my_puts(char* ps);

int main()
{
	char str[20];
	
	my_gets(str, 20);
	my_puts(str);
}

void my_gets(char* ps, int size)
{
	int i = 0;
	char ch = '\0';

	while (ch != '\n')
	{
		ch = getchar();
		ps[i] = ch;
		i++;
		if (i >= size) {
			printf("문자열 초과 다시 입력하세요\n");
			ch = '\0';
			gets();
			i = 0;
		}
	}

	ps[--i] = '\0';
}

void my_puts(char* ps)
{
	printf("%s\n", ps);
}
// 예제 12-8
int main()
{
	char str1[80] = "strawberry";
	char str2[80] = "apple";
	char* ps1 = "banana";
	char* ps2 = str2;

	printf("최초 문자열: %s\n", str1);

	strcpy(str1, str2);
	printf("바뀐 문자열: %s\n", str1);

	printf("\n");
	for (int i = 0; i < 80; i++) {
		printf("%c", str1[i]);
	}
	printf("\n\n");

	strcpy(str1, ps1);
	printf("바뀐 문자열: %s\n", str1);

	strcpy(str1, ps2);
	printf("바뀐 문자열: %s\n", str1);

	strcpy(str1, "banana");
	printf("바뀐 문자열: %s\n", str1);
}
// 예제 12-9
int main()
{
	char str[20] = "mango tree";
	strncpy(str, "apple-pie", 5);
	printf("%s\n", str);
}
int main()
{
	char str[80] = "straw";

	strcat(str, "berry");
	printf("%s\n", str);
	strncat(str, "piece", 3);
	printf("%s\n", str);
}
// 예제 12-11
int main()
{
	char str1[80], str2[80];
	char* resp;

	printf("2개의 과일 이름 입력: ");
	scanf("%s%s", str1, str2);
	if (strlen(str1) > strlen(str2))
		resp = str1;
	else
		resp = str2;
	printf("이름이 긴 과일은 : %s\n", resp);
}
int main()
{
	char str1[80] = "pear";
	char str2[80] = "peach";
	int s1 = strcmp(str1, str2);
	printf("사전에 나중에 나오는 과일 이름: ");
	if (s1 > 0)
		printf("%s\n", str1);
	else printf("%s\n", str2);
}
// 예제 12-13
char* my_strcpy(char* pd, char* ps);

int main()
{
	char str[80] = "strawberry";
	printf("바꾸기 전 문자열: %s\n", str);
	my_strcpy(str, "apple");
	printf("바꾼 후 문자열: %s\n", str);
	printf("다른 문자열 대입: %s\n", my_strcpy(str, "kiwi"));
}

char* my_strcpy(char* pd, char* ps) 
{
	char* po = pd;

	while (*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';

	return po;
}

int main()
{
	char str1[80] = "B";
	char str2[80] = "a";
	int s1 = my_strcmp(str1, str2);	// 대문자, 소문자 구분 없이 수행됨
	printf("사전에 나중에 나오는 과일 이름: ");
	if (s1 > 0)
		printf("%s\n", str1);
	else printf("%s\n", str2);
}
*/

/*
Q1. p.381 도전 실전 예제
	my_strcmp (my_strcpy, my_strcat) 를
	이용하여 프로그램을 작성하라.
	대소문자에 대해서도 strcmp와 동일한 결과가
	나올 수 있도록 한다. 
*/

int my_strcmp(char* pa, char* pb);
void my_swap(char* pa, char* pb);
void my_strcpy(char* pd, char* ps);

int main()
{
	char str1[80], str2[80], str3[80];
	printf("단어 입력: ");
	scanf("%s", str1); 
	scanf("%s", str2);
	scanf("%s", str3);

	if ( my_strcmp(str1, str2 ) > 0)
		my_swap(str1, str2);
	if (my_strcmp(str1, str3) > 0)
		my_swap(str1, str3);
	if (my_strcmp(str2, str3) > 0)
		my_swap(str2, str3);

	printf("입력한 단어: %s, %s, %s", str1, str2, str3);

}

void my_swap(char* pa, char* pb)
{
	char temp[80];
	my_strcpy(temp, pa);
	my_strcpy(pa, pb);
	my_strcpy(pb, temp);
}

void my_strcpy(char* pd, char* ps)
{
	char* po = pd;

	while (*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';
}

int my_strcmp(char* pa, char* pb)
{
	char a = '\0', b = '\0';

	while (( a == b ) && (*pa != '\0'))
	{
		if (*pa >= 'a')
		{
			a = *(pa)-32;
		}
		else a = *pa;
		if (*pb >= 'a')
		{
			b = *(pb)-32;
		}
		else b = *pb;
		pa++;
		pb++;
	}

	if (a > b) return 1;
	else if (a < b) return -1;
	else return 0;
}