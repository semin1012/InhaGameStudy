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
			std::cout << "[검색 결과] 이름: " << temp->data.name << ", 학번: " << temp->data.number << "\n";
			return;
		}

		temp = &node[temp->cursor];
	}

	std::cout << "검색한 이름의 학생 데이터가 존재하지 않습니다.\n";
	return;
}

void CLinkedList::Search(int num)
{
	Node* temp = head;
	while (temp->cursor != -1)
	{
		if (temp->data.number == num)
		{
			std::cout << "[검색 결과] 이름: " << temp->data.name << ", 학번: " << temp->data.number << "\n";
			return;
		}

		temp = &node[temp->cursor];
	}

	std::cout << "검색한 학번의 학생 데이터가 존재하지 않습니다.\n";
	return;
}

void CLinkedList::InsertRear(const Student* st)
{
	Node* temp = head;

	if (dataCount >= arrSize)
	{
		std::cout << "[오류] 정해진 데이터 개수를 초과하여 저장했습니다.\n";
		std::cout << "       최대 저장 크기: " << arrSize << ", 현재 저장된 크기: " << dataCount;
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
		// 배열에 요소가 꽉 찬 경우
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
			std::cout << "[삭제 성공] 이름: " << temp->data.name << ", 학번: " << temp->data.number << "의 데이터를 삭제했습니다.\n";
			dataCount--;
			return;
		}
		pre = temp;
		temp = &node[temp->cursor];
	}

	std::cout << "검색한 이름의 학생 데이터가 존재하지 않습니다.\n";
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
			std::cout << "[삭제 성공] 이름: " << temp->data.name << ", 학번: " << temp->data.number << "의 데이터를 삭제했습니다.\n";
			dataCount--;
			return;
		}
		pre = temp;
		temp = &node[temp->cursor];
	}

	std::cout << "검색한 이름의 학생 데이터가 존재하지 않습니다.\n";
}

void CLinkedList::Print()
{
	Node* temp = head;

	if (dataCount == 0)
	{
		std::cout << "[오류] 저장된 데이터가 없습니다.\n";
		return;
	}
	
	std::cout << "[학생 전체 출력]\n";

	while (temp->cursor != -1)
	{
		std::cout << "학생 이름: " << temp->data.name << ", 학생 번호: " << temp->data.number << "\n";
		temp = &node[temp->cursor];
	}
}
