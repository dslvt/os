#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int main(){
	char* replace_string = "This is a nice day";
	int file = open("ex1.txt", O_RDWR);
	
	struct stat s;
	int fsize = fstat(file, &s);
	int size = s.st_size;
	int pagesize = getpagesize();
	//size += pagesize-(size%pagesize);
	//printf("%d", size);

	char *addr = mmap(NULL, strlen(replace_string), PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
	for (int i=0;i<MAX(size, strlen(replace_string));i++){
		if(i<strlen(replace_string)){
			addr[i] = replace_string[i];		
		}else{
			addr[i] = ' ';
		}
	}
	munmap(addr, strlen(replace_string));
	close(file);
}
