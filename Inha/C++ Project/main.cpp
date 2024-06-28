#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int board[102][102] = { -1 };
int visit[102][102] = { -1 };
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { -1, 1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char c;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			board[i][j] = c - '0';
		}
	}

	queue<pair<int, int>> q;
	visit[0][0] = 1;
	q.push({ 0,0 });
	int cnt = 0;
	int dx = 0, dy = 0;
	
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			dx = cur.first + dir_x[i];
			dy = cur.second + dir_y[i];
			if (dx < 0 || dy < 0 || dx >= n || dy >= m)
				continue;
			if (visit[dx][dy] > 1 || board[dx][dy] != 1)
				continue;
			visit[dx][dy] = visit[cur.first][cur.second] + 1;

			q.push({ dx, dy });
		}
	}
	cout << visit[n-1][m-1];
}