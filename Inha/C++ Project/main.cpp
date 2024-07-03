#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int dist[100002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	fill(dist, dist + 100001, -1);

	queue<int> q;
	q.push(n);
	dist[n] = 0;

	while (dist[k] == -1) {
		int cur = q.front(); q.pop();
		for (int a : {cur + 1, cur - 1, cur * 2}) {
			if (a < 0 || a > 100000) continue;
			if (dist[a] != -1) continue;
			dist[a] = dist[cur] + 1;
			q.push(a);
		}
	}
	cout << dist[k];
}