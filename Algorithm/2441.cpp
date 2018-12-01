#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0; j--)
			cout << " ";
		for (int j = n - i; j > 0; j--)
			cout << "*";
		cout << "\n";
	}


	return 0;
}