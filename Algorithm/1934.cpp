#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int lcm(int a, int b, int g) {
	return a*b / g;
}

int main()
{
	int t;
	cin >> t;

	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << a*b / gcd(a, b) << "\n";
	}

	return 0;
}