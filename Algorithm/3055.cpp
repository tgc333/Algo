#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

char forest[51][51] = { 0 };
int check[51][51] = { 0 };
int dist[51][51] = { 0 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pair<int, int>> q, q2, biberq, biberq2;
int r, c;

void bfs(void) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx && nx <= r && 1 <= ny && ny <= c) {
				if (check[nx][ny] != 1 && forest[nx][ny] != 'D' && forest[nx][ny] != 'X') {
					q2.push(make_pair(nx, ny));
					forest[nx][ny] = '*';
					check[nx][ny] = 1;
				}
			}
		}
	}
}

void bfsbiber(void) {
	while (!biberq.empty()) {
		int x = biberq.front().first;
		int y = biberq.front().second;
		biberq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx && nx <= r && 1 <= ny && ny <= c) {
				if (check[nx][ny] == 0 && forest[nx][ny] != '*' && forest[nx][ny] != 'X') {
					check[nx][ny] = 2;
					dist[nx][ny] = dist[x][y] + 1;
					biberq2.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> r >> c;
	int destx, desty;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			forest[i + 1][j + 1] = s[j];
			if (forest[i + 1][j + 1] == '*') {
				q.push(make_pair(i + 1, j + 1));
				check[i + 1][j + 1] = 1;
			}
			if (forest[i + 1][j + 1] == 'S') {
				biberq.push(make_pair(i + 1, j + 1));
				check[i + 1][j + 1] = 2;
				dist[i + 1][j + 1] = 0;
			}
			if (forest[i + 1][j + 1] == 'D') {
				destx = i + 1; desty = j + 1;
			}
		}
	}

	while (!q.empty() || !biberq.empty()) {
		bfs();
		bfsbiber();
		while (!q2.empty()) {
			q.push(make_pair(q2.front().first, q2.front().second));
			q2.pop();
		}
		while (!biberq2.empty()) {
			biberq.push(make_pair(biberq2.front().first, biberq2.front().second));
			biberq2.pop();
		}
	}

	if (dist[destx][desty] == 0) {
		cout << "KAKTUS\n";
	}
	else {
		cout << dist[destx][desty] << '\n';
	}
	return 0;
}