#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long dp[201][201] = { 0 };

int main()
{
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i <= 200; i++) {
		dp[i][1] = 1;
		dp[0][i] = 1;
		dp[1][i] = i;
	}

	for (int i = 2; i <= 200; i++) {
		for (int j = 2; j <= 200; j++) {
			for (int l = 0; l <= i; l++) {
				dp[i][j] += dp[l][j-1];
				dp[i][j] %= 1000000000;
				//cout << "dp[" << i << "][" << j << "] += dp[" << k << "][" << j - 1 << "]\n";
			}
			//cout << "dp[" << i << "][" << j << "] : " << dp[i][j] << "\n";
		}
	}

	cout << dp[n][k] % 1000000000 << "\n";
	

	return 0;
}