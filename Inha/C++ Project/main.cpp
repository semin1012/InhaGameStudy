#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// 백준 1874번 : 스택 수열

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt;
	cin >> cnt;

	int num = 1;	// 자연수 값

	stack<int> myStack;
	vector<char> result;
	bool can = true;

	for (int i = 0; i < cnt; i++) {
		int sy;
		cin >> sy;
		
		if (sy >= num)
		{
			while (sy >= num) {
				myStack.push(num);
				num++;
				result.push_back('+');
			}
			myStack.pop();
			result.push_back('-');
		}

		else {
			int n = myStack.top();
			myStack.pop();
			if (n > sy) {
				cout << "NO";
				can = false;
				return 0;
			}

			else {
				result.push_back('-');
			}
		}
	}

	if (can)
	{
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << '\n';
		}
	}
}