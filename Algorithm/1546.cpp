#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	cout.setf(ios::fixed);

	int n;
	double arr[1000];
	double sum = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] / arr[n - 1] * 100;
		sum += arr[i];
	}
	//cout.precision(2);
	cout << sum / n;

	return 0;
}