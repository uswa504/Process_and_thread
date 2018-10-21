#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
void* add(void *arg);
int array[1000];
int arrSize = 1000;
int chunkSize = 100;
int main(int argc, char** argv){
	int csize;	
	for(int st = 0; st < arrSize; st++){
		array[st]=st;
	}
	pthread_t threads[10];
	for(int i=0;  i<10; i++){
		csize = i * chunkSize;
		pthread_create(&threads[i], NULL, add, (void*)&csize);
	}
	int t_sum = 0;
	int status[10];
	for(int i=0;  i<10; i++){
		pthread_join(threads[i], (void**)&status[i]);
		printf("%d\n", status[i]);
	}
	for(int i=0; i<10; i++){
		t_sum = t_sum + status[i];
	}
	printf("The sum is %d\n", t_sum);
}
void* add (void * arg){
	int start = (int) arg;
	int end = start + chunkSize;
	int sum =0;
	for(int i=start; i<end; i++){
		sum = sum+array[i];
	}
	return ((void*)&sum);
}
