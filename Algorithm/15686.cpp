#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef struct point {
	int x;
	int y;
	int distance;
}point;

point home[2500];
int homecount = 0;
point chic[2500];
int chiccount = 0;
vector<int> v;
int city[51][51] = { 0 };
int n, m;
int mini = 999999;

void combination(int start, int count) {
	
	if (count == 0) {
		int sum = 0;
		for (int i = 0; i < homecount; i++) {
			home[i].distance = 9999999;
		}

		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < homecount; j++) {
				if (home[j].distance > (abs(home[j].x - chic[v[i]].x) + abs(home[j].y - chic[v[i]].y))) {
					home[j].distance = (abs(home[j].x - chic[v[i]].x) + abs(home[j].y - chic[v[i]].y));
				}
			}
		}

		for (int i = 0; i < homecount; i++) {
			sum += home[i].distance;
		}
		if (mini > sum)
			mini = sum;

		return;
	}
	
	
	for (int i = start; i < chiccount; i++) {
		v.push_back(i);
		combination(i + 1, count - 1);
		v.pop_back();
	}
}



int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) {
				home[homecount].x = i;
				home[homecount].y = j;
				homecount++;
			}
			else if (city[i][j] == 2) {
				chic[chiccount].x = i;
				chic[chiccount].y = j;
				chiccount++;
			}
		}
	}

	combination(0, m);

	cout << mini << "\n";

	return 0;
}