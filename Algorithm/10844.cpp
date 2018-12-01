#include <iostream>
using namespace std;

int main()
{
	long long arr[101][10];

	for (int i = 1; i <= 9; i++) {
		arr[1][i] = 1;
	}
	arr[1][0] = 0;
	
	for (int i = 1; i < 9; i++) {
		arr[2][i] = arr[1][i - 1] + arr[1][i + 1];
	}
	arr[2][0] = arr[1][1];
	arr[2][9] = arr[1][8];

	for (int i = 3; i <= 100; i++) {
		for (int j = 1; j < 9; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
			arr[i][j] %= 1000000000;
		}
		arr[i][0] = arr[i - 1][1];
		arr[i][9] = arr[i - 1][8];
	}

	int n, sum = 0;

	cin >> n;

	for (int i = 0; i <= 9; i++) {
		sum += arr[n][i];
		sum %= 1000000000;
	}

	cout << sum << "\n";

	return 0;
}