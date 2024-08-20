#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include "StopWatch.h"
using namespace std;

/*
Q1. p.1343 문제 7.

 Q2. 용량이 큰 파일을 작은 용량으로 분할해서 작은 단위의 파일로 나누는
   *  프로그램을 작성하라. 사용자로부터 소스 파일명을 입력 받은 후,
   *  각각 분할된 작은 파일의 바이트 값을 입력 받아야 한다.
   *
   *  ex > Enter file name : test.zip
   *       Enter fill size : 1024
   *       -> file test.zip.01
   *       -> file test.zip.02
   *       -> file test.zip.03
   *      .....
   *      >> Split Done

Q3. 사용자로부터 소스 파일의 개수, 소스 파일의 이름, 목적 파일의 이름을
	입력받아 새로운 하나의 파일로 파일들을 조합하는 프로그램을 작성하라.

	ex> Enter file number: 4
		Enter source number: file test.zip.01
		Enter source number: file test.zip.02
		Enter source number: file test.zip.03
		Enter source number: file test.zip.04
		Enter target file: Dest.zip
		....
			>> Combine Done.

Q4. Shell Sort 구현
	비교횟수와 교환횟수 출력하기
		1. 단순 삽입 정렬의 비교횟수, 교환횟수와 비교
		2. 단순 삽입 정렬과 속도 비교
*/

#define MAX 20000

int nums[MAX];

void insertSort()
{
	int compCount = 0;
	int swapCount = 0;
	int j = 0;
	int tempnums[MAX];

	copy(begin(nums), end(nums), tempnums);
	

	cout << "Insert Sort\n";

	StopWatch st;
	st.start();

	for (int i = 1; i < MAX; i++)
	{
		int temp = tempnums[i];
		for (j = i; j > 0; j--)
		{
			compCount++;
			if (tempnums[j - 1] > temp)
			{
				tempnums[j] = tempnums[j - 1];
				swapCount++;
			}
			else break;
		}
		tempnums[j] = temp;
	}

	st.stop();

	cout << "비교 횟수: " << compCount << ", 교환 횟수: " << swapCount << "\n";
	cout << "InsertSort 시간: " << st.getElpasedTime() << "\n\n";
}

void shellSort()
{
	int compCount = 0;
	int swapCount = 0;
	int tempnums[MAX];

	copy(begin(nums), end(nums), tempnums);

	cout << "Shell Sort\n";
	StopWatch st;

	st.start();
	for (int h = MAX / 3+1; h > 0; h /= 2)
	{
		for (int i = h; i < MAX; i++)
		{
			int temp = tempnums[i];
			int j;
			for (j = i - h; j >= 0; j -= h)
			{
				compCount++;
				if (tempnums[j] >= temp)
				{
					swapCount++;
					tempnums[j + h] = tempnums[j];
				}
				else break;
			}
			tempnums[j + h] = temp;
		}
	}
	st.stop();

	cout << "비교 횟수: " << compCount << ", 교환 횟수: " << swapCount << endl;
	cout << "shellSort 시간: " << st.getElpasedTime() << '\n';
}

int main()
{
	for (int i = 0; i < MAX; i++)
		nums[i] = i + 1;
	
	random_shuffle(begin(nums), end(nums));

	insertSort();
	shellSort();
}