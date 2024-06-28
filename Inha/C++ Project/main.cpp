#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int board[502][502] = { -1 };
int visit[502][502] = { -1 };
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { -1, 1, 0, 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	}

	int max = 0;
	int cnt = 0;
	int temp = 1;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{

			if (board[i][j] == 1 && visit[i][j] != 1)
			{
				visit[i][j] = 1;
				q.push({ i, j });
				cnt++;
				while (!q.empty())
				{
					pair<int, int> cur = q.front();
					q.pop();
					for (int i = 0; i < 4; i++) {
						int dx = cur.first + dir_x[i];
						int dy = cur.second + dir_y[i];
						if (dx < 0 || dy < 0 || dx >= n || dy >= m)
							continue;

						if (visit[dx][dy] == 1 || board[dx][dy] == 0)
							continue;

						visit[dx][dy] = 1;
						q.push({ dx, dy });
						temp++;
					}
					if (temp > max) max = temp;
				}
			}
			temp = 1;
		}
	}
	cout << cnt << '\n' << max;
}