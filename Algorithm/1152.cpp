#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

int main()
{
	char s[1000001];
	cin.getline(s, 1000001);
	int count = 0;
	for (int i = 0; i < 1000001; i++) {
		if (s[i] == '\0')
			break;
		if (s[i] == ' ' && s[i + 1] != ' ')
			count++;
		if (s[i] != ' ' && s[i + 1] == '\0')
			count++;
	}

	if (s[0] == ' ')
		count--;

	cout << count << "\n";
		
	return 0;
}