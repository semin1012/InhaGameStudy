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
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";
	player1.Name();
	if (player1.HasTable())
		cout << ": 탁구대가 있다.\n";
	else
		cout << ": 탁구대가 없다.\n";

	cout << "이름: ";
	rplayer1.Name();
	cout << "; 랭킹: " << rplayer1.Rating() << endl;
	RatedPlayer rplayer2(1212, player1);
	cout << "이름: ";
	rplayer2.Name();
	cout << "; 랭킹: " << rplayer2.Rating() << endl;
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
	cout << "Hogg 씨의 계좌에 $1000 입금:\n";
	Hoggy.Deposit(1000.00);
	cout << "Hogg 씨의 현재 잔액: $" << Hoggy.Balance() << endl;
	cout << "Pigg 씨의 계좌에서 $4200 인출:\n";
	Piggy.Withdraw(4200.00);
	cout << "Pigg 씨의 현재 잔액: $" << Piggy.Balance() << endl;
	cout << "Hogg 씨의 계좌에서 $4200 인출:\n";
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
		cout << "고객의 이름을 입력하십시오: ";
		getline(cin, temp);
		cout << "고객의 계좌 번호를 입력하십시오: ";
		cin >> tempnum;
		cout << "계좌 개설 잔액을 입력하십시오: $";
		cin >> tempbal;
		cout << "Brass 계좌는 1, " << "BrassPlus 계좌는 2를 입력하십시오: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "1 아니면 2, 둘 중 하나를 입력하십시오: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "당좌 대월 한도를 입력하십시오: $";
			cin >> tmax;
			cout << "당좌 대월 이자율을 소수점 형식으로 입력하십시오: ";
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

	cout << "프로그램을 종료합니다.\n";
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
		cout << "고객의 이름을 입력한다: ";
		getline(cin, temp);
		cout << "고객의 은행계좌 번호를 입력한다: ";
		cin >> tempnum;
		cout << "계좌 개설을 입력한다: $";
		cin >> tempbal;
		cout << "Brass 계좌에 1번을 입력한다. 또는, " << "BrassPlus 계좌에 2번을 입력한다: ";

		while (cin >> kind && (kind != '1' && kind != '2'))
				cout << "1 아니면 2, 둘 중 하나를 입력하십시오: ";
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tmax, trate;
			cout << "당좌대월 한계를 입력한다: $";
			cin >> tmax;
			cout << "이자율을 입력한다 소수점을 사용한다: ";
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

	cout << "프로그램을 종료합니다.\n";
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

	cout << "baseDMA 객체를 출력한다:\n";
	cout << shirt << endl;
	cout << "lacksDMA 객체를 출력한다:\n";
	cout << balloon << endl;
	cout << "hasDMA 객체를 출력한다:\n";
	cout << map << endl;
	lacksDMA balloon2(balloon);
	cout << "lacksDMA 복사 결과:\n";
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "hasDMA 대입 결과:\n";
	cout << map2 << endl;
	return 0;
}