#pragma once
#include <string>

struct Student
{
	std::string name;
	int number;
};

struct Node
{
	Student data;
	Node* prev;
	Node* next;
};

class DLinkedList
{
public:
	// head가 끝을 가르킨다
	Node* head;
	Node* curr;

public:
	void	Initialize();
	bool	IsEmpty();
	void	PrintMember(Node* node);
	/* 선택한 노드의 데이터를 출력 */
	void	PrintCurrent();
	/* 선택한 노드의 데이터를 출력(줄바꿈 문자 추가) */
	void	PrintLnCurrent();
	/* compare 함수로 노드 검색 */
	Node*	Search(const Student* student, int compare(const Student* x, const Student* y));
	/* 모든 노드의 데이터를 리스트 순서대로 출력 */
	void	Print();
	void	PrintReverse();
	int		Next();
	int		Prev();
	/* p가 가리키는 노드 바로 뒤에 노드를 삽입 */
	void	InsertAfter(Node* p);
	void	InsertFront(Node* p);
	void	InsertRear(Node* p);
	void	Remove(Node* p);
	void	RemoveFront();
	void	RemoveRear();
	void	RemoveCurrent();
	void	Clear();
	void	Terminate();
};

