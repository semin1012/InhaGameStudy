#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

char board[102][102];
bool visit[102][102];
int dir_x[4] = { 0, 0, 1, -1 };
int dir_y[4] = { 1, -1, 0, 0 };

int bfs(int n)
{
	int result= 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false)
			{
				q.push({ j, i });
				result++;
				visit[i][j] = true;
				while (!q.empty()) {
					auto cur = q.front(); q.pop();

					for (int i = 0; i < 4; i++) {
						int dx = cur.first + dir_x[i];
						int dy = cur.second + dir_y[i];

						if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
						if (board[i][j] != board[dy][dx]) continue;
						if (visit[dy][dx] == true ) continue;

						visit[dy][dx] = true;
						q.push({ dx, dy });
					}
				}
			}
		}
	}

	return result;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	int result = bfs(n);


	cout << result << endl;
}