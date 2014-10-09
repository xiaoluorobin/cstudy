#include <stdio.h>
#include <unistd.h>
int main(void)
{
	pid_t pid,ppid;
	pid = getpid();
	ppid = getppid();

	printf("current process id is:%d\n",pid);
	printf("current parent process id is %d\n",ppid);

	return 0;
}
