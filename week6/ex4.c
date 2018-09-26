/*
output:
ps@admin:~/week6$ sigusr 1
[1]+  Done                    ./ex4

explain: I have killed process with sigusr(Ctrl+C)
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int n){
	if(n==SIGKILL){
		printf("sigkill\n");
	}else if(n==SIGSTOP){
		printf("sigstop\n");
	}else if(n==SIGUSR1){
		printf("sigusr1\n");
		exit(0);
	}
}

int main(){

	signal(SIGUSR1, sig_handler);
	signal(SIGKILL, sig_handler);
	signal(SIGSTOP, sig_handler);
	while(1){
		sleep(1);
	}
}
