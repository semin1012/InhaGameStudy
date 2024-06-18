// Inha.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main()
{
	/*printf("Be happy!\n");
	printf("12345678901234567890\n");
	printf("My\tfriend\n");
	// \t = 탭
	printf("Goot\bd\tchance\n");
	// \b = back, 뒤로 한 칸
	printf("Cow\rW\a\n");
	// \r = 맨앞으로 이동, \a = 벨소리 출력

	printf("%d\n", 10);
	printf("%lf\n", 3.4);
	printf("%.1lf\n", 3.45);
	printf("%.10lf\n", 3.4);

	printf("%d과 %d의 합은 %d입니다.\n", 10, 20, 10 + 20);
	printf("%.1lf - %.1lf = %.1lf\n", 3.4, 1.2, 3.4 - 1.2);

	printf("%d\n", 12);
	printf("%d\n", 014);	// 8진수, 앞에 0 붙임
	printf("%d\n", 0xc);	// 16진수, 앞에 0x 붙임

	printf("%o\n", 12);		// 10진수 -> 8진수
	printf("%x\n", 12);		// 10진수 -> 16진수 소문자
	printf("%X\n", 12);		// 10진수 -> 16진수 대문자
	
	printf("%.1lf\n", 1e6);
	printf("%.7lf\n", 3.14e-5);
	printf("%le\n", 0.0000314);
	printf("%.2le\n", 0.0000314);

	printf("%c\n", 'A');
	printf("%s\n", "A");*/
	printf("%c는 %s입니다.\n", '1', "first");

	float f = 0.1f;
	f += 0.1f;
	f += 0.1f;
	f += 0.1f;
	f += 0.1f;
	f += 0.1f;
	f += 0.1f;
	f += 0.1f;
	f += 0.1f;
	f += 0.1f;

	printf("%lf", f);
}