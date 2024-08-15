#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

/*
Q1. p.889 연습 문제 2

Q2. 후위표기법을 활용하여 스택 계산기 프로그램을 작성하라.
	() < +,- < x,/
	((4x12)x(123+7)
*/

struct OPERATOR
{
	string c;
	int num;
};

int main()
{
	string str;
	stack<string> st;
	queue<string> q;
	OPERATOR operators[6] = { {"(", 0}, {")",0}, {"+", 1}, {"-",1}, {"x", 2}, {"/", 2} };
	bool isOperator = false;
	string numTemp;
	int numTempLength = 0;
	string prevTemp;
	int prevNum = 0;

	//str = "(2+2)x(3+3)";
	cout << "계산식을 입력하세요: \n";
	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		isOperator = false;

		for (int j = 0; j < 6; j++)
		{
			if (i == 0 && str[i] == '-')
				break;

			if (operators[j].c[0] == str[i])
			{
				isOperator = true;

				if (!st.empty())
				{
					if (st.top() == "+" || st.top() == "-")
						prevNum = 1;
					else if (st.top() == "x" || st.top() == "/")
						prevNum = 2;
				}

				if (numTempLength != 0)
				{
					q.push(numTemp);
					numTempLength = 0;
					numTemp = "";
				}

				if (str[i] == '(')
				{
					st.push(operators[j].c);
					break;
				}

				if (str[i] == ')')
				{
					while (st.top() != "(")
					{
						q.push(st.top());
						st.pop();
					}

					st.pop();	// "(" 삭제
					break;
				}

				// 이전 거가 우선순위 더 높다면
				if (prevNum > operators[j].num && st.top() != "(")
				{
					q.push(st.top());
					st.pop();

					st.push(operators[j].c);
				}
				else
				{
					st.push(operators[j].c);
				}
				break;
			}
		}

		if (isOperator == false)	// 숫자
		{
			numTempLength++;
			numTemp += str[i];
		}
	}

	while (!st.empty())
	{
		q.push(st.top());
		st.pop();
	}

	string top;

	while (!q.empty())
	{
		st.push(q.front());
		q.pop();

		if (st.top() == "x" || st.top() == "+" || st.top() == "-" || st.top() == "/")
		{
			top = st.top();

			st.pop();
			int temp = stoi(st.top());
			st.pop();

			if (top == "x")
				temp *= stoi(st.top());
			else if (top == "+")
				temp += stoi(st.top());
			else if (top == "-")
				temp -= stoi(st.top());
			else
				temp /= stoi(st.top());
			st.pop();
			st.push(to_string(temp));
		}
	}

	cout << "결과: " << st.top() << endl;
}