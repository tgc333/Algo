#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, int>> a[1001];
int check[1001] = { 0 };

void dfs(int x) {
	check[x] = 1;
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {
		if (check[a[x][i].first] == 0) {
			dfs(a[x][i].first);
		}
	}
}

int main() {
	int n, m, start;
	cin >> n >> m >> start;
	queue<int> q;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		a[s].push_back(make_pair(e, 1));
		a[e].push_back(make_pair(s, 1));
	}

	for (int i = 0; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(start);
	cout << '\n';
	for (int i = 0; i <= n; i++) {
		check[i] = 0;
	}

	check[start] = 1;
	cout << start;
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			if (check[a[x][i].first] == 0) {
				check[a[x][i].first] = 1;
				q.push(a[x][i].first);
				cout << ' ' << a[x][i].first;
			}
		}
	}

	return 0;
}