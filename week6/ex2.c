#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
	char * st = "qwerty";

	int a[2];
	if(pipe(a)<0) exit(1);

	int pid = fork();
	if(pid > 0){
		write(a[1], st, strlen(st));
	}else{
		char em_st[strlen(st)];
		read(a[0], em_st, strlen(st));
		printf("child process: %s\n", em_st);
	}
}
