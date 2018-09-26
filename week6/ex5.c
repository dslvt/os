#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(){
	int pid = fork();

	if(pid==0){
		while(1){
			printf("I am alive!\n");
			sleep(1);
		}
	}

	sleep(10);
	kill(pid, SIGTERM);
}
