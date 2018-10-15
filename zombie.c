#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){
	int cpid = fork();
	if(cpid > 0){
		sleep(50);	
	}
	else
		exit(0);
	return 0;
}
