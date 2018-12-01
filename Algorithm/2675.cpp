#include<iostream>
#include<string>
using namespace std;

int main()
{
	int t, r;
	string s;
	char arr[1000][200] = { 0 };
	cin >> t;

	for (int k = 0; k < t; k++) {
		cin >> r >> s;
			for (int i = 0; i <= s.length(); i++) {
				for (int j = 0; j < r; j++) {
					 arr[k][i*r + j] = s[i];
				}
			}
	}

	for (int k = 0; k < t; k++) {
		for (int i = 0; i < 199; i++) {
			if (arr[k][i] == '\0') {
				cout << '\n';
				break;
			}
			cout << arr[k][i];
		}
	}

	return 0;
}