#include <iostream>
#include "stock00.h"

/*
int main()
{
	Stock fluffy_the_cat;
	fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(15, 18.125);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(400, 20.00);
	fluffy_the_cat.show();
	fluffy_the_cat.buy(300000, 40.125);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(300000, 0.125);
	fluffy_the_cat.show();
}
/*
int main()
{
	using std::cout;
	cout << "�����ڸ� �̿��Ͽ� ���ο� ��ü���� �����Ѵ�.\n";
	Stock stock1("NanoSmart", 12, 20.0);
	stock1.show();
	Stock stock2("Boffo Objects", 2, 2.0);
	stock2.show();
	
	cout << "stock1�� stock2�� �����Ѵ�.\n";
	stock2 = stock1;
	cout << "stock1�� stock2�� ����Ѵ�.\n";
	stock1.show();
	stock2.show();

	cout << "�����ڸ� ����Ͽ� ��ü�� �缳���Ѵ�.\n";
	stock1 = Stock("Nifty Foods", 10, 50.0);
	cout << "���ŵ� stock1: \n";
	stock1.show();
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}
*/
/*
const int STKS = 4;
int main()
{
	using namespace std;

	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};
	cout << "���� �ֽ� ����Ʈ: \n";
	int st;
	for (st = 0; st < STKS; st++)
		stocks[st].show();

	const Stock* top = &stocks[0];

	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);

	cout << "\n�ְ� ��ġ�� �ֽ�:\n";
	top->show();
	return 0;
}
*/