#include<iostream>
using namespace std;

int main()
{
	int arr[6] = { 0 };
	int sum = 0;
	for (int i = 1; i <= 5; i++) {
		cin >> arr[i];
		if (arr[i] < 40)
			arr[i] = 40;
		sum += arr[i];
	}

	cout << sum / 5 << "\n";

	return 0;
}