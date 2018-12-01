#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001][3] = { 0 };

int main()
{
	int n;
	cin >> n;
	int count = 0;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> dp[i][0];
		dp[i][1] = 1;
		dp[i][2] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[i][0] > dp[j][0] && dp[i][1] <= dp[j][1]) {
				dp[i][1] = dp[j][1] + 1;
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int k = n - 1; k > i; k--) {
			if (dp[i][0] > dp[k][0] && dp[i][2] <= dp[k][2]) {
				dp[i][2] = dp[k][2] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (ans < dp[i][1] + dp[i][2])
			ans = dp[i][1] + dp[i][2] - 1;
	}

	cout << ans << "\n";

	return 0;
}