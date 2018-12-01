#include<iostream>
using namespace std;

bool prime(int k) {
	if (k < 2)
		return false;

	for (int i = 2; i*i <= k; i++) {
		if (k%i == 0)
			return false;
	}
	return true;
}


int main()
{
	int n, k, ans = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;

		if (prime(k))
			ans++;
	}

	cout << ans << "\n";
	return 0;
}