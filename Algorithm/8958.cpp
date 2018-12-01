#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{
	char arr[81] = { 0 };
	int t;
	int count = 0;

	cin >> t;

	while (t--) {
		int sum = 0;
		count = 0;
		for (int i = 0; i < 81; i++) {
			arr[i] = 0;
		}

		cin >> arr;
		for (int i = 0; i < 81; i++) {
			if (arr[i] == '\0') {
				break;
			}
			if (arr[i] == 'O') {
				count++;
				sum += count;
			}
			if (arr[i] == 'X' && arr[i - 1] == 'O') {
				count = 0;
			}
		}
		cout << sum << "\n";
		
	}

	return 0;
}