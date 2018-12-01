//#include <iostream>
//#include <string>
//using namespace std;
//
//char up[3][3]; //1 = Èò
//char front[3][3]; // 2 = »¡
//char lefti[3][3]; // 3 = ÃÊ·Ï
//char righti[3][3]; // 4 = ÆÄ¶û
//char under[3][3]; // 5 = ³ë¶û
//char back[3][3]; // 6 = ¿À·»Áö
//
//void l(char at) {
//	int temp[3];
//	int templeft[3];
//	
//	for (int i = 0; i < 3; i++) {
//		
//	}
//
//
//	if (at == '+') {
//		for (int i = 0; i < 3; i++) {
//			temp[i] = up[i][0];
//			up[i][0] = back[2 - i][0];
//			back[i][0] = under[2 - i][0];
//			under[i][0] = front[2 - i][0];
//			front[i][0] = temp[i];
//		}
//		for (int i = 0; i < 3; i++) {
//			templeft[i] = lefti[0][i];
//			lefti[0][i] = lefti[2 - i][0];
//			lefti[i][0] = lefti[2][2 - i];
//			lefti[2][i] = lefti[2 - i][2];
//			lefti[i][2] = templeft[i];
//		}
//	}
//	else {
//		for (int i = 0; i < 3; i++) {
//			temp[i] = up[i][0];
//			up[i][0] = front[i][0];
//			front[i][0] = under[2 - i][0];
//			under[i][0] = back[i][0];
//			back[i][0] = temp[2 - i];
//		}
//		for (int i = 0; i < 3; i++) {
//			templeft[i] = lefti[0][i];
//			lefti[0][i] = lefti[2][i];
//			lefti[2][i] = lefti[2 - i][2];
//			lefti[i][2] = lefti[i][0];
//			lefti[i][0] = temp[2 - i];
//		}
//	}
//}
//
//
//int main() {
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			up[i][j] = 'w';
//			front[i][j] = 'r';
//			lefti[i][j] = 'g';
//			righti[i][j] = 'b';
//			back[i][j] = 'o';
//			under[i][j] = 'y';
//		}
//	}
//
//	int t, n;
//	cin >> t;
//	while (t--) {
//		cin >> n;
//		while (n--) {
//			string s;
//			cin >> s;
//			if (s[0] == 'L') {
//				l(s[1]);
//			}
//			for (int i = 0; i < 3; i++) {
//				for (int j = 0; j < 3; j++) {
//					if (up[i][j] == 1) {
//						cout << 'w';
//					}
//					else if (up[i][j] == 2) {
//						cout << 'r';
//					}
//					else if (up[i][j] == 3) {
//						cout << 'g';
//					}
//					else if (up[i][j] == 4) {
//						cout << 'b';
//					}
//					else if (up[i][j] == 5) {
//						cout << 'o';
//					}
//					else if (up[i][j] == 6) {
//						cout << 'y';
//					}
//				}
//				cout << '\n';
//			}
//		}
//	}
//
//	return 0;
//}