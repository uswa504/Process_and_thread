#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
int main(){
	int cpid = fork();
	if(cpid > 0)
		printf("Parent Process\n");
	else if(cpid == 0){
		sleep(30);
		printf("child process\n");
	}
	return 0;
}
