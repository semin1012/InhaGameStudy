#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "IntStack.h"
using namespace std;

int main()
{
	IntStack s;
	if (Initialize(&s, 5) == -1)
	{
		puts("스택 생성에 실패했습니다.\n");
		return 1;
	}

	while (1)
	{
		int menu, x;
		printf("현재 데이터 수: %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)검색 (6)클리어 (0)종료: ");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1:
			printf("데이터: ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a오류: 푸시에 실패했습니다.\n");
			break;
		case 2:
			if (Pop(&s, &x) == -1)
				puts("\a오류: 팝에 실패했습니다.\n");
			else printf("팝 데이터는 %d입니다.\n", x);
			break;
		case 3:
			if (Peek(&s, &x) == -1)
				puts("\a오류: 피크에 실패했습니다.\n");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;
		case 4:
			Print(&s);
			break;
		case 5:
			int find;
			printf("검색 데이터: ");
			scanf("%d", &find);
			int idx;
			idx = Search(&s, find);
			if (idx == -1)
				puts("\a오류: 검색 데이터가 존재하지 않습니다.\n");
			else printf("검색 데이터는 %d번째에 존재합니다.\n", idx);
			break;
		case 6:
			Clear(&s);
			printf("클리어했습니다.\n");
			break;
		default:
			printf("다시 입력하세요.\n");
			break;
		}
	}
	Terminate(&s);
	return 0;
}