#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct person {
	int age;
	string name;
	int join;
	bool operator < (const person &p) const {
		if (age < p.age) return true;
		else if (age == p.age) return join < p.join;
		else return false;
	}
};

int main()

{
	int n;
	cin >> n;
	vector<person> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].age >> v[i].name;
		v[i].join = i;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		cout << v[i].age << ' ' << v[i].name << '\n';
	}

	return 0;
}