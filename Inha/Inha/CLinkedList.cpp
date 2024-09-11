#include "CLinkedList.h"

CLinkedList::CLinkedList(int size)
{
	arrSize = size;
	node = new Node[arrSize + 1];
	node->data = { "", -1 };
	node->cursor = -1;
	curIdx = 0;
	head = node;	
	dataCount = 0;
}

CLinkedList::~CLinkedList()
{
	delete[] node;
}

void CLinkedList::Search(std::string name)
{
	Node* temp = head;
	while (temp->cursor != -1)
	{
		if (temp->data.name == name)
		{
			std::cout << "[�˻� ���] �̸�: " << temp->data.name << ", �й�: " << temp->data.number << "\n";
			return;
		}

		temp = &node[temp->cursor];
	}

	std::cout << "�˻��� �̸��� �л� �����Ͱ� �������� �ʽ��ϴ�.\n";
	return;
}

void CLinkedList::Search(int num)
{
	Node* temp = head;
	while (temp->cursor != -1)
	{
		if (temp->data.number == num)
		{
			std::cout << "[�˻� ���] �̸�: " << temp->data.name << ", �й�: " << temp->data.number << "\n";
			return;
		}

		temp = &node[temp->cursor];
	}

	std::cout << "�˻��� �й��� �л� �����Ͱ� �������� �ʽ��ϴ�.\n";
	return;
}

void CLinkedList::InsertRear(const Student* st)
{
	Node* temp = head;

	if (dataCount >= arrSize)
	{
		std::cout << "[����] ������ ������ ������ �ʰ��Ͽ� �����߽��ϴ�.\n";
		std::cout << "       �ִ� ���� ũ��: " << arrSize << ", ���� ����� ũ��: " << dataCount;
		return;
	}

	node[curIdx].data = *st;
	dataCount++;
	
	int nextIdx = curIdx;

	if (dataCount < arrSize)
	{
		for (int i = 0; i < arrSize; i++)
		{
			if (node[i].cursor == -1 && i != curIdx)
			{
				nextIdx = i;
				break;
			}
		}
		node[curIdx].cursor = nextIdx;
		curIdx = nextIdx;
	}
	else
	{
		// �迭�� ��Ұ� �� �� ���
		node[curIdx].cursor = arrSize;
		node[arrSize].cursor = -1;
	}

}

void CLinkedList::Remove(std::string name)
{
	Node* temp = head;
	Node* pre = temp;

	while (temp->cursor != -1)
	{
		if (temp->data.name == name)
		{
			if (temp == head)
			{
				head = &node[temp->cursor];
			}
			pre->cursor = temp->cursor;
			temp->cursor = -1;
			std::cout << "[���� ����] �̸�: " << temp->data.name << ", �й�: " << temp->data.number << "�� �����͸� �����߽��ϴ�.\n";
			dataCount--;
			return;
		}
		pre = temp;
		temp = &node[temp->cursor];
	}

	std::cout << "�˻��� �̸��� �л� �����Ͱ� �������� �ʽ��ϴ�.\n";
}

void CLinkedList::Remove(int num)
{
	Node* temp = head;
	Node* pre = temp;

	while (temp->cursor != -1)
	{
		if (temp->data.number == num)
		{
			if (temp == head)
			{
				head = &node[temp->cursor];
			}
			pre->cursor = temp->cursor;
			temp->cursor = -1;
			std::cout << "[���� ����] �̸�: " << temp->data.name << ", �й�: " << temp->data.number << "�� �����͸� �����߽��ϴ�.\n";
			dataCount--;
			return;
		}
		pre = temp;
		temp = &node[temp->cursor];
	}

	std::cout << "�˻��� �̸��� �л� �����Ͱ� �������� �ʽ��ϴ�.\n";
}

void CLinkedList::Print()
{
	Node* temp = head;

	if (dataCount == 0)
	{
		std::cout << "[����] ����� �����Ͱ� �����ϴ�.\n";
		return;
	}
	
	std::cout << "[�л� ��ü ���]\n";

	while (temp->cursor != -1)
	{
		std::cout << "�л� �̸�: " << temp->data.name << ", �л� ��ȣ: " << temp->data.number << "\n";
		temp = &node[temp->cursor];
	}
}
