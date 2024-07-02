#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int board[1001][1001];
int dist[1001][1001];
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, n;
	cin >> m >> n;

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				q.push({ i, j });
			if (board[i][j] == 0)
				dist[i][j] = -1;
		}
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = cur.first + dir_x[i];
			int dy = cur.second + dir_y[i];
			if (dist[dx][dy] >= 0)
				continue;
			if (dy < 0 || dx < 0 || dy >= m || dx >= n)
				continue;
			dist[dx][dy] = dist[cur.first][cur.second] + 1;
			q.push({ dx, dy });
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1) {
				cout << "-1";
				return 0;
			}
			answer = max(answer, dist[i][j]);
		}
	}
	cout << answer;
}