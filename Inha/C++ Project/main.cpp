#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) 
	{
		string str;
		stack<char> s;
		cin >> str;
		bool result = true;
		for (auto c : str)
		{
			if (c == '(') s.push(c);
			else {
				if (s.empty()) {
					result = false;
					break;
				}
				if (s.top() == '(') s.pop();				
			}
		}
		
		if (result == false || !s.empty()) cout << "NO\n";
		else cout << "YES\n";
	}
}