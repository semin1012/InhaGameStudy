#pragma once
#include <iostream>

struct Student
{
	std::string name;
	int number;
};

struct Node
{
	Student data;
	int cursor = -1;
};

class CLinkedList
{
private:
	int			arrSize;
	Node*		head;
	Node*		node;
	int			curIdx;
	int			dataCount;

public:
	CLinkedList(int size);
	~CLinkedList();
	void		Search(std::string name);
	void		Search(int num);
	void		InsertRear(const Student* st);
	void		Remove(std::string name);
	void		Remove(int num);
	void		Print();
};

