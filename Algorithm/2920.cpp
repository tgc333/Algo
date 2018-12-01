#include<iostream>
using namespace std;



int main()
{
	int arr[9] = { 0 };
	int flag = 0;
	for (int i = 1; i <= 8; i++) {
		cin >> arr[i];
	}

	if (arr[1] == 8) {
		for (int i = 0; i < 8; i++) {
			if (arr[i + 1] == 8 - i)
				flag = 2;
			else {
				flag = 0;
				break;
			}
		}
	}
	else if (arr[1] == 1) {
		for (int i = 1; i <= 8; i++) {
			if (arr[i] == i)
				flag = 1;
			else {
				flag = 0;
				break;
			}
		}
	}

	if (flag == 1) {
		cout << "ascending" << "\n";
	}else if (flag == 2) {
		cout << "descending" << "\n";
	}
	else {
		cout << "mixed" << "\n";
	}

	return 0;
}