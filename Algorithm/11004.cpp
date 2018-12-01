#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[5000001] = { 0 };


int main() {

	int n, k;
	scanf("%d %d", &n, &k);
	k--;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int left = 0, right = n - 1;
	int low = left, high = right;

	while (1) {
		int pivot = a[left];
		int temp;

		while (a[low] <= pivot && low <= right) {
			low++;
		}
		while (a[high] > pivot && high >= left) {
			high--;
		}

		if (low > high) {
			temp = a[left];
			a[left] = a[high];
			a[high] = temp;
			if (k < high) {
				right = high - 1;
			}
			else if (k > high) {
				left = high + 1;
			}
			else if (k == high) {
				cout << a[high] << '\n';
				return 0;
			}
			low = left;
			high = right;
		}
		else {
			temp = a[low];
			a[low] = a[high];
			a[high] = temp;
		}
	}

	return 0;
}