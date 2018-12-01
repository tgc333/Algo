#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <algorithm>

typedef struct element{
	int key;
	int s;
	int e;

	bool operator<(const element &e){
		return key < e.key;
	}
}element;

int parent[100001];
int num[100001];
element e[1000001];

int set_find(int vertex) {
	int p, s, k = -1;
	for (k = vertex; (p = parent[k]) >= 0; k = p)
		;
	s = k;
	for (k = vertex; (p = parent[k]) >= 0; k = p)
		parent[k] = s;
	return s;
}

void set_union(int s1, int s2) {
	if (num[s1] < num[s2]) {
		parent[s1] = s2;
		num[s2] += num[s1];
	}
	else {
		parent[s2] = s1;
		num[s1] += num[s2];
	}
}

int main() {

	int vilage, load;
	int count;
	int ans = 0;	
	int max = 0;
	scanf("%d %d", &vilage, &load);
	
	count = 0;

	for (int i = 1; i <= vilage; i++) {
		parent[i] = -1;
		num[i] = 1;
	}

	for (int i = 0; i < load; i++) {
		scanf("%d %d %d", &e[i].s, &e[i].e, &e[i].key);
	}

	sort(e, e + load);

	for(int i = 0;i<load;i++) {
		int sset, eset;
		
		sset = set_find(e[i].s);
		eset = set_find(e[i].e);

		if (sset != eset) {
			set_union(sset, eset);
			if (max < e[i].key)
				max = e[i].key;
			ans += e[i].key;
			e[i].key = 1001;
		}
		else {
			e[i].key = 1001;
		}
	}
	
	printf("%d\n", ans-max);

	return 0;

}