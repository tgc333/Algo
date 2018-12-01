#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {

	stack<char> s;
	int size=0;
	int sum=0;

	string aaa;
	cin >> aaa;

	for (int i = 0; i < aaa.size(); i++) {
		if (aaa[i] == '(')
			s.push(aaa[i]);
		if (aaa[i] == ')') {
			s.pop();
			if(aaa[i-1]=='(')
				sum += s.size();
			else sum++;
		}
	}

	cout << sum << "\n";

	return 0;
}