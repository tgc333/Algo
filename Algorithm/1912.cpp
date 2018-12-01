#include<iostream>
#include<algorithm>
using namespace std;

int dp[100001][2] = { 0 };

int main()
{
	int n;
	cin >> n;
	int mini = -1001;
	int maxi = -1001;
	for (int i = 1; i <= n; i++) {
		cin >> dp[i][0];
	}

	dp[1][1] = dp[1][0];

	for (int i = 2; i <= n; i++) {
		dp[i][1] = max(dp[i - 1][1] + dp[i][0], dp[i][0]);
	}

	for (int i = 1; i <= n; i++) {
		if (dp[i][1] < 0 && dp[i][1] > mini) {
			mini = dp[i][1];
		}
		if (dp[i][1] > maxi) {
			maxi = dp[i][1];
		}
	}

	cout << max(maxi, mini);

	return 0;
}