#include<iostream>
using namespace std;

int main()
{
	int arr[5][9] = { 0 };
	char num[9] = { 0 };

	for (int i = 0; i < 4; i++) {
		cin >> num;
		for (int j = 0; j < 8; j++) {
			if (num[j] == '1')
				arr[i][j] = 1;
			else if (num[j] = '0')
				arr[i][j] = 0;
		}
	}
	
	int n, k, cycle, temp, sum = 0, cycletemp;
	cin >> k;
	while (k--) {
		cin >> n >> cycle;
		int flag[5] = { 0 };
		flag[n-1] = cycle;
		for (int i = n-1; i > 0; i--) {
			if (arr[i][6] != arr[i - 1][2]) {
				flag[i - 1] = flag[i] * -1;
				
			}
			else break;
		}
		for (int i = n-1; i < 3; i++) {
			if (arr[i][2] != arr[i + 1][6]) {
				flag[i + 1] = flag[i] * -1;
				
			}
			else break;
		}
		
		for (int i = 0; i < 4; i++) {
			if (flag[i] == 1) {
				temp = arr[i][7];
				for (int j = 7; j > 0; j--) {
					arr[i][j] = arr[i][j - 1];
				}
				arr[i][0] = temp;
			}
			else if (flag[i] == -1) {
				temp = arr[i][0];
				for (int j = 0; j < 7; j++) {
					arr[i][j] = arr[i][j+1];
				}
				arr[i][7] = temp;
			}
		}
		
		
	}


	if (arr[0][0] == 1) {
		sum += 1;
	}
	if (arr[1][0] == 1) {
		sum += 2;
	}
	if (arr[2][0] == 1) {
		sum += 4;
	}
	if (arr[3][0] == 1) {
		sum += 8;
	}

	cout << sum << "\n";
	return 0;
}