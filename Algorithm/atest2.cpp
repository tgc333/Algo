#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;

int a[11][11];

vector<pair<int, int>> vp, vs;
vector<int> vtemp[150];
queue<pair<int, int>> qtemp;
int n, ans;

void dfs(int p) {
	if (p == vp.size()) {
		int time = 0;
		//cout << '\n';
		for (int i = 0; i < vs.size(); i++) {
			vector<int> v = vtemp[i];
			int sz = v.size();
			int cnt = 0;
			
			sort(v.begin(), v.end());
			for (int j = 0; j < sz; j++) {
				qtemp.push(make_pair(v[j], a[vs[i].first][vs[i].second]));
			}
			while (!qtemp.empty()) {
				int flag = 0;
				int qsz = qtemp.size();
				for (int j = 0; j < qsz; j++) {
					int x = qtemp.front().first;
					int y = qtemp.front().second;
					qtemp.pop();
					//cout << x << ' ';
					if (y <= 0) {
						flag++;
					}
					else {
						if (j < 3 + flag && cnt >= x) {
							qtemp.push(make_pair(x, y - 1));
						}
						else 
							qtemp.push(make_pair(x, y));
					}
					
				}
				cnt++;
			}
			time = max(time, cnt);
			//cout << time << "!!\n";
		}
		ans = min(time, ans);
	}
	else {
		int c = vp[p].first;
		int r = vp[p].second;
		int time;
		for (int i = 0; i < vs.size(); i++) {
			 time = abs(c - vs[i].first) + abs(r - vs[i].second);
			 vtemp[i].push_back(time);
			 dfs(p + 1);
			 vtemp[i].pop_back();
		}
	}
}

int main() {
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> n;
		vp.clear();
		vs.clear();
		ans = 99999;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				a[j][k] = 0;
				cin >> a[j][k];
				if (a[j][k] == 1) {
					vp.push_back(make_pair(j, k));
				}
				else if (a[j][k] > 1) {
					vs.push_back(make_pair(j, k));
				}
			}
		}
		
		dfs(0);
		cout << "#" << i << ' ' << ans << '\n';
	}

	return 0;
}