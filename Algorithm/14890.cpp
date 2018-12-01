#include<iostream>
#include<cmath>
using namespace std;


int arr[101][101] = { 0 };

int main()
{
	int n, l, count = 0;
	cin >> n >> l;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		int flag = 1;
		int type[101] = { 0 };
		for (int j = 1; j <= n - 1; j++) {
			if (arr[i][j] == arr[i][j + 1]) {
				continue;
			}
			else if (abs(arr[i][j] - arr[i][j + 1]) >= 2) {
				flag = 0;
				break;
			}
			else if (arr[i][j] - arr[i][j + 1] == 1) {
				if (n - j < l) {
					flag = 0;
					break;
				}
				for (int k = j + 1; k <= j + l; k++) {
					if (arr[i][j] - arr[i][k] != 1) {
						flag = 0;
						break;
					}
					else {
						if (type[k] == 0) {
							type[k] = 1;
						}
						else if (type[k] == 1) {
							flag = 0;
							break;
						}
					}
				}
				if (flag == 1) {
					j += l - 1;
					continue;
				}
			}
			
			else if (arr[i][j] - arr[i][j + 1] == -1) {
				if (j - l + 1 < 1) {
					flag = 0;
					break;
				}
				for (int k = j - l + 1; k <= j; k++) {
					if (arr[i][k] - arr[i][j + 1] != -1) {
						flag = 0;
						break;
					}
					else {
						if (type[k] == 0) {
							type[k] = 1;
						}
						else if (type[k] == 1) {
							flag = 0;
							break;
						}
					}
				}
			}
		}

		if (flag == 1) {
			count++;
		}
	}

	for (int i = 1; i <= n; i++) {
		int flag = 1;
		int type[101] = { 0 };
		for (int j = 1; j <= n - 1; j++) {
			if (arr[j][i] == arr[j + 1][i]) {
				continue;
			}
			else if (abs(arr[j][i] - arr[j + 1][i]) >= 2) {
				flag = 0;
				break;
			}
			else if (arr[j][i] - arr[j + 1][i] == 1) {
				if (n - j < l) {
					flag = 0;
					break;
				}
				for (int k = j + 1; k <= j + l; k++) {
					if (arr[j][i] - arr[k][i] != 1) {
						flag = 0;
						break;
					}
					else {
						if (type[k] == 0) {
							type[k] = 1;
						}
						else if (type[k] == 1) {
							flag = 0;
							break;
						}
					}
				}
				if (flag == 1) {
					j += l - 1;
					continue;
				}
			}

			else if (arr[j][i] - arr[j + 1][i] == -1) {
				if (j - l + 1 < 1) {
					flag = 0;
					break;
				}
				for (int k = j - l + 1; k <= j; k++) {
					if (arr[k][i] - arr[j + 1][i] != -1) {
						flag = 0;
						break;
					}
					else {
						if (type[k] == 0) {
							type[k] = 1;
						}
						else if (type[k] == 1) {
							flag = 0;
							break;
						}
					}
				}
			}
		}

		if (flag == 1) {
			count++;
		}
	}

	cout << count << "\n";

	return 0;
}