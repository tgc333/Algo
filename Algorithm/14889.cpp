#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int a[21][21] = { 0 };
int flag[21] = { 0 };
vector<int> vs, vl;
int n;
int ssum, lsum, ans = 999999;

void combination(int x, int cnt) {
	if (cnt == 0) {
		for (int i = 1; i <= n; i++) {
			flag[i] = 0;
		}
		ssum = 0;
		lsum = 0;
		vl.clear();
		for (int i = 0; i < vs.size(); i++) {
			flag[vs[i]] = 1;
		}
		for (int i = 1; i <= n; i++) {
			if (flag[i] == 0) {
				vl.push_back(i);
			}
		}

		for (int i = 0; i < vs.size(); i++) {
			for (int j = i + 1; j < vs.size(); j++) {
				ssum += a[vs[i]][vs[j]];
				ssum += a[vs[j]][vs[i]];

			}
		}

		for (int i = 0; i < vl.size(); i++) {
			for (int j = i + 1; j < vl.size(); j++) {
				lsum += a[vl[i]][vl[j]];
				lsum += a[vl[j]][vl[i]];
			}
		}

		ans = min(ans, abs(ssum - lsum));
		return;
	}
	
	for (int i = x; i <= n; i++) {
		vs.push_back(i);
		combination(i + 1, cnt - 1);
		vs.pop_back();
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	combination(1, n / 2);

	cout << ans << '\n';

	return 0;
}