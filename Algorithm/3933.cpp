#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<math.h>

int main() {

	int input[255];
	int ex[255];
	int ans[4] = { 0 };
	int max, sum = 0;
	int index;
	int count;
	
	for (index = 0; index < 255; index++) {
		scanf("%d", &input[index]);
		if (input[index] == 0)
			break;
	}

	for (int i = 0; i < index; i++) {
		max = sqrt(input[i]);
		count = 0;
		for (int j = 0; j < max; j++) {
			ex[j] = (j+1) * (j+1);
			
		}
		
		int result = input[i];
		
		int temp1 = result;
		for (int k1 = 0; k1 < (int)sqrt(temp1); k1++) {
			result = temp1 - ex[k1];
		
			if (result == 0) {
				count++;
				ans[0] = ex[k1];
				ans[1] = 0;
				ans[2] = 0;
				ans[3] = 0;

				/*for (int aa = 0; aa < 4; aa++)
					printf("%d ", ans[aa]);
				printf("\n");*/
				break;
			}
			else if (result < 0) {
				break;
			}

			int temp2 = result;
			for (int k2 = 0; k2 <= (int)sqrt(temp2); k2++) {
				result = temp2 - ex[k2];
				//printf("k2 = %d\n", result);
				if (result == 0) {
					if (k1 > k2)
						continue;
					count++;
					ans[0] = ex[k1];
					ans[1] = ex[k2];
					ans[2] = 0;
					ans[3] = 0;
				/*	for (int aa = 0; aa < 4; aa++)
						printf("%d ", ans[aa]);
					printf("\n");*/
					break;
				}
				else if (result < 0) {
					break;
				}
				int temp3 = result;
				for (int k3 = 0; k3 <= (int)sqrt(temp3); k3++) {
					result = temp3 - ex[k3];
					//printf("k3 = %d\n", result);
					if (result == 0) {
						if (k2 >k3)
							continue;
						if (k1 > k2)
							continue;
						count++;
						ans[0] = ex[k1];
						ans[1] = ex[k2];
						ans[2] = ex[k3];
						ans[3] = 0;
						/*for (int aa = 0; aa < 4; aa++)
							printf("%d ", ans[aa]);
						printf("\n");
*/
						
						break;
					}
					else if (result < 0) {
						break;
					}
					int temp4 = result;
					for (int k4 = 0; k4 <= (int)sqrt(temp4); k4++) {
						result = temp4 - ex[k4];
						//printf("k4 = %d\n", result);
						if (result == 0) {
							if (k3 > k4)
								continue;
							if (k2 > k3)
								continue;
							if (k1 > k2)
								continue;
							count++;
							ans[0] = ex[k1];
							ans[1] = ex[k2];
							ans[2] = ex[k3];
							ans[3] = ex[k4];
							
							break;
						}
						else if (result < 0) {
							break;
						}
					}
				}
			}
		}
		
		printf("%d\n", count);
	}



	return 0;
}