#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<stack>
using namespace std;

typedef struct point {
	int x;
	int y;
}point;

stack<point> st;
int farm[51][51] = { 0 };
int warmcount = 0;
int arr[101] = { 0 };

bool search(int x, int y) {
	if (x < 0 || y < 0) {
		return false;
	}
	else if (x > 50 || y > 50) {
		return false;
	}
	else if (farm[x][y] == 0) {
		return false;
	}
	else if (farm[x][y] == 1) {
		point p;
		p.x = x;
		p.y = y;
		st.push(p);
		farm[x][y] = 0;
		search(x + 1, y);
		search(x, y - 1);
		search(x - 1, y);
		search(x, y + 1);
		//printf("(%d,%d), %d\n", x, y, warmcount);
	}
	if (st.size() > 0)
		return true;
	else
		return false;
}

int main() {
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++) {
		warmcount = 0;
		int m, n, k;

		scanf("%d %d %d", &m, &n, &k);

		for (int x = 0; x < m; x++)
			for (int y = 0; y < n; y++)
				farm[x][y] = 0;

		for (int j = 0; j < k; j++) {
			int x, y;
			scanf("%d %d", &x, &y);
			farm[x][y] = 1;
		}

		for (int x = 0; x < m; x++) {
			for (int y = 0; y < n; y++) {
				bool cc = false;
				cc = search(x, y);
				if (cc) {
					warmcount++;
					while (!st.empty()) {
						st.pop();
					}
				}
			}
		}
		arr[i] = warmcount;
		//printf("%d\n", warmcount);
	}

	for (int i = 0; i < testcase; i++) {
		printf("%d\n", arr[i]);
	}
}