/* we create subprocesses exponentially
8 -loop 8
32 -loop 32
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	for(int i=0;i<5;i++){
		fork();
		sleep(2);
	}
	return 0;
}
