#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

vector<pair<int, int>> a[1000];
int check[51][51] = { 0 };
int island[51][51] = { 0 };

void dfs(int x, int y) {
	check[x][y] = 1;
	if (island[x + 1][y] == 1 && check[x + 1][y] == 0) {
		dfs(x + 1, y);
	}
	if (island[x - 1][y] == 1 && check[x - 1][y] == 0) {
		dfs(x - 1, y);
	}
	if (island[x][y + 1] == 1 && check[x][y + 1] == 0) {
		dfs(x, y + 1);
	}
	if (island[x][y - 1] == 1 && check[x][y - 1] == 0) {
		dfs(x, y - 1);
	}
	if (island[x + 1][y + 1] == 1 && check[x + 1][y + 1] == 0) {
		dfs(x + 1, y + 1);		
	}
	if (island[x - 1][y + 1] == 1 && check[x - 1][y + 1] == 0) {
		dfs(x - 1, y + 1);
	}
	if (island[x - 1][y - 1] == 1 && check[x - 1][y - 1] == 0) {
		dfs(x - 1, y - 1);
	}
	if (island[x + 1][y - 1] == 1 && check[x + 1][y - 1] == 0) {
		dfs(x + 1, y - 1);
	}
}

int main() {
	
	while (1) {
		int w, h;
		cin >> h >> w;
		for (int i = 0; i <= w; i++) {
			for (int j = 0; j <= h; j++) {
				check[i][j] = 0;
				island[i][j] = 0;
			}
		}
		if (w == 0 && h == 0)
			break;

		int ans = 0;

		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				cin >> island[i][j];
			}
		}

		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				if (check[i][j] == 0 && island[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	


	return 0;
}