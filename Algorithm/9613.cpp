#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int t, n;

	cin >> t;

	while (t--) {
		cin >> n;
		long long sum = 0;
		long long arr[101] = { 0 };
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
			
		}
		cout << sum << "\n";
	}

	return 0;
}