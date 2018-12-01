#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int locate[26] = { 0 };
	for (int i = 0; i < 26; i++)
		locate[i] = -1;

	string s;
	cin >> s;
	

	for (int i = 0; i < s.length(); i++) {
		if (locate[((int)s[i] - 97)] == -1) {
			locate[(int)(s[i] - 97)] = i;
		}
		else
			continue;
	}

	for (int i = 0; i < 26; i++)
		cout << locate[i] << " ";
	cout << "\n";

	return 0;
}