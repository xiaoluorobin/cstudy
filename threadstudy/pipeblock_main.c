#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#define K 1024
#define WRITELEN (11*K)

int main()
{
	int result = -1;
	int fd[2],nbytes;
	pid_t pid;
	char string[WRITELEN] ="welcome pipe!";
	char readbuffer[10*K];
	int *write_fd = &fd[1];
	int *read_fd = &fd[0];

	result = pipe(fd);
	if(-1 == result)
	{
		printf("create piple fail\n");
		return -1;
	}
	pid = fork();
	if(-1 == pid)
	{
		printf("fork fail\n");
		return -1;
	}
	if(0 == pid)
	{
		int write_size = WRITELEN;
		result = 0;
		close(*read_fd);
		while(write_size >= 0)
		{
			result = write(*write_fd,string,write_size);
			if(result >0)
			{	write_size -= result;
				printf("wirite %d bytes data.left %d bytes\n",result,write_size);
			}
			else
			{
				printf("not write finish.result = %d",result);
				sleep(100);
			}
			return 0;
		}
	}
	else
	{
		close(*write_fd);
		while(1)
		{
			nbytes = read(*read_fd,readbuffer,sizeof(readbuffer));
			if(nbytes <=0)
			{
				printf("no data writed\n");
				break;
			}
			printf("receive %d bytes,content is %s\n",nbytes,readbuffer);
		}
	}
	return 0;
}
