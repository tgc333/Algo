#include <iostream>
using namespace std;

int main()
{
	long long arr[1001][10] = { 0 };
	int n;
	cin >> n;
	int sum = 0;

	for (int i = 0; i <= 9; i++)
		arr[1][i] = 1;

	for (int i = 2; i <= 1000; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				arr[i][j] += arr[i - 1][k];
			}
			arr[i][j] %= 10007;
		}
	}

	for (int i = 0; i <= 9; i++)
		sum += arr[n][i];
	sum %= 10007;
	cout << sum << "\n";

	return 0;
}