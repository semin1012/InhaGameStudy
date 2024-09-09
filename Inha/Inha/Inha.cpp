#include <iostream>
#include <string>
#include <Windows.h>
#include "StopWatch.h"
#include "SLinkedList.h"
using namespace std;

/*
Q1. 싱글 링크드 리스트(Linked List)를 구현하라.
	학생 번호, 이름으로 입력/삭제/출력/검색 기능을 가진
	학생부를 구현하시오.
*/

int PrintMenu();
Student* InputData();
void PrintSleep(float time, string str, bool bEnter = false);
void RemoveData(SLinkedList& list);
void SearchData(SLinkedList& list);

int main()
{
	SLinkedList list;
	int menu;

	list.Initialize();

	while (1)
	{
		menu = PrintMenu();

		switch (menu)
		{
		case 1:
			list.InsertRear(InputData());
			PrintSleep(1000, "저장되었습니다.");
			break;
		case 2:
			RemoveData(list);
			PrintSleep(1000, "");
			break;
		case 3:
			SearchData(list);
			PrintSleep(0, "계속하려면 엔터를 입력하세요.\n", true);
			break;
		case 4:
			list.Print();
			PrintSleep(0, "계속하려면 엔터를 입력하세요.\n", true);
			break;
		case 5:
			return 0;
			break;
		}
	}

}

int PrintMenu()
{
	int menu;

	cout << "----------------------------\n";
	cout << "1. 학생 정보 입력\n";
	cout << "2. 학생 정보 삭제\n";
	cout << "3. 학생 검색\n";
	cout << "4. 전체 출력\n";
	cout << "5. 종료\n";
	cout << "----------------------------\n";
	cout << "메뉴를 입력하세요: ";
	cin >> menu;

	return menu;
}

void PrintSleep(float time, string str, bool bEnter)
{
	cout << str << "\n";
	if (bEnter)
	{
		cin.get();
		char ch;
		cin.get(ch);
		if (ch == '\n')
		{
			system("cls");
			return;
		}
	}
	Sleep(time);
	system("cls");
}

Student* InputData()
{
	Student* student = new Student();
	cout << "학생 이름을 입력하세요: ";
	cin >> student->name;
	cout << "학생 번호를 입력하세요: ";
	cin >> student->number;

	return student;
}

void RemoveData(SLinkedList& list)
{
	int menu, num;
	string name;
	cout << "\n(1)이름으로 삭제, (2)학번으로 삭제\n";
	cin >> menu;

	switch (menu)
	{
	default:
		cout << "잘못된 입력입니다.\n";
		break;
	case 1:
		cout << "삭제할 학생의 이름을 입력하세요: ";
		cin >> name;
		list.Remove(name);
		break;
	case 2:
		cout << "삭제할 학생의 번호를 입력하세요: ";
		cin >> num;
		list.Remove(num);
		break;
	}
}

void SearchData(SLinkedList& list)
{
	int menu, num;
	string name;
	cout << "\n(1)이름으로 검색, (2)학번으로 검색\n";
	cin >> menu;

	switch (menu)
	{
	default:
		cout << "잘못된 입력입니다.\n";
		break;
	case 1:
		cout << "검색할 학생의 이름을 입력하세요: ";
		cin >> name;
		list.Search(name);
		break;
	case 2:
		cout << "검색할 학생의 번호를 입력하세요: ";
		cin >> num;
		list.Search(num);
		break;
	}
}