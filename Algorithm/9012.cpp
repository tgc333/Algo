#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


int main() {

	int n, k;
	scanf("%d", &n);
	

	for (int i = 0; i < n; i++) {
		char arr[51] = { 0 };
		scanf("%s", arr);
		k = 0;
		for (int i = 0; i < 51; i++) {
			//printf("%d  ", k);
			if (arr[i] == '(')
				k++;
			else if (arr[i] == ')')
				if (k > 0) {
					k--;
				}
				else {
					printf("NO\n");
					break;
				}
			else if (arr[i] == '\0') {
				if (k == 0)
					printf("YES\n");
				else
					printf("NO\n");
				break;
			}
		}
	}

	return 0;
}