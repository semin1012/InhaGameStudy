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
// 예제 19-1
/*
#include "student.h"
int main(void)
{
	Student a = { 315, "홍길동" };

	printf("학번: %d, 이름: %s\n", a.num, a.name);
}
// 예제 19-2
#define PI 3.14159
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("허용 범위를 벗어났습니다!\n")

int main()
{
	double radius, area;

	printf("반지름을 입력하세요(10 이하): ");
	scanf("%lf", &radius);
	area = PI * radius * radius;
	if (area > LIMIT) ERR_PRN;
	else printf("원의 면적: %.2lf (%s)\n", area, MSG);
}
// 예제 19-3
#define SUM(a, b) ((a) + (b))
#define MUL(a, b) ((a) * (b))

int main()
{
	int a = 10, b = 20;
	int x = 30, y = 40;
	int res;

	printf("a + b = %d\n", SUM(a, b));
	printf("x + b = %d\n", MUL(a, b));
	res = 30 / MUL(2, 5);
	printf("res: %d\n", res);
}
// 예제 19-4
void func();

int main()
{
	printf("컴파일 날짜와 시간: %s, %s\n\n", __DATE__, __TIME__);
	printf("파일명: %s\n", __FILE__);
	printf("함수명: %s\n", __FUNCTION__);
	printf("행번호: %d\n", __LINE__);

#line 100 "macro.c"
	func();
}

void func()
{
	printf("\n");
	printf("파일명: %s\n", __FILE__);
	printf("함수명: %s\n", __FUNCTION__);
	printf("행번호: %d\n", __LINE__);
}
// 예제 19-5
#define PRINT_EXPR(x) printf(#x " = %d\n", x)
#define NAME_CAT(x, y) (x##y)
#define VER 6
int main()
{
	int a1, a2;

	NAME_CAT(a, 1) = 10;
	NAME_CAT(a, 2) = 20;
	PRINT_EXPR(a1 + a2);
	PRINT_EXPR(a2 - a1);

#if VER >= 6
	printf("버전 %d\n", VER);
#else
#error 컴파일러 버전은 6.0 이상이어야 합니다
#endif
}
// 예제 19-6
#define VER 7
#define BIT16
int main()
{
	int max;

#if VER >= 6
	printf("버전 %d입니다.\n", VER);
#endif

#ifdef BIT16
	max = 32767;
#else 
	max = 2147483647;
#endif

	printf("int형 변수의 최댓값: %d\n", max);
}
// 예제 19-7
#pragma pack(push, 1)
typedef struct
{
	char ch;
	int in;
} Sample1;

#pragma pack(pop)
typedef struct
{
	char ch;
	int in;
} Sample2;

int main()
{
	printf("Sample1 구조체의 크기: %d바이트\n", sizeof(Sample1));
	printf("Sample2 구조체의 크기: %d바이트\n", sizeof(Sample2));
}
//예제 19-8

void input_data(int*, int*);
double average(int, int);

int main()
{
	int a, b;
	double avg;

	input_data(&a, &b);
	avg = average(a, b);
	printf("%d와 %d의 평균: %.1lf\n", a, b, avg);
}
int input_data();
double average();
void print_data(double);

int count = 0;
static int total = 0;

int main()
{
	double avg;

	total = input_data();
	avg = average();
	print_data(avg);
}

void print_data(double avg)
{
	printf("입력한 양수의 개수: %d\n", count);
	printf("전체 합과 평균: %d, %.1lf\n", total, avg);
}
*/
// 예제 19-9
#include "point.h"
#include "line.h"

int main()
{
	Line a = { { 1, 2 }, {5, 6} };
	Point b;

	b.x = (a.first.x + a.second.x) / 2;
	b.y = (a.first.y + a.second.y) / 2;
	printf("선의 가운데 점의 좌표: (%d, %d)\n", b.x, b.y);
}