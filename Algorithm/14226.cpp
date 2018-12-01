#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int check[2002][2002] = { 0 };
queue<pair<int, int>> q;

int s, cnt = 0;

void bfs(void) {
	while (!q.empty()) {
		int sz = q.size();
		while (sz--) {
			int x = q.front().first;
			int size = q.front().second;

			//cout << x << ' ' << size << ' ' << check[x][size] - 1<< '\n';
			q.pop();
			if (x == s) {
				cout << check[x][size] - 1 << '\n';
				return;
			}
			if (check[x][x] == 0 && x <= 1000) {
				q.push(make_pair(x, x));
				check[x][x] = check[x][size] + 1;
			}

			if (size != -1) {
				int nx = x + size;
				if (check[nx][size] == 0 && nx <= 1000) {
					check[nx][size] = check[x][size] + 1;
					q.push(make_pair(nx, size));
				}
			}
			int nx = x - 1;
			if (check[nx][size] == 0 && nx > 1) {
				check[nx][size] = check[x][size] + 1;
				q.push(make_pair(nx, size));
			}
		}
	}
}

int main() {
	cin >> s;
	check[1][0] = 1;
	q.push(make_pair(1, 0));
	bfs();
	
	return 0;
}