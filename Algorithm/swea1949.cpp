#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int n, k;
int a[9][9] = { 0 };

vector<pair<int, int>> v;


void dfs() {
	check[]
}

int main() {
	int t;
	int maxi = 0;
	cin >> t;
	for (int q = 1; q <= t; q++) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				maxi = max(maxi, a[i][j]);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] == maxi) {
					v.push_back(make_pair(i, j));
				}
			}
		}

	}

	return 0;
}