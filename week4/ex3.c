#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fl = 1;
	while (fl){
		char com[100];
		printf(": ");
		scanf("%s", com);
		if(strcmp(com, "exit")==0){
			fl=0;
		}else{
			system(com);
		}
	}
}
