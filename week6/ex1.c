#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char * st1 = "qwerty";
	char * st2 = "";
	printf("before second string: %s\n", st2);

	int a[2];
	char buffer[strlen(st1)];
	if (pipe(a)<0)exit(1);

	write(a[1],st1, strlen(st1));
	read(a[0], buffer, strlen(st1));

	st2 = buffer;
	printf("after second string: %s\n", st2);
}
