#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, L;
	deque<pair<int, int>> dq;
	deque<int> result;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		while ( !dq.empty() && num <= dq.back().second) {
			dq.pop_back();
		}
		dq.push_back({ i, num });
		
		if (dq.front().first <= i - L) {
			dq.pop_front();
		}

		cout << dq.front().second << " ";
	}	
}