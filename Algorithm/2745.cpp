#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	int b;
	long long ans = 0;
	string s;
	int ni[100] = { 0 };
	cin >> s >> b;
	for (int i = 0; i < s.length(); i++) {
		ni[i] = s[i] - '0';
		if (ni[i] > 10) {
			ni[i] = ni[i] - 'A' + 10 + '0';
		}
	}

	for (int i = 0; i < s.length(); i++) {
		ni[i] = pow(b, s.length() - 1 - i) * ni[i];
		ans += ni[i];
	}
	cout << ans << "\n";

	return 0;
}