#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int n = s.length();

	if (n % 3 == 1) {
		cout << s[0]-'0';
	}
	else if (n % 3 == 2) {
		cout << (s[0] - '0') * 2 + s[1] - '0';
	}
	for (int i = n % 3; i < n; i+=3) {
		cout << (s[i] - '0') * 4 + (s[i+1] - '0') * 2 + s[i+2] - '0';
	}

	return 0;
}
