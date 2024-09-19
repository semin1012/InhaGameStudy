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
	// head�� ���� ����Ų��
	Node* head;
	Node* curr;

public:
	void	Initialize();
	bool	IsEmpty();
	void	PrintMember(Node* node);
	/* ������ ����� �����͸� ��� */
	void	PrintCurrent();
	/* ������ ����� �����͸� ���(�ٹٲ� ���� �߰�) */
	void	PrintLnCurrent();
	/* compare �Լ��� ��� �˻� */
	Node*	Search(const Student* student, int compare(const Student* x, const Student* y));
	/* ��� ����� �����͸� ����Ʈ ������� ��� */
	void	Print();
	void	PrintReverse();
	int		Next();
	int		Prev();
	/* p�� ����Ű�� ��� �ٷ� �ڿ� ��带 ���� */
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

