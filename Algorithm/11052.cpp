#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int p[10001] = { 0 };
int dp[10001] = { 0 };

int main() 
{
	int n, max = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	dp[0] = p[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = p[i];
		for (int j = 1; j <= i/2; j++) {
		
			if (dp[i] < dp[i - j] + dp[j])
				dp[i] = dp[i - j] + dp[j];
		}
		
	}
	cout << dp[n];

	return 0;
}