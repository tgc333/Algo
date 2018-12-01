#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int dp[31] = { 0 };

int main()
{
	int n;
	cin >> n;
	dp[0] = 1;
	dp[2] = 3;
	dp[4] = 11;

	for (int i = 6; i <= n; i+=2) {
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j+=2) {
			dp[i] += 2 * dp[i-j];
		}
	}

	cout << dp[n] << "\n";


	return 0;
}