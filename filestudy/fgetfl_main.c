#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int flags = -1;
	int accmode = -1;

	flags = fcntl(0,F_GETFL,0);
	if(flags < 0)
	{
		 printf("failure to use fcntl\n");
		 return -1;
	}
	accmode = flags & O_ACCMODE;
	if(accmode == O_RDONLY)
	{
		printf("stdin read only\n");
	}
	else
	{
		printf("stdin not read only\n");
	}
}
