#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void sigHandler(int n){
	printf("ctrl+c\n");
	//sleep(4);
	exit(0);
}

int main(){
	signal(SIGINT, sigHandler);

	while(1){}
}
