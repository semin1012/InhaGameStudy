#include <iostream>
#include <cstring>
#include "workermi.h"
#include "QueueTP.h"
const int SIZE = 5;

/*
Q2. p.1105 Q3 QueueTP 템플릿 클래스를 정의하라. 각 예제 코드를 바탕으로 코드가 바르게 동작하는지
	테스트하라.
	- UML

Q3. 버블 정렬 3가지 방법으로 구현
	p.215 Q2처럼... 현재 비교 데이터끼리 교환 발생 여부를 +, - 기호로
	정렬을 마친 후 비교횟수와 교환횟수를 출력하라.
	- StopWatch 클래스를 이용해서 알고리즘 성능을 측정하라.
*/

#define MAX 10

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void printArray(int arr[], int change)
{
	for (int i = 0; i < MAX; i++)
	{
		cout << arr[i];
		if (i != MAX - 1)
		{
			if (i == change)
			{
				if (change == -1)
					cout << "-";
				else cout << "+";
			}
			else cout << "-";
		}
	}
	cout << "\n";
}

void bubbleSortBasic(int arr[])
{
	int arrTemp[MAX];
	for (int i = 0; i < MAX; i++)
	{
		arrTemp[i] = arr[i];
	}
	int path = 1;
	int change = -1;
	int compair = 0;
	for (int i = 0; i <= MAX; i++)
	{
		cout << "\n패스" << path << ", 비교: " << compair << "\n";
		// 앞에서부터
		for (int j = MAX - 1; j > i; j--)
		{
			compair++;
			if (arrTemp[j] < arrTemp[j - 1])
			{
				Swap(arrTemp[j], arrTemp[j - 1]);
				change = j - 1;
			}
			else change = -1;
			printArray(arrTemp, change);
		}
		path++;
	}
}

void bubbleSortUpgrade(int arr[])
{
	int arrTemp[MAX];
	for (int i = 0; i < MAX; i++)
	{
		arrTemp[i] = arr[i];
	}
	int path = 1;
	int count;
	int change;
	int compair = 0;

	for (int i = 0; i < MAX; i++)
	{
		cout << "\n패스" << path << ", 비교: " << compair << "\n";
		count = 0;
		for (int j = MAX - 1; j > i; j--)
		{
			compair++;
			if (arrTemp[j] < arrTemp[j - 1])
			{
				Swap(arrTemp[j], arrTemp[j - 1]);
				count++;
				change = j - 1;
			}
			else change = -1;
			printArray(arrTemp, change);
		}
		path++;
		if (count == 0) break;
	}
}

void bubbleSortUpgrade2(int arr[])
{
	int arrTemp[MAX];
	for (int i = 0; i < MAX; i++)
	{
		arrTemp[i] = arr[i];
	}
	int last = MAX-1;
	int k = MAX-1;
	int path = 1;
	int compair = 0;
	int change;

	while (k > 0)
	{
		cout << "\n패스" << path << ", 비교: " << compair << "\n";
		last = 0;
		for (int i = k; i > 0; i--)
		{
			compair++;
			if (arrTemp[MAX - i] < arrTemp[MAX - i - 1])
			{
				Swap(arrTemp[MAX - i], arrTemp[MAX - i - 1]);
				last = MAX - i - 1;
				change = MAX - i - 1;
			}
			else change = -1;
			printArray(arrTemp, change);
		}
		path++;
		k = last;
	}
}

int main()
{
	int arr[MAX] = { 1,3,9,4,7,8,6 };

	//cout << "**버블 소트 기본**\n";
	//bubbleSortBasic(arr);

	//cout << "\n\n**버블 소트 개선1**\n";
	//bubbleSortUpgrade(arr);

	cout << "**버블 소트 개선2**\n";
	bubbleSortUpgrade2(arr);
}


/*
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	//Worker* lolas[SIZE];
	QueueTP<Worker*> lola(SIZE);

	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "직종을 입력하십시오:\n" << "w: 웨이터  s: 가수  " << "t: 가수 겸 웨이터  q: 종료\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q 중에서 하나를 선택하십시오: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w': 
			lola.push(new Waiter("sss", 40));
			//lolas[ct] = new Waiter;
			break;
		case 's':
			lola.push(new Singer());
			//lolas[ct] = new Singer;
			break;
		case 't':
			lola.push(new SingingWatiter());
			//lolas[ct] = new SingingWatiter;
			break;
		}
		cin.get();
		
		lola.getRear()->Set();
		//lolas[ct]->Set();
	}

	cout << "\n사원 현황은 다음과 같습니다:\n";

	while (!lola.isEmpty())
	{
		cout << endl;
		lola.getFront()->Show();
		lola.pop();
	}
	cout << "프로그램을 종료합니다.\n";
	return 0;
}
*/