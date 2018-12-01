#include<iostream>
#include<algorithm>
using namespace std;

int dp[1001][2] = { 0 };
int main()
{
	int n;
	cin >> n;
	int count = 0;
	int maxi = 1;
	for (int i = 0; i < n; i++) {
		cin >> dp[i][0];
		dp[i][1] = 1;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[i][0] > dp[j][0]) {
				dp[i][1] = max((dp[j][1]) + 1, dp[i][1]);
				if (dp[i][1] > maxi)
					maxi = dp[i][1];
			}
		}
	}

	cout << maxi << "\n";

	return 0;
}