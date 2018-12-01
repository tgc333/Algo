#include <iostream>
#include <algorithm>
using namespace std;

long long arr[2][100001] = { 0 };

long long d[100001][3] = { 0 };

int main()
{
	int t, n;

	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 100001; j++) {
				arr[i][j] = 0;
			}
		}
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < 100001; i++) {
			for (int j = 0; j < 3; j++) {
				d[i][j] = 0;
			}
		}

		d[0][0] = 0;
		d[0][1] = arr[0][0];
		d[0][2] = arr[1][0];

		for (int i = 1; i < n; i++) {
			d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] });
			d[i][1] = max({ d[i - 1][0]+arr[0][i], d[i - 1][2] + arr[0][i] });
			d[i][2] = max({ d[i - 1][0]+arr[1][i], d[i - 1][1] + arr[1][i] });
		}

		cout << max({ d[n - 1][0], d[n - 1][1], d[n - 1][2] }) << "\n";
	}

	return 0;
}