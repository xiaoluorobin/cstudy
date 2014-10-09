#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *args[] = {"/bin/ls",NULL};
	printf("process id is:%d\n",getpid());
	if(execve("/bin/ls",args,NULL)<0)
		printf("create process fail!\n");
	return 0;
}
