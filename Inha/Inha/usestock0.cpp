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
*/

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