#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	stack<char> s;
	int answer = 0;
	int temp = 1;
	bool result = true;
	char prev = ' ';

	string str;
	cin >> str;

	for (auto c : str)
	{
		if (c == '(' || c == '[')
		{
			s.push(c);
			if (c == '(')
				temp *= 2;
			else temp *= 3;
		}
		else if (c == ')')
		{
			if (s.empty() || s.top() != '(')
			{
				result = false;
				break;
			}
			s.pop();
			if (prev == '(')
			{
				answer += temp;
				temp /= 2;
			}
			else 
			{
				temp /= 2;
			}
		}
		else if (c == ']')
		{
			if (s.empty() || s.top() != '[') 
			{
				result = false;
				break;
			}
			s.pop();
			if (prev == '[')
			{
				answer += temp;
				temp /= 3;
			}
			else
			{
				temp /= 3;
			}
		}
		prev = c;
	}
	if (!s.empty()) result = false;
	// 하 이거때문이엇네
	if (result != false)
		cout << answer;
	else cout << "0";
}