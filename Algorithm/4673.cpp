#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;


int arr[10001] = { 0 };

void dn(int n) {
	if (n > 10000)
		return;

	int sum = 0;
	sum += n;
	while (n / 10 != 0) {
		sum += n % 10;
		n /= 10;
	}
	sum += n;
	arr[sum] = 0;
	dn(sum);
}



int main()
{
	for (int i = 1; i < 10001; i++) {
		arr[i] = i;
	}
	for (int i = 1; i < 10001; i++) {
		dn(i);
	}

	for (int i = 1; i < 10001; i++) {
		if (arr[i] != 0)
			cout << arr[i] << "\n";
		
	}

	return 0;
}