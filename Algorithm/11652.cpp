#include<iostream>
#include<algorithm>
using namespace std;

long long card[1000001] = { 0 };

int main() {

	int n;
	int count = 1;
	int anscount = 1;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	sort(card, card + n);

	long long ansnum = card[0];

	for (int i = 1; i < n; i++) {
		if (card[i] == card[i - 1]) {
			count++;
			if (anscount <= count) {
				if (anscount == count && ansnum <= card[i]) {
					continue;
				}
				anscount = count;
				ansnum = card[i];
			}
		}
		else {
			count = 1;
		}
	}
	
	cout << ansnum << '\n';

	return 0;
}