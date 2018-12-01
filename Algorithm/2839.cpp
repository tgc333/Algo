#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() 
{
	int count = 0;
	int n;
	int a, b;
	int flag = 0;
	cin >> n;

	a = n / 5;
	b = n % 5;

	count = n / 5;

	if (n % 5 == 0)
		flag = 1;

	for (int i = 0; i <= a; i++) {
		if (b % 3 == 0) {
			count += b / 3;
			flag = 1;
			break;
		}
		else {
			b += 5;
			count--;
		}
	}

	if (flag == 1)
		cout << count;
	else
		cout << "-1";
	

	return 0;
}