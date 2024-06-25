#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//char c = ' ';
	stack<char> c;
	char in;
	bool running = true, result = true;

	while (1) 
	{
		cin >> in;
		if (in != '.') running = true;

		if (in == '.' && running == false)
			return 0;

		switch (in) {
		case '(':
			c.push(in);
			break;
		case ')':
			if (!c.empty() && c.top() == '(')
				c.pop();
			else 
				result = false;
			break;
		case '[':
			c.push(in);
			break;
		case ']':
			if (!c.empty() && c.top() == '[')
				c.pop();
			else
				result = false;
			break;
		case '.':
			if (!c.empty()) {
				cout << "no\n";
				for (int i = 0; i < c.size(); i++)
					c.pop();
			} 
			else if (result == false) {
				cout << "no\n";
			}
			else cout << "yes\n";
			running = false;
			result = true;
			break;
		default:
			break;
		}
	}
}