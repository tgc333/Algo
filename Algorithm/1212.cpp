#include<iostream>
#include<string>
using namespace std;

int n[333335] = { 0 };
string eight[8] = { "000", "001", "010", "011", "100", "101", "110", "111"};
int main()
{
	string s;

	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		n[i] = s[i] - '0';
	}
	
	if (n[0] == 1) {
		cout << "1";
	}
	else if (n[0] == 2)
		cout << "10";
	else if (n[0] == 3)
		cout << "11";
	else if (n[0] == 0)
		cout << '0';
	else {
		cout << eight[n[0]];
	}

	for (int i = 1; i < s.length(); i++) {
		cout << eight[n[i]];
	}

	cout << '\n';
	return 0;
}