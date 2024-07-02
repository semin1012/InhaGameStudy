#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

string board[1002];
int dist1[1001][1001];
int dist2[1001][1001];
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < r; i++) {
		fill(dist1[i], dist1[i] + c, -1);
		fill(dist1[i], dist1[i] + c, -1);
	}

	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'F') {
				q1.push({ i,j });
				dist1[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				q2.push({ i,j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!q1.empty()) {
		pair<int, int> cur = q1.front(); q1.pop();
		for (int i = 0; i < 4; i++) {
			int dx = cur.first + dir_x[i];
			int dy = cur.second + dir_y[i];

			if (dx < 0 || dy < 0 || dx >= r || dy >= c) continue;
			if (dist1[dx][dy] >= 0 || board[dx][dy] == '#') continue;

			dist1[dx][dy] = dist1[cur.first][cur.second] + 1;
			q1.push({ dx, dy });
		}
	}

	while (!q2.empty()) {
		pair<int, int> cur = q2.front(); q2.pop();
		for (int i = 0; i < 4; i++) {
			int dx = cur.first + dir_x[i];
			int dy = cur.second + dir_y[i];

			if (dx < 0 || dy < 0 || dx >= r || dy >= c) {
				cout << dist2[cur.first][cur.second] + 1;
				return 0;
			}
			if (dist2[dx][dy] >= 0 || board[dx][dy] == '#') continue;
			if (dist1[dx][dy] != -1 && dist1[dx][dy] <= dist2[cur.first][cur.second] + 1) continue;

			dist2[dx][dy] = dist2[cur.first][cur.second] + 1;
			q2.push({ dx, dy });
		}
	}

	cout << "IMPOSSIBLE";
}