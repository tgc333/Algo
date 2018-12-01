#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

char arr[10000][10000] = { 0 };
int solvex=3;
int solvey=6;
char output[3][6] = {
{ '0','0','*','0','0','0' },
{ '0','*','0','*','0','0' },
{ '*','*','*','*','*','0' } };

void star(int n, int x, int y, int cnt)
{
	if (n == 1)
		return;

	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				arr[i + (x)][j + (y * k)] = arr[i][j];			
				//cout << i + 3 * cnt << " " << j + (y * k) << "\n";
				solvex = i + x;
				solvey = j + (y * k);
			}
		}
	}	
	int empty = 3 * pow(2, cnt - 1);
	for (int i = 0; i < empty; i++) {
		memmove(arr[i] + empty, arr[i], sizeof(char)*y);
	}
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < empty; j++) {
			arr[i][j] = '0';
		}
	}
	
	solvex++;
	solvey++;
	star(n/2, solvex, solvey, cnt + 1);
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= 5; j++) {
			arr[i][j] = output[i][j];
		}
	}

	star(n/3, 3, 6, 1);
	
	for (int i = 0; i < solvex; i++) {
		for (int j = 0; j < solvey-1; j++) {
			if (arr[i][j] == '*')
				cout << "*";
			else
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}