#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;
	queue<int> q1,q2;
	cout << "<";
	for (int i = 1; i <= n; i++)
		q1.push(i);

	while (n--) {
		if (q1.size() == 0)
			break;
		else if (q1.size() == 2) {
			if (m % 2 == 0) {
				q1.push(q1.front());
				q1.pop();
				cout << q1.front() << ", ";
				q1.pop();
			}
			else {
				cout << q1.front() << ", ";
				q1.pop();
			}
		}
		else if (q1.size() == 1) {
			cout << q1.front() << ">";
			q1.pop();
		}
		else {
			for (int i = 0; i < m - 1; i++) {
				q1.push(q1.front());
				q1.pop();
			}
			cout << q1.front() << ", ";
			q1.pop();
		}
	}


	return 0;
}