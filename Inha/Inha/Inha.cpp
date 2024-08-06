#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

/*
Q1. 임의의 한 단어를 생성하고 사용자가 한번에
	한 문자만 추측하도록 해서 단어를 맞추는 게임.
	단어의 각 문자는 '*'으로 표시된다.
	사용자가 올바른 추측을 했을 때는 실제 문자가 화면에
	표시된다. 
	사용자가 단어를 맞추기를 끝냈을 때 실수한 횟수를 
	표시하고, 다른 단어를 계속할 것인지를 묻도록 한다.
	ex> 생성된 단어: apple
	> 단어 중 한 글자를 입력하시오. ***** > a
	>> a****
	> 단어 중 한 글자를 입력하시오. a**** > r
	>> r은 단어에 포함되지 않습니다.
	> 단어 중 한 글자를 입력하시오. a**** > a
	>> a는 이미 단어에 포함되어 있습니다.
	>> 총 xx 번 실패, 00 번 만에 정답! apple

Q2. p.705 1번
	예금주 설정, 예금 입/출금 합수, 잔액 표시 함수

	1. 예금 새로 만들기 
		예금주 이름, 초기 입금액, 잔액
	2. 예금 입력 
		2.1. 잔액 표시
	3. 예금 출력
		3.1. 잔액 표시

	4, 5번 보류
	4. 총 예금주 명단 출력
	5. 총 예금액 출력
*/

#include "BankAccount.h"
#define ACCOUNT_MAX_NUM 10

void PrintMenu();
void AddAccount(BankAccount& account, int& idx);
void InputDeposit(BankAccount account[], int& idx);
void InputWithdraw(BankAccount account[], int& idx);
void PrintAllName(BankAccount account[], int& idx);
void PrintAllAccount(BankAccount account[], int& idx);

int main()
{
	BankAccount *account = new BankAccount[ACCOUNT_MAX_NUM];
	int idx = 0;
	int menu;

	AddAccount(account[idx], idx);

	while (1)
	{
		PrintMenu();
		cin >> menu;

		switch (menu)
		{
		case 1:
			AddAccount(account[idx], idx);
			break;
		case 2:
			InputDeposit(account, idx);
			break;
		case 3:
			InputWithdraw(account, idx);
			break;
		case 4:
			PrintAllName(account, idx);
			break;
		case 5:
			PrintAllAccount(account, idx);
			break;
		default:
			cout << "메뉴를 다시 입력하세요.\n";
		}
	}
}

void PrintMenu()
{
	cout << "1. 예금 새로 만들기\n";
	cout << "2. 예금 입력\n";
	cout << "3. 예금 출력\n";
	cout << "4. 총 예금주 명단 출력\n";
	cout << "5. 총 예금액 출력\n";
	cout << "=================================\n";
	cout << "메뉴를 입력해 주세요: ";
}

void AddAccount(BankAccount& account, int& idx)
{
	string name, num;

	cout << "예금주 이름, 초기 입금액을 입력해 주세요: ";
	cin >> name >> num;
	account = BankAccount(name, num, stod(num));
	idx++;
}

void InputDeposit(BankAccount account[], int& idx)
{
	double num;
	string name;
	bool find = false;
	cout << "입금할 예금주의 이름을 입력하세요: ";
	cin >> name;
	int i = 0;

	for (i; i < idx; i++)
	{
		// 맞는 이름 찾으면 break
		if (account[i].isItSameName(name))
		{
			find = true;
			break;
		}
	}

	if (find == false)
	{
		cout << "해당하는 예금주가 없습니다.\n";
		return;
	}

	cout << "예금할 금액을 입력하세요: ";
	cin >> num;

	account[i].deposit(num);
	account[i].show();
}

void InputWithdraw(BankAccount account[], int& idx)
{
	double num;
	string name;
	bool find = false;
	cout << "출력할 예금주의 이름을 입력하세요: ";
	cin >> name;
	int i = 0;

	for (i; i < idx; i++)
	{
		// 맞는 이름 찾으면 break
		if (account[i].isItSameName(name))
		{
			find = true;
			break;
		}
	}

	if (find == false)
	{
		cout << "해당하는 예금주가 없습니다.\n";
		return;
	}

	cout << "출금할 금액을 입력하세요: ";
	cin >> num;

	account[i].withdraw(num);
	account[i].show();
}

void PrintAllName(BankAccount account[], int& idx)
{
	for (int i = 0; i < idx; i++)
	{
		account[i].showName();
	}
}

void PrintAllAccount(BankAccount account[], int& idx)
{
	for (int i = 0; i < idx; i++)
	{
		account[i].show();
	}
}