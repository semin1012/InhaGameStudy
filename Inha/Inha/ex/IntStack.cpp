#include <stdio.h>
#include "IntStack.h"

int Initialize(IntStack* s, int max)
{
	s->stk = new int[max];
	if (s == nullptr) return -1;
	s->max = max;
	s->ptr = 0;
	return 0;
}

int Push(IntStack* s, int x)
{
	if (s->max > s->ptr)
	{
		s->stk[s->ptr++] = x;
		return 0;
	}
	return -1;
}

int Pop(IntStack* s, int* x)
{
	if (s->ptr > 0)
	{
		*x = s->stk[(s->ptr--)-1];
		return 0;
	}
	return -1;
}

int Peek(const IntStack* s, int* x)
{
	if (s->ptr != 0)
	{
		*x = s->stk[s->ptr-1];
		return 0;
	}
	return -1;
}

void Clear(IntStack* s)
{
	s->ptr = 0;
}

int Capacity(const IntStack* s)
{
	return s->max;
}

int Size(const IntStack* s)
{
	return s->ptr;
}

int IsEmpty(const IntStack* s)
{
	if (s->ptr == 0) return 1;
	else return 0;
}

int IsFull(const IntStack* s)
{
	if (s->ptr == s->max) return 1;
	else return 0;
}

int Search(const IntStack* s, int x)
{
	for (int i = 0; i < s->ptr; i++)
	{
		if (s->stk[i] == x) 
		{
			return i+1;	// 원소가 존재하는 위치를 return
		}
	}
	return -1;		// 없으면 -1 return
}

void Print(const IntStack* s)
{
	for (int i = 0; i < s->ptr; i++)
		printf("%d ", s->stk[i]);
	printf("\n");
}

void Terminate(IntStack* s)
{
	s->max = 0;
	s->ptr = 0;
	delete[] s->stk;
}
