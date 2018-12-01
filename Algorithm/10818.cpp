#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main(void)
{
	int n, k;
	scanf("%d", &n);
	int min = 1000001;
	int max = -10000001;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k > max)
			max = k;
		if (k < min)
			min = k;
	}

	printf("%d %d\n", min, max);

	return 0;
}