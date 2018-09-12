/*every time when we create process, new process has new pid
child process has parent pid + 1
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int n = getpid();
	fork();
	if(n == getpid()){
		printf("Hello from parent[PID - %d]\n", getpid());
	}else{
		printf("Hello from child[PID - %d]\n", getpid());
	}
	return 0;
}
