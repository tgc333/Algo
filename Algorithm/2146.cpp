#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int mapi[101][101] = { 0 };
int check[1001][1001] = { 0 };
int dist[1001][1001] = { 0 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q, q2;
int n, ans = 9999999;

void bfswater(void) {
	while (!q2.empty()) {
		int x = q2.front().first;
		int y = q2.front().second;
		q2.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
				if (check[nx][ny] == 0 && dist[nx][ny] == 0) {
					check[nx][ny] = check[x][y];
					dist[nx][ny] = dist[x][y] + 1;
					q2.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void bfsisland(int cnt) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
				if (check[nx][ny] == 0 && mapi[nx][ny] == 1) {
					check[nx][ny] = cnt;
					dist[nx][ny] = 0;
					q.push(make_pair(nx, ny));
				}
				else if (check[nx][ny] == 0 && mapi[nx][ny] == 0) {
					q2.push(make_pair(nx, ny));
					check[nx][ny] = cnt;
					dist[nx][ny] = 1;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mapi[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mapi[i][j] == 1 && check[i][j] == 0) {
				check[i][j] = cnt;
				dist[i][j] = 0;
				q.push(make_pair(i, j));
				bfsisland(cnt);
				cnt++;
			}
		}
	}
	bfswater();
	int ans = 9999999;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (1 <= nx && nx <= n && 1 <= ny && ny <= n) {
					if (check[i][j] != check[nx][ny]) {
						ans = min(ans, dist[i][j] + dist[nx][ny]);
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}