#include "DLinkedList.h"
#include <iostream>
using namespace std;

void DLinkedList::Initialize()
{
	Node* node = new Node();
	head = node;
	curr = node;
	node->prev = node->next = node;
}

bool DLinkedList::IsEmpty()
{
	if (head->next == head)
		return true;
	return false;
}

void DLinkedList::PrintMember(Node* node)
{
	cout << "학생 이름: " << node->data.name << ", 학생 번호: " << node->data.number << "\n";
}

void DLinkedList::PrintCurrent()
{
	if (IsEmpty())
	{
		cout << "리스트가 비어있습니다.\n";
		return;
	}

	cout << ":: PrintCurrent ::\n";
	cout << "학생 이름: " << curr->data.name << "\n";
	cout << "학생 번호: " << curr->data.number;
}

void DLinkedList::PrintLnCurrent()
{
	PrintCurrent();
	cout << "\n\n";
}

Node* DLinkedList::Search(const Student* student, int compare(const Student* x, const Student* y))
{
	Node* node = head;
	
	while ( node->next != head )
	{
		if (compare(student, &node->data) == 1)
		{
			curr = node;
			return node;
		}
		node = node->next;
	}

	return nullptr;
}

void DLinkedList::Print()
{
	curr = head;

	while (Next() == 1)
	{
		PrintMember(curr);
	}
}

void DLinkedList::PrintReverse()
{
	curr = head;

	while (Prev() == 1)
	{
		PrintMember(curr);
	}
}

int DLinkedList::Next()
{
	if (IsEmpty() || curr->next == head )
		return 0;
	curr = curr->next;
	return 1;
}

int DLinkedList::Prev()
{
	if (IsEmpty() || curr->prev == head)
		return 0;
	curr = curr->prev;
	return 1;
}

void DLinkedList::InsertAfter(Node* p)
{
	Node* node = head;

	while (node->next != head)
	{
		if (node == p)
		{
			p->next = node->next;
			p->prev = node;

			node->next = p;
			node->next->prev = p;

			curr = p;
			break;
		}
		node = node->next;
	}
}

void DLinkedList::InsertFront(Node* p)
{
	p->prev = head->prev;
	p->next = head->next;
	
	head->next = p;
	head->next->prev = p;

	curr = head->next;
}

void DLinkedList::InsertRear(Node* p)
{
	p->next = head;
	p->prev = head->prev;

	head->prev = p;
	head->prev->next = p;

	curr = head->prev;
}

void DLinkedList::Remove(Node* p)
{
	if (IsEmpty())
		return;

	Node* node = head;

	while (node->next != head)
	{
		if (node == p)
		{
			node->prev->next = node->next;
			node->next->prev = node->prev;
			curr = node->prev;
			delete node;
			break;
		}
		node = node->next;
	}
}

void DLinkedList::RemoveFront()
{
	if (IsEmpty())
		return;

	Node* front = head->next;

	front->next->prev = head;
	head->next = front->next;
	curr = head->next;

	delete front;
}

void DLinkedList::RemoveRear()
{
	if (IsEmpty())
		return;

	Node* rear = head->prev;

	rear->prev->next = head;
	head->prev = rear->prev;
	curr = head->prev;

	delete rear;
}

void DLinkedList::RemoveCurrent()
{
	if (IsEmpty())
		return;

	Remove(curr);
}

void DLinkedList::Clear()
{
	Node* node = head;

	while (node->next != head)
	{
		Node* temp = node;
		node = node->next;
		delete temp;
	}
}

void DLinkedList::Terminate()
{
	Clear();
	delete head;
}
