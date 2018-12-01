#include<iostream>
#include<cmath>
using namespace std;

int arr[50000001] = { 0 };

int main()
{
	long long n, b;
	cin >> n >> b;
	long long temp;
	int count = 0;
	while (n != 0) {
		temp = n % b;
		n /= b;
		arr[count] = temp;
		count++;
	}

	for (int i = count - 1; i >= 0; i--) {
		if (arr[i] > 9) {
			cout << (char)(arr[i] + 'A' - 10);
		}
		else
			cout << arr[i];
	}

	return 0;
}