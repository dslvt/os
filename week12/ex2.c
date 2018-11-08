#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 255

int main(int argc, char* argv[]){
    char file_name[BUFFER_SIZE] = "";
    char let;
    int flag;

   if (argc>2){
       if (strcmp(argv[1], "-a")==0){
           strcpy(file_name, argv[2]);
           flag = open(file_name, O_RDWR|O_APPEND);
       }
   }else {
       strcpy(file_name, argv[1]);
       flag = open(file_name, O_WRONLY);}
       while (read(STDIN_FILENO, &let, 1) > 0) {
           write(flag, &let, 1);
       }
    return 0;
}
