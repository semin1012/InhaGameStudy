#include <iostream>
#include "tabtenn0.h"

/*
int main()
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.Name();
	if ( rplayer1.HasTable())
		cout << ": Ź���밡 �ִ�.\n";
	else
		cout << ": Ź���밡 ����.\n";
	player1.Name();
	if (player1.HasTable())
		cout << ": Ź���밡 �ִ�.\n";
	else
		cout << ": Ź���밡 ����.\n";

	cout << "�̸�: ";
	rplayer1.Name();
	cout << "; ��ŷ: " << rplayer1.Rating() << endl;
	RatedPlayer rplayer2(1212, player1);
	cout << "�̸�: ";
	rplayer2.Name();
	cout << "; ��ŷ: " << rplayer2.Rating() << endl;
	return 0;
}
*/

/*
#include "brass.h"

int main()
{
	using std::cout;
	using std::endl;

	Brass Piggy("Porcelot Pigg", 381299, 4000.00);
	BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
	Piggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	cout << "Hogg ���� ���¿� $1000 �Ա�:\n";
	Hoggy.Deposit(1000.00);
	cout << "Hogg ���� ���� �ܾ�: $" << Hoggy.Balance() << endl;
	cout << "Pigg ���� ���¿��� $4200 ����:\n";
	Piggy.Withdraw(4200.00);
	cout << "Pigg ���� ���� �ܾ�: $" << Piggy.Balance() << endl;
	cout << "Hogg ���� ���¿��� $4200 ����:\n";
	Hoggy.Withdraw(4200.00);
	Hoggy.ViewAcct();
}
*/

/*
#include <string>
#include "brass.h"
const int CLIENTS = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	Brass* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "���� �̸��� �Է��Ͻʽÿ�: ";
		getline(cin, temp);
		cout << "���� ���� ��ȣ�� �Է��Ͻʽÿ�: ";
		cin >> tempnum;
		cout << "���� ���� �ܾ��� �Է��Ͻʽÿ�: $";
		cin >> tempbal;
		cout << "Brass ���´� 1, " << "BrassPlus ���´� 2�� �Է��Ͻʽÿ�: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "1 �ƴϸ� 2, �� �� �ϳ��� �Է��Ͻʽÿ�: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "���� ��� �ѵ��� �Է��Ͻʽÿ�: $";
			cin >> tmax;
			cout << "���� ��� �������� �Ҽ��� �������� �Է��Ͻʽÿ�: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}

	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}*/

/*
#include <iostream>
#include <string>
#include "acctabc.h"
const int CLIENTS = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	AcctABC* p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;

	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "���� �̸��� �Է��Ѵ�: ";
		getline(cin, temp);
		cout << "���� ������� ��ȣ�� �Է��Ѵ�: ";
		cin >> tempnum;
		cout << "���� ������ �Է��Ѵ�: $";
		cin >> tempbal;
		cout << "Brass ���¿� 1���� �Է��Ѵ�. �Ǵ�, " << "BrassPlus ���¿� 2���� �Է��Ѵ�: ";

		while (cin >> kind && (kind != '1' && kind != '2'))
				cout << "1 �ƴϸ� 2, �� �� �ϳ��� �Է��Ͻʽÿ�: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "���´�� �Ѱ踦 �Է��Ѵ�: $";
			cin >> tmax;
			cout << "�������� �Է��Ѵ� �Ҽ����� ����Ѵ�: ";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}

	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}
*/

#include "dma.h"

int main()
{
	using std::cout;
	using std::endl;

	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);

	cout << "baseDMA ��ü�� ����Ѵ�:\n";
	cout << shirt << endl;
	cout << "lacksDMA ��ü�� ����Ѵ�:\n";
	cout << balloon << endl;
	cout << "hasDMA ��ü�� ����Ѵ�:\n";
	cout << map << endl;
	lacksDMA balloon2(balloon);
	cout << "lacksDMA ���� ���:\n";
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "hasDMA ���� ���:\n";
	cout << map2 << endl;
	return 0;
}