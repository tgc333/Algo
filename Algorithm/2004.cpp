#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int fivecnt = 0;
	int twocnt = 0;
	long long f = 5;
	long long t = 2;
	while (n / f != 0) {
		fivecnt += n / f;
		f *= 5;
	}
	while (n / t != 0) {
		twocnt += n / t;
		t *= 2;
	}

	f = 5;
	t = 2;
	while (m / f != 0) {
		fivecnt -= (m / f);
		f *= 5;
	}

	while (m / t != 0) {
		twocnt -= (m / t);
		t *= 2;
	}
	f = 5;
	t = 2;
	while ((n - m) / f != 0) {
		fivecnt -= ((n - m) / f);
		f *= 5;
	}

	while ((n - m) / t != 0) {
		twocnt -= ((n - m) / t);
		t *= 2;
	}

	cout << min(twocnt, fivecnt) << '\n';

	return 0;
}