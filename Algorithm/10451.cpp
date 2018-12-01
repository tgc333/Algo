#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int, int>> a[1001];
int check[1001];

void dfs(int x) {
	check[x] = 1;
	for (int i = 0; i < a[x].size(); i++) {
		if (check[a[x][i].first] == 0) {
			dfs(a[x][i].first);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, cnt=0;
		cin >> n;

		for (int i = 0; i<= n; i++) {
			check[i] = 0;
			a[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			cin >> m;
			a[i].push_back(make_pair(m, 1));
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}