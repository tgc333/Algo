#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10001] = { 0 };

int main() {
	int n, t;
	cin >> n;

	while (n--) {
		cin >> t;
		arr[t]++;
	}

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << '\n';
		}
	}

	return 0;
}