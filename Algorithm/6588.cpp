#include<iostream>
using namespace std;

bool arr[1000001] = { 0 };
int ans[1000001] = { 0 };
int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int count = 0;
	
	for (int i = 2; i <= 1000000; i++) {
		if (arr[i] == false) {
			ans[count++] = i;
			for (int j = i+i; j <= 1000000; j+=i) {
				arr[j] = true;
			}
		}
	}	

	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;		

		for (int i = 1; i < count; i++) {
			if (arr[n - ans[i]] == false) {
				cout << n << " = " <<ans[i] << " + " << n - ans[i] << "\n";
				break;
			}
		}
	}

	
	return 0;
}