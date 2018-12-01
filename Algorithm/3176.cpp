#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

typedef struct path {
	int start;
	int end;
	int length;
}path;

path p[100001];

int main()
{
	int n, k;
	int a, b, temp;
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &p[i].length);
		if (a > b) {
			temp = a;
			a = b;
			b = temp;
		}
		p[i].start = a;
		p[i].end = b;
	}

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int start, end, min, max;
		scanf("%d %d", &a, &b);
		if (a > b) {
			temp = a;
			a = b;
			b = temp;
		}
		start = a;
		end = b;


	}

	return 0;
}