#include<iostream>
using namespace std;


int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}

int lcm(int a, int b, int g) {
	return a*b / g;
}

int main()
{
	int a, b, g;
	cin >> a >> b;
	g = gcd(a, b);
	cout << g << "\n" << lcm(a, b, g) << "\n";

	return 0;
}