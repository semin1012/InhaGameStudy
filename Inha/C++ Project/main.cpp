#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int board[51][51];
int visit[51][51];

int dirX[4] = { 0, 0, 1, -1 };
int dirY[4] = { 1, -1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, m, n, k;
	int x, y;
	cin >> t;
	int result = 0;
	while (t--)
	{
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			board[y][x] = 1;
		}
	
		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == 1 && visit[i][j] == 0)
				{
					result++;
					q.push({ i, j });
					while (!q.empty() )
					{
						auto cur = q.front();
						q.pop();
						for (int i = 0; i < 4; i++) {
							int dx = cur.first + dirX[i];
							int dy = cur.second + dirY[i];

							if (dx < 0 || dy < 0 || dx >= n || dy >= m) continue;
							if (board[dx][dy] != 1 || visit[dx][dy] != 0) continue;
							visit[dx][dy] = 1;
							q.push({ dx, dy });
						}
					}
				}
			}
		}
		cout << result << '\n';
		result = 0;
		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);
			fill(visit[i], visit[i] + m, 0);
		}
	}
}