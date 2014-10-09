#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;

	pid = fork();

	if(-1 == pid){
		printf("process create fail.\n");
	}
	else if(pid == 0){
		printf("child fork:child %d,parent %d\n",getpid(),getppid());
	}
	else{
		printf("parent fork,get child %d\n",pid);
	}
	return 0;
}
