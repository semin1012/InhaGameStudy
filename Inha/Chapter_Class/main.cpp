#include <iostream>
#include <cstring>
#include "workermi.h"
#include "QueueTP.h"
const int SIZE = 5;

/*
Q2. p.1105 Q3 QueueTP ���ø� Ŭ������ �����϶�. �� ���� �ڵ带 �������� �ڵ尡 �ٸ��� �����ϴ���
	�׽�Ʈ�϶�.
	- UML

Q3. ���� ���� 3���� ������� ����
	p.215 Q2ó��... ���� �� �����ͳ��� ��ȯ �߻� ���θ� +, - ��ȣ��
	������ ��ģ �� ��Ƚ���� ��ȯȽ���� ����϶�.
	- StopWatch Ŭ������ �̿��ؼ� �˰��� ������ �����϶�.
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
		cout << "\n�н�" << path << ", ��: " << compair << "\n";
		// �տ�������
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
		cout << "\n�н�" << path << ", ��: " << compair << "\n";
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
		cout << "\n�н�" << path << ", ��: " << compair << "\n";
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

	//cout << "**���� ��Ʈ �⺻**\n";
	//bubbleSortBasic(arr);

	//cout << "\n\n**���� ��Ʈ ����1**\n";
	//bubbleSortUpgrade(arr);

	cout << "**���� ��Ʈ ����2**\n";
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
		cout << "������ �Է��Ͻʽÿ�:\n" << "w: ������  s: ����  " << "t: ���� �� ������  q: ����\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "w, s, t, q �߿��� �ϳ��� �����Ͻʽÿ�: ";
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

	cout << "\n��� ��Ȳ�� ������ �����ϴ�:\n";

	while (!lola.isEmpty())
	{
		cout << endl;
		lola.getFront()->Show();
		lola.pop();
	}
	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}
*/