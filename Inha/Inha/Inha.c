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

Q2. 문자열에서 특정 단어를 찾아서 다른 단어로 바꾸는
	프로그램을 작성하라.
	ex> "I am a boy. I am happy!"
	-> 찾을 단어: boy
	-> 바꿀 단어: girl
	-> 변경된 문자열 > I am a girl. I am happy!
	1. strstr -> api 를 활용
	2. my_strstr 를 만들기
*/

char* my_strstr(char* ps, char* pf);

int main()
{
	char str[80];
	char find[80];
	char change[80];
	char result[80] = { '\0' };

	int find_size = 0;
	int change_size = 0;
	int cnt = 0;
	printf("> ");
	gets(str);
	printf("찾을 단어: ");
	scanf("%s", find);
	find_size = strlen(find);
	printf("바꿀 단어: ");
	scanf("%s", change);
	change_size = strlen(change);

	// 찾는 문자가 있는지 my_strstr로 확인
	// my_strstr : 찾는 문자가 있으면 찾는 문자의 위치를 반환 받음
	char* fp = my_strstr(str, find);

	// 찾는 문자 없으면 프로그램 종료
	if (fp == NULL) {
		printf("찾는 단어가 문자열에 존재하지 않습니다.\n");
		return 0;
	}

	// 찾는 문자 있으면 찾는 문자의 위치를 기준으로
	// result[80]에 (찾는 위치 전의 문자열 + 바꿀 문자 + 찾은 문자 다음의 문자열) 합쳐줌
	else {
		char* op = str;
		// 찾는 위치 전까지는 result에 문자열 그대로 넣는다
		while (op != fp)
		{
			result[cnt] = *op;
			op++;
			cnt++;
		}
		// 찾은 문자의 사이즈만큼 포인터를 옭겨 준다
		for (int i = 0; i < find_size; i++)
		{
			op++;
		}
		// result에 찾은 위치부터는 바꿀 문자열 넣는다
		for (int i = 0; i < change_size; i++)
		{
			result[cnt] = change[i];
			cnt++;
		}
		// 바꾼 문자열 넣었으면 끝까지 result에 그대로 넣어준다
		while (*op != '\0')
		{
			result[cnt] = *op;
			op++;
			cnt++;
		}
	}

	printf("\n%s\n", result);
}

char* my_strstr(char* ps, char* pf)
{
	int cnt = 0;

	while (ps[cnt] != '\0')
	{
		if (ps[cnt] == *pf)
		{
			char* start = ps[cnt];
			bool check = true;
			for (int i = 0; i < strlen(pf); i++)
			{
				//printf("%c %c\n", ps[cnt + i], pf[i]);
				if (ps[cnt+i] != pf[i])
					check = false;
			}
			if (check == true)
			{
				return (ps + cnt);
			}
			pf++;
		}
		cnt++;
	}
	return NULL;
}