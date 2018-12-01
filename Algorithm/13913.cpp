#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

int check[100001] = { 0 };
int parent[100001] = { 0 };
queue<int> q;
stack<int> s;
int n, k;

void bfs(void) {
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx;
			if (i == 0) {
				nx = x + 1;
			}
			else if (i == 1) {
				nx = x - 1;
			}
			else if (i == 2) {
				nx = x * 2;
			}
			if (0 <= nx && nx <= 100000) {
				if (check[nx] == 0) {
					check[nx] = check[x] + 1;
					parent[nx] = x;
					q.push(nx);
				}
			}
		}
	}
}

int main() {
	cin >> n >> k;
	check[n] = 1;
	parent[n] = -1;
	q.push(n);
	bfs();

	cout << check[k] - 1 << '\n';

	int temp = k;
	while (parent[temp] != -1) {
		s.push(parent[temp]);
		temp = parent[temp];
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << k;

	return 0;
}