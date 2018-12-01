#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int twocnt = 0, fivecnt = 0;
	for (int i = 2; i <= n; i++) {
		int temp = i;
		for (int j = 2; j <= i; j++) {
			while (temp%j == 0) {
				temp /= j;
				if (j == 2)
					twocnt++;
				else if (j == 5)
					fivecnt++;
			}
		}
	}
	cout << min(twocnt, fivecnt) << '\n';

	return 0;
}