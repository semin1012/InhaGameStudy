#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
Q1. 학교에 100개의 사물함과 100명의 학생이 있다.
	모든 사물함이 첫 날에는 닫혀 있다.
	학생이 교실로 들어가면서
	s1이라는 첫번째 학생은 모든 사물함을 연다.
	s2라는 두번째 학생은 L2부터 시작하여 1개씩 건너뛰면서 사물함을 닫는다.
	s3라는 세번째 학생은 L3부터 시작하여 2개씩 건너뛰면서 사물함의 상태를 변경한다. 
	( 열림 <-> 닫힘 )
	...
	학생 s100이 L100 사물함을 변경할 때까지 계속된다. 
*/

/**/
// p.124 
int int_cmp(const int* a, const int* b)
{
	if (*a < *b)
		return 1;	// 오름/내림 차순 변경
	else if (*a > *b)
		return -1;	// 오름/내림 차순 변경
	else return 0;
}

int main()
{
	int nx, ky;
	puts("bsearch 함수를 사용하여 검색");
	printf("요소 개수: ");
	scanf("%d", &nx);
	int *x = (int*)calloc(nx, sizeof(int));

	printf("내림차순으로 입력하세요.\n");
	printf("x[0]: ");
	scanf("%d", &x[0]);
	for (int i = 1; i < nx; i++)
	{
		do {
			printf("x[%d]: ", i);
			scanf("%d", &x[i]);
		} while (x[i] > x[i - 1]);	// 오름/내림 차순 변경
	}
	printf("검색값: ");
	scanf("%d", &ky);
	int* p = (int*)bsearch(
		&ky,
		x,
		nx,
		sizeof(int),
		(int(*)(const void*, const void*)) int_cmp);
	if (p == NULL)
		puts("검색에 실패했습니다.\n");
	else
		printf("%d은(는) x[%d]에 있습니다.\n", ky, (int)(p - x));
	free(x);
	return 0;

}

