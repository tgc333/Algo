#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int D(int n) {
	return 2 * n % 10000;
}
int S(int n) {
	if (n == 0) {
		return 9999;
	}
	else {
		return n - 1;
	}
}
int L(int n) {
	int x = n / 1000;
	n %= 1000;
	n *= 10;
	n += x;
	return n;
}
int R(int n) {
	int x = n % 10;
	n /= 10;
	x *= 1000;
	x += n;
	return x;
}

int check[10001] = { 0 };
vector<pair<int, char>> v[10001];
queue<int> q;
int t, a, b;

void bfs() {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx;
			if (i == 0) {
				nx = D(x);
				if (check[nx] == 0) {
					q.push(nx);
					v[nx].push_back(make_pair(x, 'D'));
					check[nx] = 1;
				}
			}
			else if (i == 1) {
				nx = S(x);
				if (check[nx] == 0) {
					q.push(nx);
					v[nx].push_back(make_pair(x, 'S'));
					check[nx] = 1;
				}
			}
			else if (i == 2) {
				nx = L(x);
				if (check[nx] == 0) {
					q.push(nx);
					v[nx].push_back(make_pair(x, 'L'));
					check[nx] = 1;
				}
			}
			else if (i == 3) {
				nx = R(x);
				if (check[nx] == 0) {
					q.push(nx);
					v[nx].push_back(make_pair(x, 'R'));
					check[nx] = 1;
				}
			}
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		for (int i = 0; i < 10000; i++) {
			check[i] = 0;
			v[i].clear();
		}
		cin >> a >> b;
		q.push(a);
		check[a] = 1;
		v[a].push_back(make_pair(-1, -1));
		bfs();
		int temp = b;
		stack<char> s;
		while (v[temp][0].first != -1) {
			s.push(v[temp][0].second);
			temp = v[temp][0].first;
		}
		while (!s.empty()) {
			cout << s.top();
			s.pop();
		}
		cout << '\n';
	}

	return 0;
}