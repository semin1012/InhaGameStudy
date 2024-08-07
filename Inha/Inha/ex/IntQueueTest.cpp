#include <stdio.h>
#include "IntQueue.h"

/*
Q4. 원형큐 구현 p.164 코드를 기반으로 해서 작성
	clear, search 메뉴도 추가
int main()
{
	IntQueue que;
	int temp;

	if (Initialize(&que, 5) == -1) {
		puts("큐의 생성에 실패하였습니다.\n");
		return 1;
	}

		while (1)
	{
		int m, x;
		printf("현재 데이터 수: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5)클리어 (6)서치 (0)종료: ");
		scanf("%d", &m);

		if (m == 0) break;
		switch (m)
		{
		case 1:
			printf("데이터: "); scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a오류: 인큐에 실패하였습니다.\n");
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a오류: 디큐에 실패하였습니다.\n");
			else printf("디큐한 데이터는 %d입니다.\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a오류: 피크에 실패하였습니다.\n");
			else
				printf("피크한 데이터는 %d입니다.\n", x);
			break;
		case 4:
			Print(&que);
			break;
		case 5:
			Clear(&que);
			printf("큐를 초기화했습니다.\n");
			break;
		case 6:
			printf("찾는 값을 입력하세요: ");
			scanf("%d", &x);
			temp = Search(&que, x);
			if (temp == -1)
				puts("\a오류: 찾는 값이 존재하지 않습니다.\n");
			else printf("찾는 값은 %d번째에 존재합니다.\n", temp+1);
			break;
		default:
			printf("메뉴를 다시 입력하세요.\n");
			break;
		}
	}
	Terminate(&que);
}
*/