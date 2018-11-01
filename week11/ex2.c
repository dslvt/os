#include <stdio.h>
#include <unistd.h>

int main(){
	char * hello = "hello";
	setvbuf(stdout, NULL, _IOLBF, 0);
	for (int i=0;i<5;i++){
		printf("%c", hello[i]);
		sleep(1);
	}
}
