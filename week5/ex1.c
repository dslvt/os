#include <stdio.h>
#include <pthread.h>

int atoi(const char *nptr);
void * thr(int it){
	printf("%d thread from %d\n", (int) pthread_self(), it);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	int thread_num = atoi(argv[1]);

	for(int i=0; i<thread_num; i++){
		pthread_t tid;
		pthread_attr_t attr;

		pthread_attr_init(&attr);

		printf("create thread %d\n", i);
		pthread_create(&tid, &attr, thr, i);
		pthread_join(tid, NULL);
	}


	return 0;
}
