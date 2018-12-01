#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int board[1001][1001];
int dp[1001][1001] = { 0 };
int main() {

	int n, m;
	string s;

	cin >> n >> m;
	int length = 0;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			board[i][j] = s[j]-'0';
			if (board[i][j] == 1) {
				dp[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (board[i][0] == 1 || board[0][i] == 1) {
			length = 1;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (board[i][j] == 0)
				continue;
			else {
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;
				length = max(length, dp[i][j]);
			}
		}
	}

	cout << length * length << '\n';

	return 0;
}