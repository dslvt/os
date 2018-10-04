#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_realloc(void* ptr, size_t newsize){
	void* newpoint = malloc(newsize);
	if(ptr != NULL){
		if(newsize==0) free(ptr);
		else{
			memcpy(newpoint, ptr, newsize);
			free(ptr);
		}
	}
	return newpoint;
}

int main(){
	int asize=10;
	int* a = malloc(asize*sizeof(int));
	for(int i = 0; i < asize; i++){
		a[i]=100;
	}
	a = my_realloc(a, 0);
	printf("%d", sizeof(a));
/*	for(int i=0;i<asize;i++){
		printf("%d ", a[i]);
	}*/
	return 0;
}
