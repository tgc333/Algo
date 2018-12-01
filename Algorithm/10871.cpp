#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, x;
	int temp;
	cin >> n >> x;

	while (n--) {
		cin >> temp;
		if (temp < x)
			cout << temp << " ";
	}

	return 0;
}