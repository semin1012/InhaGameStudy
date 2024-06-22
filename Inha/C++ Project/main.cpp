#include <iostream>
#include <queue>
#include <string>
using namespace std;

// 백준 3015번 : 오아시스 재결합


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> q;
	int n, input;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		if (str == "push") {
			cin >> input;
			q.push(input);
		}
		else if (str == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			}
			else cout << "-1\n";
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (str == "front") {
			if (!q.empty()) cout << q.front() << '\n';
			else cout << "-1\n";
		}
		else {
			if (!q.empty()) cout << q.back() << "\n";
			else cout << "-1\n";
		}
	}
}