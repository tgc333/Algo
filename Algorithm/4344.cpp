#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cout.setf(ios::fixed);
	cout.precision(3);
	double c, n;
	int arr[1001];
	cin >> c;

	while (c--) {
		cin >> n;
		double sum = 0;
		double count = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		sum /= n;
		for (int i = 0; i < n; i++) {
			if (arr[i] > sum)
				count++;
		}
		cout << count / n * 100 << "%\n";
	}

	return 0;
}