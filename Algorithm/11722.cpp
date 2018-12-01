#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001][2] = { 0 };

int main()
{
	int n;
	cin >> n;
	int count = 0;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> dp[i][0];
		dp[i][1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[i][0] < dp[j][0] && dp[i][1] <= dp[j][1]) {
				dp[i][1] = dp[j][1] + 1;
			}
		}
		if (ans < dp[i][1])
			ans = dp[i][1];
	}

	cout << ans << "\n";

	return 0;
}