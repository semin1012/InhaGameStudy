// Inha.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <Windows.h>

void main()
{	/*
	// 예제 3-1
	int a;
	int b, c;
	double da;
	char ch;

	a = 10;
	b = a;
	c = a + 20;
	da = 3.5;
	ch = 'A';

	printf("변수 a의 값: %d\n", a);
	printf("변수 b의 값: %d\n", b);
	printf("변수 c의 값: %d\n", c);
	printf("변수 da의 값: %.1lf\n", da);
	printf("변수 ch의 값: %c\n", ch);

	// 예제 3-2
	char ch1 = 'A';
	char ch2 = 65;

	printf("문자 %c의 아스키 코드 값: %d\n", ch1, ch1);
	printf("아스키 코드 값이 %d인 문자: %c\n", ch2, ch1);

	// 예제 3-3, #include <limits.h> 보면 최댓값 확인할 수 있다.
	short sh = 32767;
	int in = 2147483647;
	long ln = 2147483647;
	long long lln = 123451234512345;

	printf("short형 변수 출력: %d\n", sh);
	printf("int형 변수 출력: %d\n", in);
	printf("long형 변수 출력: %ld\n", ln);
	printf("long long형 변수 출력: %lld\n", lln);

	// 예제 3-5
	float ft = 1.234567890123456789f;
	double db = 1.234567890123456789;

	printf("float형 변수의 값: %.20f\n", ft);
	printf("double형 변수의 값: %.20lf\n", db);

	// 예제 3-6, 3-7
	char fruit[20] = "strawberry";

	printf("딸기: %s\n", fruit);
	printf("딸기잼: %s %s\n", fruit, "jam");

	printf("%s\n", fruit);
	strcpy(fruit, "banana");
	printf("%s\n", fruit);

	// INT	// Windows.h에서 정의가 된 사용자정의 타입이다.

	int a;
	scanf("%d", &a);
	printf("%d\n", a);

	// 예제 3-10
	int age;
	double height;

	printf("나이와 키를 입력하세요: ");
	scanf("%d%lf", &age, &height);
	printf("나이는 %d살, 키는 %.1lfcm입니다.\n", age, height);
	
	// 예제 3-11
	char grade;
	char name[20];

	printf("학점 입력: ");
	scanf("%c", &grade);
	printf("이름 입력: ");
	scanf("%s", name);
	printf("%s의 학점은 %c입니다. \n", name, grade);
	
	// 예제 4-1
	int a, b;
	int sum, sub, mul, inv;

	a = 10;
	b = 20;
	sum = a + b;
	sub = a - b;
	mul = a * b;
	inv = -a;

	printf("a의 값: %d, b의 값: %d\n", a, b);
	printf("덧셈: %d\n", sum);
	printf("뺄셈: %d\n", sub);
	printf("곱셈: %d\n", mul);
	printf("a의 음수 연산: %d\n", inv);

	// 예제 4-2
	double apple;
	int banana;
	int orange;

	apple = 5.0 / 2.0;
	banana = 5 / 2;
	orange = 5 % 2;
	printf("apple: %.1lf\n", apple);
	printf("banana: %d\n", banana);
	printf("orange: %d\n", orange);

	double d1 = 5.0 / 2;
	double d2 = 5 / 2.0;
	printf("d1(d): %d\n", d1);
	printf("d1(lf): %lf\n", d1);
	printf("d2(d): %d\n", d2);
	printf("d2(lf): %lf\n", d2);
	int n1 = 5.0 / 2;
	int n2 = 5 / 2.0;
	printf("n1(d): %d\n", n1);
	printf("n1(lf): %lf\n", n1);
	printf("n2(d): %d\n", n2);
	printf("n2(lf): %lf\n", n2);
	
	// 예제 4/3
	int a = 10, b = 10;
	++a;
	--b;
	printf("a: %d\n", a);
	printf("b: %d\n", b);
	
	// 예제 4-4
	int a = 5, b = 5;
	printf("현재 값 a = %d, b = %d\n", a, b);
	int pre, post;
	pre = (++a) * 3;
	post = (b++) * 3;
	printf("증감 연산 후 초깃값 a = %d, b = %d\n", a, b);
	printf("전위형: (++a) * 3 = %d, 후위형: (b++) * 3 = %d\n", pre, post);
	
	// 예제 4-5
	int a = 10, b = 20, c = 10;
	int res;
	res = (a > b);
	printf("a > b = %d\n", res);
	res = (a >= b);
	printf("a >= b = %d\n", res);
	res = (a < b);
	printf("a < b = %d\n", res);
	res = (a <= b);
	printf("a >= b = %d\n", res);
	res = (a <= c);
	printf("a <= c = %d\n", res);
	res = (a == b);
	printf("a == b = %d\n", res);
	res = (a != c);
	printf("a != c = %d\n", res);
	*/
	// 예제 4-6
	int a = 30;
	int res;

	res = (a > 10) && (a < 20);
	printf("(a > 10) && (a < 20) : %d\n", res);
	res = (a < 10) || (a > 20);
	printf("(a < 10) || (a > 20) : %d\n", res);
	res = !(a >= 30);
	printf("!(a >= 30) : %d\n", res);

}

