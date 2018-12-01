#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 2; i * i <= n; i++) {
		while (n%i == 0) {
			n /= i;
			cout << i << "\n";
		}
	}
	if (n > 1) {
		cout << n;
	}
	return 0;
}
