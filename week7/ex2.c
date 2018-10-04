#include <stdlib.h>
#include <stdio.h>

int main(){
	int n=0;
	printf("N=");
	scanf("%d", &n);

	int *array = malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		array[i]=i;
	}

	for(int i=0;i<n;i++){
		printf("%d ", array[i]);
	}
	printf("\n");

	free(array);
	return 0;
}

