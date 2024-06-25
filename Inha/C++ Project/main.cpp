#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		string in;
		stack<char> s;
		bool result = true;
		getline(cin, in);

		if (in == ".") return 0;

		for (auto c : in) 
		{
			if (c == '[' || c == '(') s.push(c);
			else if (c == ']') 
			{
				if (s.empty() || s.top() != '[')
				{
					result = false;
					break;
				}
				s.pop();
			}
			else if (c == ')') 
			{
				if (s.empty() || s.top() != '(')
				{
					result = false;
					break;
				}
				s.pop();
			}
		}

		if (!s.empty()) result = false;
		(result == true) ? cout << "yes\n" : cout << "no\n";
	}
}