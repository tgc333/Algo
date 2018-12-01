#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> a[100001];
int check[100001];
int num[100001];
int ans;
void dfs(int x, int start, int cnt) {
	check[x] = start;
	num[x] = cnt;
	for (int i = 0; i < a[x].size(); i++) {
		if (check[a[x][i].first] == 0) {
			dfs(a[x][i].first, start, cnt + 1);
		}
		if (check[a[x][i].first] == check[x]) {
			ans += num[x] - num[a[x][i].first] + 1;
			return;
		}
	}
}

int main() {
	int t, n, d, cnt;
	cin >> t;
	while (t--) {
		cin >> n;
		cnt = 1;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			a[i].clear();
			check[i] = 0;
			num[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			cin >> d;
			a[i].push_back(make_pair(d, 1));
		}
		for (int i = 1; i <= n; i++) {
			if (check[i] == 0) {
				dfs(i, i, 1);
			}
		}
		cout << n - ans << '\n';
	}


	return 0;
}