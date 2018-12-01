#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


vector<pair<int, int>> a[20001];
int check[20001] = { 0 };


void dfs(int x, int flag) {
	check[x] = flag;
	flag *= -1;
	for (int i = 0; i < a[x].size(); i++) {
		if (check[a[x][i].first] == 0) {
			dfs(a[x][i].first, flag);
		}
	}
}



int main() {

	int t, n, m;
	cin >> t;

	while (t--) {
		for (int i = 0; i < 20001; i++) {
			a[i].clear();
			check[i] = 0;
		}
		int ans = 1;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			a[u].push_back(make_pair(v, 1));
			a[v].push_back(make_pair(u, 1));
		}

		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				dfs(i, 1);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				if (check[i] == check[a[i][j].first]) {
					ans = 0;
				}
			}
		}
		if (ans == 0) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
		}

	}

	return 0;
}