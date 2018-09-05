#include <stdio.h>

void bs(int *ar, int len);
void swp(int *frs, int *scd);

int main(){
	int ar[5] = {9, 8, 7, 6, 5};
	bs(ar, 5);
	for(int i=0;i<5; i++){
		printf("%d ", ar[i]);
	}
}

void bs(int *ar, int len){
	for(int i=0;i<len; i++){
		for(int j=0; j<len-i-1; j++){
			if(ar[j] > ar[j+1]){
				swp(&ar[j], &ar[j+1]);
			}
		}
	}
}

void swp(int *frs, int *scd){
	int tmp;
	tmp = *frs;
	*frs = *scd;
	*scd = tmp;
}
