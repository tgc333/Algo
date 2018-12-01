#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
using namespace std;

int n, m, k, ans;
int dx[5] = { 0, -1,1,0,0 };
int dy[5] = { 0, 0,0,-1,1 };

struct point {
	int x, y;
	int num;
	int dir;
};

queue<point> q;
vector<point> v[101][101];
point p;
point pushp;
point tempp;
point bp;

void bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].size() > 0) {
				pushp.num = 0;
				int sum = 0;
				for (int u = 0; u < v[i][j].size(); u++) {
					tempp = v[i][j][u];
					if (pushp.num < tempp.num) {
						pushp.num = tempp.num;
						pushp.dir = tempp.dir;
					}
					sum += tempp.num;
				}
				pushp.num = sum;
				pushp.x = i;
				pushp.y = j;
				v[i][j].clear();
				q.push(pushp);
			}
		}
	}

	int sz = q.size();
	while (sz--) {
		bp = q.front();
		q.pop();
		int x = bp.x;
		int y = bp.y;
		int num = bp.num;
		int dir = bp.dir;
		for (int i = 1; i <= 4; i++) {
			if (dir == i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx == 0 || nx == n - 1|| ny == 0 || ny == n - 1) {
					num /= 2;
					if (i == 1) dir = 2;
					if (i == 2) dir = 1;
					if (i == 3) dir = 4;
					if (i == 4) dir = 3;
				}
				tempp.x = nx;
				tempp.y = ny;
				tempp.num = num;
				tempp.dir = dir;
				v[nx][ny].push_back(tempp);
				break;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> m >> k;
		ans = 0;
		
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; l++) {
				v[j][l].clear();
			}
		}

		for (int j = 0; j < k; j++) {
			int x, y, num, dir;
			cin >> x >> y >> num >> dir;
			p.x = x; p.y = y;
			p.num = num;
			p.dir = dir;
			v[x][y].push_back(p);
		}

		for (int j = 0; j < m; j++) {
			bfs();
		}
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; l++) {
				if (v[j][l].size() > 0) {
					for (int u = 0; u < v[j][l].size(); u++) {
						ans += v[j][l][u].num;
					}
				}
			}
		}
		cout << '#' << i << ' ' << ans << '\n';
	}
	return 0;
}