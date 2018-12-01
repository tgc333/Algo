#include<iostream>
using namespace std;

bool arr[1000001] = { 0 };

int main()
{
	int m, n;
	cin >> m >> n;
	int count = 0;

	for (int i = 2; i <= n; i++) {
		if (arr[i] == false) {
			for (int j = 2; j <= n / i; j++) {
				arr[i * j] = true;
			}
			if (i >= m)
				cout << i << "\n";
		}
	}

	return 0;
}