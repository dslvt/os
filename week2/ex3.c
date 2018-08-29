#include <stdio.h>
#include <string.h>



int main(int argc, char *argv[]){
	int n;
	sscanf(argv[1], "%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = n-i-1; j > -1; j--){
			printf("%c", ' ');
		}
		for(int j = 0; j < (i+1)*2-1; j++){
			printf("%c", '*');
		}
		printf("\n");

	}
	return 0;
}
