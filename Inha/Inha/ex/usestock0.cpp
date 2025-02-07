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
	cout << "생성자를 이용하여 새로운 객체들을 생성한다.\n";
	Stock stock1("NanoSmart", 12, 20.0);
	stock1.show();
	Stock stock2("Boffo Objects", 2, 2.0);
	stock2.show();
	
	cout << "stock1을 stock2에 대입한다.\n";
	stock2 = stock1;
	cout << "stock1과 stock2를 출력한다.\n";
	stock1.show();
	stock2.show();

	cout << "생성자를 사용하여 객체를 재설정한다.\n";
	stock1 = Stock("Nifty Foods", 10, 50.0);
	cout << "갱신된 stock1: \n";
	stock1.show();
	cout << "프로그램을 종료합니다.\n";

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
	cout << "보유 주식 리스트: \n";
	int st;
	for (st = 0; st < STKS; st++)
		stocks[st].show();

	const Stock* top = &stocks[0];

	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);

	cout << "\n최고 가치의 주식:\n";
	top->show();
	return 0;
}
*/