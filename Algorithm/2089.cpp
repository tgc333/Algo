#include<iostream>
#include<cmath>
using namespace std;

int arr[1000001] = { 0 };

int main()
{
	long long n;
	cin >> n;
	int temp = n;
	int count = 0;
	if (n == 0) {
		cout << '0';
		return 0;
	}

	while (temp != 0) {
		arr[count] = abs(temp % 2);
		if (temp > 0) {
			temp /= -2;
		}
		else {
			if (temp % 2 != 0) {
				temp /= -2;
				temp++;
			}
			else temp /= -2;
		}
		count++;
	}

	arr[count] = abs(temp % 2);
	for (int i = count - 1; i >= 0; i--) {
		cout << arr[i];
	}
	return 0;
}