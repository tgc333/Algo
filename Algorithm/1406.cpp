#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {

	string str;
	
	stack<char> front, rear;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		front.push(str[i]);
	}
	int n;
	cin >> n;

	cin.ignore(1);
	for (int i = 0; i < n; i++) {
		string command;
		getline(cin, command);
		if (command[0] == 'L') {
			if (front.size() == 0) {
				continue;
			}
			else {
				rear.push(front.top());
				front.pop();
			}
		}
		else if (command[0] == 'D') {
			if (rear.size() == 0) {
				continue;
			}
			else {
				front.push(rear.top());
				rear.pop();
			}
		}
		else if (command[0] == 'P') {
			front.push(command[2]);
		}
		else if (!front.empty() && command[0] == 'B') {
			front.pop();
		}
	}

	int k = front.size();
	for (int i = 0; i < k; i++) {
		rear.push(front.top());
		front.pop();
	}

	k = rear.size();
	for (int i = 0; i < k; i++) {
		cout << rear.top();
		rear.pop();
	}

	return 0;
}