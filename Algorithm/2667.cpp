#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<pair<int, int>> a[1000];
int check[26][26] = { 0 };
int apart[26][26] = { 0 };

void dfs(int x, int y, int ans) {
	check[x][y] = 1;
	a[ans].push_back(make_pair(x, y));
	if (apart[x + 1][y] == 1 && check[x + 1][y] == 0) {
		dfs(x + 1, y, ans);
	}
	if (apart[x - 1][y] == 1 && check[x - 1][y] == 0) {
		dfs(x - 1, y, ans);
	}
	if (apart[x][y + 1] == 1 && check[x][y + 1] == 0) {
		dfs(x, y + 1, ans);
	}
	if (apart[x][y - 1] == 1 && check[x][y - 1] == 0) {
		dfs(x, y - 1, ans);
	}
}

bool vectorsort(vector<pair<int, int>> a, vector<pair<int, int>> b) {
	if (a.size() < b.size()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	cin >> n;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			apart[i + 1][j + 1] = s[j] - '0';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (apart[i][j] == 1 && check[i][j] == 0) {
				dfs(i, j, ans);
				ans++;
			}
		}
	}

	cout << ans << '\n';
	sort(a, a + ans, vectorsort);
	for (int i = 0; i < ans; i++) {
		cout << a[i].size() << '\n';
	}


	return 0;
}