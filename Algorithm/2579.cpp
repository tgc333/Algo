#include<iostream>
#include<algorithm>
using namespace std;

int dp[100001][2] = { 0 };

int main()
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> dp[i][0];
	}
	dp[0][0] = dp[0][1] = 0;
	dp[1][1] = dp[1][0];

	for (int i = 2; i <= n; i++) {
		dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + dp[i][0];
		dp[i][2] = dp[i - 1][1] + dp[i][0];
	}

	cout << max(dp[n][1], dp[n][2]) << "\n";

	return 0;
}