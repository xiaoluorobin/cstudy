#include<stdio.h>
#include<string.h>
#include<sys/types.h>
//#include<stdlib.h>
//#include<unistd.h>

int main(void)
{
	int result = -1;
	int fd[2],nbytes;

	pid_t pid;
	char string[] = "welcome,piple!\n";
	char readbuffer[80];

	int *write_fd = &fd[1];
	int *read_fd = &fd[0];

	result = pipe(fd);

	if(-1 == result)
	{
		printf("create pipe fail\n");
		return -1;
	}
	pid = fork();
	if(-1 == pid)
	{
		printf("fork fail\n");
		return -1;
	}
	if( 0 == pid)
	{
		close(*read_fd);
		result = write(*write_fd,string,strlen(string));

		return 0;
	}
	else // parent
	{
		close(*write_fd);
		nbytes = read(*read_fd,readbuffer,sizeof(readbuffer));
		printf("receive %d data,content is %s\n",nbytes,readbuffer);
	}
	return 0;

}
