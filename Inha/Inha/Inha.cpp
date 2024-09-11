#include <iostream>
#include <string>
#include <Windows.h>
#include "StopWatch.h"
//#include "SLinkedList.h"
#include "CLinkedList.h"
using namespace std;

/*
Q1. 커서를 이용한 링크드 리스트(Linked List)를 구현하라.
	학생 번호, 이름으로 입력/삭제/출력/검색 기능을 가진
	학생부를 구현하시오.
	(이전에 구현했던 싱글링크드 리스트를 배열과 커서를 이용한 개념으로 수정하라.)
*/

int main()
{
	CLinkedList list(3);
	list.InsertRear(new Student({ "aaa", 10 }));
	list.InsertRear(new Student({ "bbb", 20 }));
	list.InsertRear(new Student({ "ccc", 30 }));
	list.Print();

	cout << "\n\"aaa\" 이름으로 검색\n";
	list.Search("aaa");
	cout << "\n\"20\" 숫자로 검색\n";
	list.Search(20);

	cout << "\n\"aaa\" 이름으로 삭제\n";
	list.Remove("aaa");
	cout << "\n";
	list.Print();
	cout << "\n";
	cout << "\n\"ccc\" 이름으로 삭제\n";
	list.Remove("ccc");
	cout << "\n";
	list.Print();
	cout << "\n";
	cout << "\n\"20\" 숫자로 삭제\n";
	list.Remove(20);
	cout << "\n";
	list.Print();
}