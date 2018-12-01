#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long dp[101] = { 0 };

int main()
{
	int t, n;
	cin >> t;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	dp[7] = 4;
	dp[8] = 5;
	dp[9] = 7;
	dp[10] = 9;

	for (int i = 11; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}


	while (t--) {
		cin >> n;
		cout << dp[n] << "\n";

	}
	
	return 0;
}