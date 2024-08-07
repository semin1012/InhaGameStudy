#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount()
{
	balance = 0.0f;
}

BankAccount::BankAccount(const std::string& client, const std::string& num, double bal)
{
	name = client;
	acctnum = num;
	balance = bal;
}

BankAccount::~BankAccount()
{
}

void BankAccount::show(void) const
{
	std::cout << ">> " << name << "의 잔액: " << balance << '\n';
}

void BankAccount::showName(void) const
{
	std::cout << ">> " << name << '\n';
}

void BankAccount::deposit(double cash)
{
	std::cout << ">> " << name << "의 계좌에 " << cash << "원을 입금했습니다.\n";
	balance += cash;
}

void BankAccount::withdraw(double cash)
{
	if (cash <= balance)
	{
		std::cout << ">> " << name << "의 계좌에서 " << balance << "원을 출금했습니다.\n";
		balance -= cash;
	}
	else std::cout << ">> [잔고 부족]으로 실패했습니다.\n";
}

bool BankAccount::isItSameName(std::string name)
{
	if (this->name == name)
		return true;
	return false;
}
