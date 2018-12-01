//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//int start[100001];
//int endi[100001];
//int mini[100001];
//int maxi[100001] = { 0 };
//int arr[100001] = { 0 };
//
//int main() {
//
//	int n, m;
//	cin >> n >> m;
//	
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//		mini[i] = 2000000000;
//	}
//
//	
//	maxi[1] = 0;
//	mini[1] = 2000000000;
//	cin >> start[1] >> endi[1];
//	for (int i = start[1]; i <= endi[1]; i++) {
//		if (maxi[1] < arr[i])
//			maxi[1] = arr[i];
//		if (mini[1] > arr[i])
//			mini[1] = arr[i];
//	
//	}
//	cout << mini[1] << ' ' << maxi[1] << '\n';
//	
//	for (int i = 2; i <= m; i++) {
//		cin >> start[i] >> endi[i];
//
//		if (start[i] > start[i - 1]) {
//			for (int j = start[i - 1]; j < start[i]; j++) {
//				if (arr[j] == maxi[i - 1] || arr[j] == mini[i - 1]) {
//					maxi[i] = 0;
//					mini[i] = 2000000000;
//					for (int k = start[i]; k <= endi[i]; k++) {
//						if (maxi[i] < arr[k])
//							maxi[i] = arr[k];
//						if (mini[i] > arr[k])
//							mini[i] = arr[k];
//					}
//					break;
//				}
//			}
//		}
//		else if (start[i] <= start[i - 1]) {
//			for (int j = start[i]; j <= start[i - 1]; j++) {
//				if (maxi[i] < arr[j])
//					maxi[i] = arr[j];
//				if (mini[i] > arr[j])
//					mini[i] = arr[j];
//			}
//		}
//
//		if (endi[i] < endi[i - 1]) {
//			for (int j = endi[i] + 1; j <= endi[i - 1]; j++) {
//				if (arr[j] == maxi[i - 1] || arr[j] == mini[i - 1]) {
//					maxi[i] = 0;
//					mini[i] = 2000000000;
//					for (int k = start[i]; k <= endi[i]; k++) {
//						if (maxi[i] < arr[k])
//							maxi[i] = arr[k];
//						if (mini[i] > arr[k])
//							mini[i] = arr[k];
//					}
//					break;
//				}
//			}
//		}
//		else if (endi[i] >= endi[i - 1]) {
//			for (int j = endi[i - 1]; j <= endi[i]; j++) {
//				if (maxi[i] < arr[j])
//					maxi[i] = arr[j];
//				if (mini[i] > arr[j])
//					mini[i] = arr[j];
//			}
//		}
//		cout << mini[i] << ' ' << maxi[i] << '\n';
//	}
//
//	return 0;
//}