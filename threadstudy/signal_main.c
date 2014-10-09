#include <signal.h>
#include <stdio.h>
#include <errno.h> 
#include <string.h>
//why return error ?

static void sig_handle(int signo)
{
	if(SIGSTOP == signo)
	{
		printf("recevie sigstop\n");
	}
	else if(SIGKILL == signo)
	{
		printf("receive sigkill\n");
	}
	else
	{
		printf("receive %d\n",signo);
	}
	return;
}

int main(void)
{
	typedef void (*sighandler_t)(int);

	sighandler_t ret;
	ret = signal(SIGSTOP,sig_handle);
	if(SIG_ERR == ret)
	{
		printf("set sighandle function fail,error is:%s,no is %d\n" , strerror(errno),errno);
		//return -1;
	}
	ret = signal(SIGKILL,sig_handle);
	if(SIG_ERR == ret)
	{
		printf("set sigkill function fail\n");
		//return -1;
	}
	for(;;);
}
