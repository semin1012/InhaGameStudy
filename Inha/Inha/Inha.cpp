#include <iostream>
#include <string>
#include <Windows.h>
#include "StopWatch.h"
//#include "SLinkedList.h"
//#include "CLinkedList.h"
//#include "DLinkedList.h"
#include "BinaryTree.h"
using namespace std;

/*
Q1. (원형) 더블 링크드 리스트(Linked List)를 구현하라.
	학생 번호, 이름으로 입력(정렬)/삭제/출력/검색(이진) 기능을 가진
	학생부를 구현하시오.
	(이전에 구현했던 싱글링크드 리스트를 배열과 커서를 이용한 개념으로 수정하라.)
*/

/*
Q1. 이전에 구현했던 학생부 관리 프로그램을 이진트리를 이용한 구조로 변경하라.
	입력(이진트리 구성) / 삭제 / 출력 / 검색 (번호로)
*/


void PrintMenu()
{
	cout << "=========================================\n";
	cout << "  1: 학생 정보 입력\n";
	cout << "  2: 학생 정보 삭제\n";
	cout << "  3: 학생 정보 출력\n";
	cout << "  4: 학생 정보 검색\n";
	cout << "  5: 종료\n";
	cout << "=========================================\n";
	cout << ">> 메뉴 입력: ";
}

void InputStudentData(BinaryTree& tree)
{
	Student* data = new Student();
	cout << "\n저장할 학생 정보를 입력해주세요.\n";
	cout << ">> 이름: ";
	cin >> data->name;
	cout << ">> 번호: ";
	cin >> data->number;

	tree.Add(data);
	cout << "저장되었습니다.\n\n";
}

void PrintAllData(BinaryTree& tree)
{
	cout << "\n모든 학생의 정보를 출력합니다.\n";
	tree.PrintTree();
	cout << "\n";
}

void RemoveStudentData(BinaryTree& tree)
{
	int number;
	cout << "\n삭제할 학생의 번호를 입력해주세요.\n";
	cout << ">> 삭제할 학생의 번호: ";
	cin >> number;
	tree.Remove(number);
	cout << "\n";
}

void SearchStudentData(BinaryTree& tree)
{
	int number;
	cout << "\n검색할 학생의 번호를 입력해주세요.\n";
	cout << ">> 학생 번호: ";
	cin >> number;
	Node* node = tree.Search(number);
	cout << "[결과] 학생 이름: " << node->data.name << ", 학생 번호: " << node->data.number << "\n\n";
}

int main()
{
	BinaryTree bt;
	int menu;
	Student st1 = { "이름", 2020 };
	bt.Add(&st1);
	st1 = { "이름2", 2021 };
	bt.Add(&st1);
	st1 = { "이름3", 2022 };
	bt.Add(&st1);

	bt.PrintTree();
	cout << "\n";

	while (1)
	{
		PrintMenu();
		cin >> menu;

		switch (menu)
		{
		case 1:
			InputStudentData(bt);
			break;
		case 2:
			RemoveStudentData(bt);
			break;
		case 3:
			PrintAllData(bt);
			break;
		case 4:
			SearchStudentData(bt);
			break;
		case 5:
			cout << "프로그램을 종료합니다.\n";
			return 0;
		default:
			cout << "메뉴를 다시 입력해주세요.\n";
			break;
		}
	}
}





//void PrintMenu()
//{
//	cout << "=========================================\n";
//	cout << "  1: 학생 정보 입력\n";
//	cout << "  2: 학생 정보 삭제\n";
//	cout << "  3: 학생 정보 출력\n";
//	cout << "  4: 학생 정보 검색\n";
//	cout << "  5: 종료\n";
//	cout << "=========================================\n";
//	cout << ">> 메뉴 입력: ";
//}
//
//void InputStudentData(DLinkedList& dlist)
//{
//	Node *node = new Node();
//	cout << ">> 학생 이름: ";
//	cin >> node->data.name;
//	cout << ">> 학생 번호: ";
//	cin >> node->data.number;
//
//	dlist.InsertRear(node);
//	cout << "\n  학생 정보가 저장되었습니다.\n";
//}
//
//int compare(const Student* x, const Student* y)
//{
//	if (x->name == y->name && x->number == y->number)
//		return 1;
//	return 0;
//}
//
//void RemoveStudentData(DLinkedList& dlist)
//{
//	cout << "  삭제할 학생 정보를 입력하세요.\n";
//	
//	Student* student = new Student();
//	cout << ">> 학생 이름: ";
//	cin >> student->name;
//	cout << ">> 학생 번호: ";
//	cin >> student->number;
//	
//	Node* node = dlist.Search(student, compare);
//	dlist.Remove(node);
//}
//
//void ShowAllStudentInfo(DLinkedList& dlist)
//{
//	cout << "모든 학생들의 정보를 출력합니다.\n\n";
//	dlist.Print();
//}
//
//
//int compareWithName(const Student* x, const Student* y)
//{
//	if (x->name == y->name)
//		return 1;
//	return 0;
//}
//
//
//void SearchStudent(DLinkedList& dlist)
//{
//	cout << "  검색할 학생 정보를 입력하세요.\n";
//
//	Student* student = new Student();
//	cout << ">> 학생 이름: ";
//	cin >> student->name;
//
//	Node* node = dlist.Search(student, compareWithName);
//
//	dlist.PrintMember(node);
//}
//
//int main()
//{
//	DLinkedList dlist;
//	int menu;
//
//	while (1)
//	{
//		PrintMenu();
//		cin >> menu;
//
//		switch (menu)
//		{
//		case 1:
//			InputStudentData(dlist);
//			break;
//		case 2:
//			RemoveStudentData(dlist);
//			break;
//		case 3:
//			ShowAllStudentInfo(dlist);
//			break;
//		case 4:
//			SearchStudent(dlist);
//			break;
//		case 5:
//			return 0;
//		default:
//			cout << "[오류] 메뉴를 다시 입력하세요.\n";
//			break;
//		}
//	}
//}