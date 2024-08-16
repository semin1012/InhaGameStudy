#include <iostream>
#include <cstring>

/*
Q1. ¹®Á¦...
*/

#define MAX 1

void bubbleSort(int v[], int size)
{
	int temp;
	int count = 0;

	for (int i = 0; i < size - 1; i++)
	{
		count = 0;
		for (int j = size - 1; j > i; j--)
		{
			if (v[j] < v[j - 1])
			{
				temp = v[j];
				v[j] = v[j - 1];
				v[j - 1] = temp;
				count++;
			}
		}
		if (count == 0)
			break;
	}
}

int solution(int l, int v[], int size)
{
	int maxDistance = 0;

	bubbleSort(v, size);

	if (size > 1)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (v[i + 1] - v[i] > maxDistance)
				maxDistance = v[i + 1] - v[i];
		}

		if (v[size - 1] != l)
		{
			if (l - v[size - 1] > maxDistance)
				maxDistance = l - v[size - 1];
		}
	}

	else
	{
		if (v[0] < l - v[0]) return l - v[0];
		else return v[0];
	}

	return (maxDistance + 1) / 2;
}

int main()
{
	int l = 15;
	int v[MAX] = { 12 };

	std::cout << solution(l, v, MAX);
}