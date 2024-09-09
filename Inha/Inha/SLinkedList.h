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
	Node* next;
};


class SLinkedList
{
public:
	Node* head;

public:
	void	Initialize();
	void	Search(std::string name);
	void	Search(int num);
	void	InsertRear(const Student* st);
	void	Remove(std::string name);
	void	Remove(int num);
	void	Print();
};

