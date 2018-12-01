#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int a[13][13] = { 0 };
int check[13][13] = { 0 };
int n, ans, pnum;

vector<pair<int, int>> v;

bool isline(int c, int x, int y, int ctemp[13][13]) {
	if (c == 0) {
		for (int i = x - 1; i >= 1; i--) {
			if (ctemp[i][y] != 0) {
				return false;
			}
		}
	}if (c == 1) {
		for (int i = y - 1; i >= 1; i--) {
			if (ctemp[x][i] != 0) {
				return false;
			}
		}
	}if (c == 2) {
		for (int i = x + 1; i <= n; i++) {
			if (ctemp[i][y] != 0) {
				return false;
			}
		}
	}if (c == 3) {
		for (int i = y + 1; i <= n; i++) {
			if (ctemp[x][i] != 0) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int p, int num, int ad[13][13]) {
	if (p == v.size()) {
		int cnt = 0;
		for (int k = 1; k <= n; k++) {
			for (int j = 1; j <= n; j++) {
				if (ad[k][j] == 1) {
					cnt++;
				}
			}
		}
		if (num > pnum) {	
			pnum = num;
			ans = cnt;
		}
		else if(num == pnum){
			ans = min(ans, cnt);
		}
	}	
	
	else {
		int ctemp[13][13];

		/*for (int k = 1; k <= n; k++) {
			for (int j = 1; j <= n; j++) {
				cout << ad[k][j];
			}
			cout << '\n';
		}
		cout << '\n';

		cout << p << ' ' << x << ' ' << y << "\n";*/

		int x = v[p].first;
		int y = v[p].second;
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			for (int k = 1; k <= n; k++) {
				for (int j = 1; j <= n; j++) {
					ctemp[k][j] = ad[k][j];
				}
			}
			if (isline(i, x, y, ad)) {
				if (i == 0) {
					for (int j = x - 1; j >= 1; j--) {
						ctemp[j][y] = 1;
					}
					dfs(p + 1, num + 1, ctemp);
					flag = 1;
				}
				if (i == 1) {
					for (int j = y - 1; j >= 1; j--) {
						ctemp[x][j] = 1;
					}
					dfs(p + 1, num + 1, ctemp);
					flag = 1;
				}
				if (i == 2) {
					for (int j = x + 1; j <= n; j++) {
						ctemp[j][y] = 1;
					}
					dfs(p + 1, num + 1, ctemp);
					flag = 1;
				}
				if (i == 3) {
					for (int j = y + 1; j <= n; j++) {
						ctemp[x][j] = 1;
					}
					dfs(p + 1, num + 1, ctemp);
					flag = 1;
				}
			}
		}
		if (flag == 0) {
			dfs(p + 1, num, ctemp);
		}
	}

}

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		ans = 99999999;
		pnum = 0;
		v.clear();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				check[i][j] = 0;
				a[i][j] = 0;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 1) {
					check[i][j] = 2;
					if (i == 1 || i == n || j == 1 || j == n) {
						continue;
					}
					v.push_back(make_pair(i, j));
				}
			}
		}
		dfs(0, 0, check);
		cout << "#" << tc << " " << ans << '\n';
	}

	return 0;
}