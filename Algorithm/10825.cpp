#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct person {
	int ko;
	int en;
	int ma;
	string name;
};

bool cmp(const person &u, const person &v) {
	if (u.ko > v.ko) return true;
	else if (u.ko == v.ko) {
		if (u.en < v.en) return true;
		else if (u.en == v.en) {
			if (u.ma > v.ma) return true;
			else if (u.ma == v.ma) {
				return u.name < v.name;
			}
		}
	}
	return false;
}


int main() {

	int n;
	cin >> n;
	vector<person> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].name >> v[i].ko >> v[i].en >> v[i].ma;
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << v[i].name << '\n';
	}


	return 0;
}