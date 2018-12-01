#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main(void)
{
	int a, b;
	int sum=0;
	int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	scanf("%d %d", &a, &b);

	for (int i = 0; i < a-1; i++) {
		sum += month[i];
	}
	sum += b;

	if (sum % 7 == 0)
		printf("SUN");
	else if (sum % 7 == 1)
		printf("MON");
	else if (sum % 7 == 2)
		printf("TUE");
	else if (sum % 7 == 3)
		printf("WED");
	else if (sum % 7 == 4)
		printf("THU");
	else if (sum % 7 == 5)
		printf("FRI");
	else
		printf("SAT");

	return 0;
}