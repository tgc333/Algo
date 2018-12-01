#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main() {
	char s[101];
	while (scanf("%[^\n]\n",s)) {
		printf("%s\n", s);
	}

	return 0;
}