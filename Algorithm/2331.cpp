#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v[240000];
int check[240000] = { 0 };

int main() {
	int a, p, cnt = 0;
	cin >> a >> p;

	while (1) {
		int temp = 0;

		if (check[a] == 0) {
			
			check[a] = 1;
			int n = a;
			while (a / 10 != 0) {
				temp += pow(a % 10, p);
				a /= 10;
			}
			temp += pow(a, p);
			v[n].push_back(make_pair(temp, cnt));
			a = temp;
			cnt++;
		}
		else {
			cout << v[a][0].second << '\n';
			return 0;
		}	
	}
	return 0;
}