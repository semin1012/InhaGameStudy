#include <stdio.h>
#include "IntQueue.h"

/*
Q4. ����ť ���� p.164 �ڵ带 ������� �ؼ� �ۼ�
	clear, search �޴��� �߰�
int main()
{
	IntQueue que;
	int temp;

	if (Initialize(&que, 5) == -1) {
		puts("ť�� ������ �����Ͽ����ϴ�.\n");
		return 1;
	}

		while (1)
	{
		int m, x;
		printf("���� ������ ��: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)��ť (2)��ť (3)��ũ (4)��� (5)Ŭ���� (6)��ġ (0)����: ");
		scanf("%d", &m);

		if (m == 0) break;
		switch (m)
		{
		case 1:
			printf("������: "); scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("\a����: ��ť�� �����Ͽ����ϴ�.\n");
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("\a����: ��ť�� �����Ͽ����ϴ�.\n");
			else printf("��ť�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("\a����: ��ũ�� �����Ͽ����ϴ�.\n");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 4:
			Print(&que);
			break;
		case 5:
			Clear(&que);
			printf("ť�� �ʱ�ȭ�߽��ϴ�.\n");
			break;
		case 6:
			printf("ã�� ���� �Է��ϼ���: ");
			scanf("%d", &x);
			temp = Search(&que, x);
			if (temp == -1)
				puts("\a����: ã�� ���� �������� �ʽ��ϴ�.\n");
			else printf("ã�� ���� %d��°�� �����մϴ�.\n", temp+1);
			break;
		default:
			printf("�޴��� �ٽ� �Է��ϼ���.\n");
			break;
		}
	}
	Terminate(&que);
}
*/