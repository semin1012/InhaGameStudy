#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)

/*
Q1. 사용자로부터 문자열을 입력 받아서
	단어 단위로 역순으로 출력하는 프로그램을
	작성하라. "Quit"가 입력될 때까지 반복한다.

	ex>
		입력 > I am happy
		출력 > happy am I
		메모리 할당, 잘라서 카피(개수 알아야 함) 

p.502 소수 계산 프로그램

*/

int main(int argc, char** argv)
{
	printf(" >>> arguments <<< \n");
	printf(" >>> argv[1] : %s \n", argv[1]);
	//printf(" >>> argv[1] : %s \n", argv[1]);

	int num = atoi(argv[1]);
	// calloc으로 고쳤고
	char** a = (char**)calloc(num+1, sizeof(char*));
	
	bool decimal = true;
	int col = 1;
	char temp[10] = { 0 };

	// i는 0부터 되게 범위 고쳤고
	for (int i = 0; i < num; i++)
	{
		decimal = true;
		if (i < 2) decimal = false;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0) {
				decimal = false;
				break;
			}
		}
		int t = i, count = 1;
		while ( t != 0 )
		{
			t = t / 10;
			count++;
		}

		a[i] = (char*)malloc(count*sizeof(char*));

		if (decimal == true) {
			_itoa(i, a[i], 10);
		}
		else {
			strcpy(a[i], "X");
		}
	}

	for (int i = 0; i < num; i++)
	{
		if (a[i] != NULL) {
			printf("%5s", a[i]);
			if (col % 5 == 0)
				printf("\n");
			col++;
		}
	}

	for (int i = 0; a[i] != NULL; i++) {
		free(a[i]);
	}
}

/*
//예제 17-2

struct profile
{
	char name[20];
	int age;
	double height;
	char* intro;
};

int main()
{
	struct profile yuni;

	strcpy(yuni.name, "서하윤");
	yuni.age = 17;
	yuni.height = 164.5;

	yuni.intro = (char*)malloc(80);
	printf("자기소개 : ");
	gets(yuni.intro);

	printf("이름: %s\n", yuni.name);
	printf("나이: %d\n", yuni.age);
	printf("키: %.1lf\n", yuni.height);
	printf("자기소개: %s\n", yuni.intro);
	free(yuni.intro);
}
// 예제 17-3
struct profile
{
	int age;
	double height; 
};

struct student
{
	struct profile pf;
	int id;
	double grade;
};

int main()
{
	struct student yuni;

	yuni.pf.age = 17;
	yuni.pf.height = 164.5;
	yuni.id = 315;
	yuni.grade = 4.3;

	printf("나이: %d\n", yuni.pf.age);
	printf("키: %.1lf\n", yuni.pf.height);
	printf("학번: %d\n", yuni.id);
	printf("학점: %.1lf\n", yuni.grade);
}
// 예제 17-4
struct student
{
	int id;
	char name[20];
	double grade;
};

int main()
{
	struct student s1 = { 315, "홍길동", 2.4 },
				   s2 = { 316, "이순신", 3.6 },
				   s3 = { 317, "세종대왕", 4.4 };

	struct student max;

	max = s1;
	if (s2.grade > max.grade) max = s2;
	if (s3.grade > max.grade) max = s3;

	printf("학번: %d\n", max.id);
	printf("이름: %s\n", max.name);
	printf("학점: %.1lf\n", max.grade);
}
// 예제 17-6
struct score
{
	int kor;
	int eng;
	int math;
};

int main()
{
	struct score yuni = { 90, 80, 70 };
	struct score* ps = &yuni;

	printf("국어: %d\n", (*ps).kor);
	printf("영어: %d\n", ps->eng);
	printf("수학: %d\n", ps->math);
}
// 예제 17-9
struct list
{
	int num;
	struct list* next;
};

int main()
{
	struct list a = { 10, 0 }, b = { 20, 0 }, c = { 30, 0 }, d = { 40, 0 };
	struct list* head = &a, * current;

	a.next = &b;
	b.next = &c;
	c.next = &d;

	printf("head->num : %d\n", head->num);
	printf("head->next->num : %d\n\n", head->next->num);

	printf("list all: ");
	current = head;
	while (current != NULL)
	{
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");

}

// 예제 17-10
union student
{
	int num;
	double grade;
};

int main()
{
	union student s1 = { 315 };
	printf("학번: %d\n", s1.num);
	s1.grade = 4.4;
	printf("학점: %.1lf\n", s1.grade);
	printf("학번: %d\n", s1.num);
}
enum season { SPRING, SUMMER, FALL, WINTER };

int main()
{
	enum season ss;
	char* pc = NULL;

	ss = SPRING;
	switch (ss)
	{
	case SPRING:
		pc = "inline"; break;
	case SUMMER:
		pc = "swimming"; break;
	case FALL:
		pc = "trip"; break;
	case WINTER:
		pc = "skiing"; break;
	}
	printf("나의 레저 활동 => %s\n", pc);
}
*/