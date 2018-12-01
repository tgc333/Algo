#include<iostream>
#include<string>
using namespace std;
long long dp[5001] = { 0 };
int arr[5001] = { 0 };
int main()
{
	string s;
	cin >> s;
	int temp;

	for (int i = 0; i < s.length(); i++) {
		arr[i + 1] = s[i] - 48;
		if (arr[i + 1] < 0 || arr[i] > 9) {
			cout << "0\n";
			return 0;
		}
	}

	dp[0] = 1;
	arr[0] = 0;

	if (arr[1] == 0) {
		cout << "0\n";
		return 0;
	}

	
	for (int i = 1; i <= s.length(); i++) {
		temp = arr[i - 1] * 10 + arr[i];

		 if (temp <= 26 && temp >= 10) {
			if (temp == 10 || temp == 20) {
				dp[i] = dp[i - 2] % 1000000;
			}
			else {
				dp[i] = dp[i - 2] + dp[i - 1] % 1000000;
			}
		}
		else if (arr[i] <= 9 && arr[i] >= 1) {
			dp[i] = dp[i - 1] % 1000000;
		}
		else {
			cout << "0\n";
			return 0;
		}
	}
	
	cout << dp[s.length()] % 1000000 << "\n";


	

	return 0;
}