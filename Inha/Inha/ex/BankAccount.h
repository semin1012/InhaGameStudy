#pragma once
#include <string>

class BankAccount
{
private:
	std::string name;
	std::string acctnum;
	double balance;
public:
	BankAccount();
	BankAccount(const std::string& client, const std::string &num, double bal = 0.0);
	~BankAccount();
	void show(void) const;
	void showName(void) const;
	void deposit(double cash);
	void withdraw(double cash);
	bool isItSameName(std::string name);
};

