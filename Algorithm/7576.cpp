#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int tomato[1001][1001] = { 0 };
int check[1001][1001] = { 0 };
int dist[1001][1001] = { 0 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q;
int n, m;

void bfs(void) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
				if (check[nx][ny] == 0 && tomato[nx][ny] == 0) {
					tomato[nx][ny] = 1;
					dist[nx][ny] = dist[x][y] + 1;
					check[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		q.pop();
	}
}

int main() {
	int ans = 0;
	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = 1;
				dist[i][j] = 1;
			}
			else if (tomato[i][j] == -1) {
				dist[i][j] = -1;
			}
		}
	}

	bfs();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(ans, dist[i][j]);
			if (dist[i][j] == 0) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << ans - 1 << '\n';

	return 0;
}