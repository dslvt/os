#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fl = 1;
	while (fl){
		int n = getpid();
		char *com = NULL;
		size_t  bufsize = 0;
		ssize_t read = getline(&com, &bufsize, stdin);

		char *argv[10];
		char *cmd;

		int st = 0, uk = 0;

		for(int i = 0; i <read-1; i++){
			if(com[i] == ' '){
				argv[uk] = (char *)malloc(i-st);
				strncpy(argv[uk], com+st, i-st);
				uk++;
				st = i+1;
			}
		}

		argv[uk] = malloc(read-st-1);
		strncpy(argv[uk], com+st, read-st-1);
		uk++;

		cmd = argv[0];
		if(strcmp(cmd, "exit")==0){
			fl=0;
		}else{
			fork();
			if (n != getpid()){
				char * arg[uk+1];
				for(int i=0;i<uk;i++){
					arg[i]=argv[i];
				}
				arg[uk] = NULL;
				execvp(cmd, arg);
				fl=0;
			}
		}
	}
}
