#include "workermi.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Worker::Data() const
{
	cout << "��� �̸�: " << fullname << endl;
	cout << "��� ��ȣ: " << id << endl;
}

void Worker::Get()
{
	getline(cin, fullname);
	cout << "��� ��ȣ�� �Է��Ͻʽÿ�: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void Waiter::Set()
{
	cout << "�������� �̸��� �Է��Ͻʽÿ�: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "����: ������\n";
	Worker::Data();
	Data();
}

void Waiter::Data() const
{
	cout << "������ ���: " << panache << endl;
}

void Waiter::Get()
{
	cout << "������ ����� �Է��Ͻʽÿ�: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

const char* Singer::pv[Singer::Vtypes] = { "other",  "alto", "contralto", "soprano", "bass", "bartitone", "tenor" };

void Singer::Set()
{
	cout << "������ �̸��� �Է��Ͻʽÿ�: ";
	Worker::Get();
	Get();
}

void Singer::Show() const
{
	cout << "����: ����\n";
	Worker::Data();
	Data();
}

void Singer::Data() const
{
	cout << "��Ҹ� ����: " << pv[voice] << endl;
}

void Singer::Get()
{
	cout << "������ ��Ҹ� ���� ��ȣ�� �Է��Ͻʽÿ�:\n";
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << "  ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << '\n';
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}

void SingingWatiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWatiter::Get()
{
	Waiter::Get();
	Singer::Get();
}

void SingingWatiter::Set()
{
	cout << "���� �� �������� �̸��� �Է��Ͻʽÿ�: ";
	Worker::Get();
	Get();
}

void SingingWatiter::Show() const
{
	cout << "����: ���� �� ������\n";
	Worker::Data();
	Data();
}
