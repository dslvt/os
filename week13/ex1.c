#include <stdio.h>
#include <stdbool.h>

int main(){
	int n = 3;
	int m = 5;
	int C[m][n];
	int R[m][n];
	int E[n];
	int A[n];

	freopen("input.txt","r",stdin);
	for(int i = 0; i < n; i++){
		scanf("%d",&E[i]);
	}

 	for(int i = 0; i < n; i++){
		scanf("%d",&A[i]);
 	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &C[i][j]);
		}
	}

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &R[i][j]);
		}
	}

	bool zer = false;
	while(!zer){
		zer = true;
		bool fl = false;
		for(int j = 0; j < m; j++){
			bool flag = true;
			bool linezeroes = true;
			for(int k = 0; k < n; k++){
				if(R[j][k] != 0){
					linezeroes = false;
				}

				if(R[j][k] > A[k]){
					flag = false;
					break;
				}
			}
			if(!linezeroes){
				zer = false;
			}
			if(flag && !linezeroes){
				fl = true;
				for(int k = 0; k < n; k++){
					R[j][k] = 0;
					A[k] +=C[j][k];
					C[j][k] = 0;
				}
			}
		}

		if(!fl){
			if(zer){
				printf("no deadlock\n");
			}
			else{
				printf("deadlock:\n");
				for(int i = 0; i < m; i++){
					for(int j = 0; j < n; j++){
						if(R[i][j] != 0 ){
							printf("%d ", (i+1));
							break;
						}
					}
				}
			printf("\n");
			}
		return 0;
		}
	}
}
