#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int ans = 0;

void dn(int n) {
	int arr[4];
	int c = 0;
	if (n < 100) {
		ans++;
		
	}
	else {
		while (n / 10 != 0) {
			arr[c] = n % 10;
			n /= 10;
			c++;
		}
		arr[c] = n;

		for (int i = 0; i <= c; i++)
			//cout << arr[i] << " ";

		for (int i = 0; i < c-1; i++) {
			if (arr[i] - arr[i + 1] != arr[i + 1] - arr[i + 2]) {
				return;
			}
		}
		ans++;
	}

	return;
}



int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dn(i);
	}

	cout << ans << "\n";

	return 0;
}