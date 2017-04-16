#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int s1[9+1] = {0, 3, 2, 1, 2, 3, 1, 2, 3, 3};
int s2[8+1] = {0, 1, 2, 3, 1, 2, 3, 2, 1};
int DP[9+1][8+1];
int prev[9+1][8+1];


void printLCS(int size1, int size2){
	if(size1 == 0 || size2 == 0)
		return;
	if(prev[size1][size2] == 1){
		printLCS(size1-1, size2-1);
		cout << s1[size1] << " ";
	}
	else if(prev[size1][size2] == 2){
		printLCS(size1, size2-1);
	}
	else if(prev[size1][size2] == 3){
		printLCS(size1-1, size2);
	}
}

void LCS(int size1, int size2){
	int i, j;
	for(i = 1; i <= size1; i++){
		for(j = 1; j <= size2; j++){
			if(s1[i] == s2[j]){
				DP[i][j] = DP[i-1][j-1] + 1;
				prev[i][j] = 1; // from upleft
			}
			else{
				if(DP[i-1][j] < DP[i][j-1]){
					DP[i][j] = DP[i][j-1];
					prev[i][j] = 2; // from left
				}
				else{
					DP[i][j] = DP[i-1][j];
					prev[i][j] = 3; // from right
				}
			}
			printf("%d ", DP[i][j]);
		}
		printf("\n");
	}
	printf("LCS length : %d\n", DP[size1][size2]);
	printLCS(size1, size2);
}

int main(){
	for(int i = 0; i < 10; i++){
		if(i == 0){
			for(int j = 0; j < 9; j++){
				DP[i][j] = 0;
			}
		}
		else{
			DP[i][0] = 0;
		}
	}
	LCS(9, 8);

	system("pause");
}