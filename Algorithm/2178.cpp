#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int miro[101][101] = { 0 };
int check[101][101] = { 0 };
int dist[101][101] = { 0 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n, m;
queue<pair<int, int>> q;

void bfs(int x, int y) {
	q.push(make_pair(x, y));
	check[x][y] = 1;
	dist[x][y] = 1;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;

		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
				if (miro[nx][ny] == 1 && check[nx][ny] == 0) {
					check[nx][ny] = 1;
					dist[nx][ny] = dist[a][b] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		q.pop();
	}
	cout << dist[n][m] << '\n';
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			miro[i + 1][j + 1] = s[j] - '0';
		}
	}

	bfs(1, 1);

	return 0;
}