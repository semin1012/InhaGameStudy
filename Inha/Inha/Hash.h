#pragma once
#include <iostream>

class Student
{
public:
	std::string name	= "";
	int			num		= -1;
public:
	Student() {};
	Student(std::string name, int num) : name(name), num(num) {};
	void SetInfo(std::string name, int num)
	{
		this->name = name;
		this->num = num;
	}
};

class Node
{
public:
	Student data;
	Node* next = nullptr;

public:
	Node() {};
};

class Hash
{
private:
	int			size;
	Node**		table;	// 해쉬 테이블 첫번째 요소에 대한 포인터

public:
	Hash();
	~Hash();
	bool		Initialize(int size);
	bool		Add(const Student* data);
	bool		Remove(const int number);
	Node*		Search(const int number);
	void		Dump();
	void		Clear();
};

