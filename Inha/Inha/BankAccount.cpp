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
	std::cout << ">> " << name << "�� �ܾ�: " << balance << '\n';
}

void BankAccount::showName(void) const
{
	std::cout << ">> " << name << '\n';
}

void BankAccount::deposit(double cash)
{
	std::cout << ">> " << name << "�� ���¿� " << cash << "���� �Ա��߽��ϴ�.\n";
	balance += cash;
}

void BankAccount::withdraw(double cash)
{
	if (cash <= balance)
	{
		std::cout << ">> " << name << "�� ���¿��� " << balance << "���� ����߽��ϴ�.\n";
		balance -= cash;
	}
	else std::cout << ">> [�ܰ� ����]���� �����߽��ϴ�.\n";
}

bool BankAccount::isItSameName(std::string name)
{
	if (this->name == name)
		return true;
	return false;
}
