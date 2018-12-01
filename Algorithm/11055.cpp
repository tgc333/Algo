#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001][2] = { 0 };

int main()
{
	int n;
	cin >> n;
	int count = 0;
	int sum = 0;
	int maxi;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> dp[i][0];
		dp[i][1] = dp[i][0];
	}

	for (int i = 0; i < n; i++) {
		maxi = 0;
		for (int j = 0; j < i; j++) {
			if (dp[i][0] > dp[j][0] && dp[j][1] > maxi) {
				maxi = dp[j][1];				
			}
		}
		dp[i][1] += maxi;
	}

	for (int i = 0; i < n; i++) {
		//cout << dp[i][1] << " ";
		if (ans < dp[i][1])
			ans = dp[i][1];
		//ans = max(ans, dp[i][1]);
	}

	cout << ans << "\n";

	return 0;
}