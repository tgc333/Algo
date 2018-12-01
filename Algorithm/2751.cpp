#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1000001] = { 0 };
int main()

{
	vector <int> v;
	int n, temp;
	cin >> n;
	temp = n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	

	sort(arr, arr+n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	return 0;
}