#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		int i = 0;
		string str;
		deque<int> dq;
		cin >> str >> n;
		while (dq.size() != n) {
			char c;
			cin >> c;
			if (isalnum(c)) dq.push_back(c - 48);
		}
		while (str[i] != NULL) {
			if (str[i] == 'R') {
				for (int i = 0; i < (int)dq.size()-1; i++) {
					reverse(dq.begin(), dq.end());
				}
			}
			else if ( str[i] == 'D') {

			}
			i++;
		}
		cout << "[";
		/*for (int i = dq.begin(); i < dq.size()-1; i++) {
			cout << dq[i] << ",";
		}*/
		cout << dq.back() << "]\n";
	}
}