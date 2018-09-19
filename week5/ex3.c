#include <stdio.h>
#include <pthread.h>

int g[10];
int thread_id[10];
int is_using = 0;

void * thr(int it){
	int h = 0;
	while(h!=10){
		if(is_using==0){
			if(h%5==0)
				printf("%d, thread\n", (int) pthread_self());
			is_using=1;
			for(int i=0;i<10;i++){
				g[i]+=1;
			}
			h++;
			is_using=0;
		}
		else{
			sleep(1);
		}
	}
	pthread_exit(NULL);
}

int main(){
	for(int i=0;i<10;i++){
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&thread_id[i], &attr, thr, i);
	}
}
