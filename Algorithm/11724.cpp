#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int>> a[1000*999/2];
int check[10000001] = { 0 };

int dfs(int x) {
	if (check[x] == 1) {
		return 0;
	}
	else {
		check[x] = 1;
		for (int i = 0; i < a[x].size(); i++) {
			if (check[a[x][i].first] == 0) {
				dfs(a[x][i].first);
			}
		}
	}
	return 1;
}



int main() {

	int n, m;
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(make_pair(v, 1));
		a[v].push_back(make_pair(u, 1));
	}

	for (int i = 1; i <= n; i++) {
		if (dfs(i)) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}