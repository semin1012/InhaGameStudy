#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <crtdbg.h>		// 메모리 릭이 일어났는지 확인하기 위함

/*
Q1. p.540 성적 처리 프로그램
	학번, 이름, 학점(국/영/수)을 입력받을 수 있는
	구조체를 만들고, 임의 수의 학생에 대한 데이터를 입력받아
	출력하는 프로그램을 작성하라.
	다음 4개의 메뉴를 구성하고, 각 메뉴의 선택시 작동은 다음과 같다.

	1. 입력 - 학번, 이름, 성적 순으로 입력
	2. 출력 - 성적(평균)에 따라 (정렬된 형태로) 출력
	3. 검색 - 이름으로 해당 학생의 학점, 성적을 출력
	4. 종료
	조건>
		1. 번호 중복 불가, 이름은 중복 가능
		2. 검색 -> 이름 검색으로 하고 먼저 찾은 것을 우선 출력
		3. 메모리 할당 활용, 자기 참조 구조체 활용
		4. 입력/출력/검색은 각각 개별 함수로 구현한다.
*/

struct Student
{
	int studentNum;
	char name[20];
	int kor;
	int eng;
	int math;
	double avg;
};

struct List
{
	struct Student student;
	struct List* next;
	struct List* prev;
};

void printMenu()
{
	printf("=================================================\n");
	printf("1. 입력 - 학번, 이름, 성적 순으로 입력\n");
	printf("2. 출력 - 성적(평균)에 따라 정렬된 형태로 출력\n");
	printf("3. 검색 - 이름으로 해당 학생의 학점, 성적을 출력\n");
	printf("4. 종료\n");
	printf("=================================================\n");
}

void inputMenu(int* menu)
{
	printf("> ");
	scanf("%d", menu);
}

void inputStudent(struct List* head, struct List* tail)
{
	while (1)
	{
		bool dup = false;

		struct List* newNode = (struct List*)malloc(sizeof(struct List));
		struct List* prevNode = tail->prev;

		printf("학번 이름 학점(국/영/수)를 순서대로 입력하세요(0 입력 시까지): ");
		scanf("%d", &newNode->student.studentNum);

		if (newNode->student.studentNum == 0) {
			break;
		}

		scanf("%s%d", &newNode->student.name, &newNode->student.kor);
		scanf("%d%d", &newNode->student.eng, &newNode->student.math);

		struct List* node = head->next;
		while (node != tail)
		{
			if (node->student.studentNum == newNode->student.studentNum) {
				printf("학번이 같습니다. 다시 입력하세요.\n\n");
				dup = true;
				break;
			}
			node = node->next;
		}
		if (dup == true)
			continue;



		newNode->student.avg = (newNode->student.kor + newNode->student.eng + newNode->student.math) / 3.f;

		prevNode->next = newNode;
		newNode->prev = prevNode;
		newNode->next = tail;
		tail->prev = newNode;
	}
}

void printStudents(struct List* head, struct List* tail)
{
	if (head->next == tail)
	{
		printf("저장된 학생이 없습니다.\n\n");
		return;
	}

	struct List* tempi = head->next;
	struct List* tempj = head->next;

	while (tempi != tail)
	{
		tempj = head->next;
		while (tempj != tail->prev)
		{
			if (tempj->student.avg < tempj->next->student.avg)
			{
				struct Student temp;
				temp = tempj->student;
				tempj->student = tempj->next->student;
				tempj->next->student = temp;
			}
			tempj = tempj->next;
		}
		tempi = tempi->next;
	}

	// 출력 부분
	struct List* node = head->next;
	while (node != tail)
	{
		printf("이름: %s, 학번: %d, 평균 성적: %.2lf \n", node->student.name, node->student.studentNum, node->student.avg);
		node = node->next;
	}

}

void searchStudent(struct List* head, struct List* tail)
{
	if (head->next == tail)
	{
		printf("저장된 학생이 없습니다.\n\n");
		return;
	}

	char searchName[20];

	printf("학생의 이름을 입력하세요: ");
	scanf("%s", searchName);

	struct List* node = head->next;
	while (node != tail)
	{
		if (strcmp(node->student.name, searchName) == 0)
		{
			printf("이름: %s \n", node->student.name);
			printf("  학번: %d\n", node->student.studentNum);
			printf("  국어 성적: %d\n", node->student.kor);
			printf("  영어 성적: %d\n", node->student.eng);
			printf("  수학 성적: %d\n", node->student.math);
			printf("\n평균 성적: %.2lf\n", node->student.avg);
			return;
		}
		node = node->next;
	}

	printf("\n찾는 학생이 존재하지 않습니다.\n\n");
}

int main(int argc, char** argv)
{
	int menu;

	struct List* head = (struct List*)malloc(sizeof(struct List));
	struct List* tail = (struct List*)malloc(sizeof(struct List));

	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = head;

	while (1)
	{
		printMenu();
		inputMenu(&menu);
		
		switch (menu)
		{
		case 1:
			inputStudent(head, tail);
			break;
		case 2:
			printStudents(head, tail);
			break;
		case 3:
			searchStudent(head, tail);
			break;
		case 4:
			printf("프로그램을 종료합니다.\n\n");

			struct List* node = head;
			while (node)
			{
				struct List* deleteNode = node;
				node = node->next;
				free(deleteNode);
			}
			/*_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF); // -> F5로 실행하면 메모리 릭 번호 나옴
			// _CrtSetBreakAlloc(70);			// -> 그 번호를 이 함수 안에 넣으면 어떤 변수인지 보여줌

			int* arr = NULL;
			arr = (int*)malloc(sizeof(int) * 4);

			_CrtDumpMemoryLeaks();*/

			return 0;
		default:
			printf("다시 입력하세요.\n\n");
		}
		printf("\n엔터를 입력하세요.\n");
		_getch();		// 엔터 입력 전까지 안 넘어가게 하기 위함
		system("cls");
	}
}