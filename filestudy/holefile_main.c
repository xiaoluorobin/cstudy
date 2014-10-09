#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	int i;
	ssize_t size;
	off_t offset;
	char buf1[] = "1234567890";
	char buf2[] = "abcdefghijklmnopqrstuvwxyz";
	char filename[] = "hole.txt";
	int len = 8;

	fd = open(filename,O_RDWR|O_CREAT,S_IRWXU);
	if( -1 == fd){
		return -1;
	}
	size = write(fd,buf1,strlen(buf1));
	if(size != strlen(buf1)){
		printf("write fail\n");
		return -1;
	}

	offset = lseek(fd,32,SEEK_SET);
	if(-1 == offset)
	{
		return -1;
	}
	size = write(fd, buf2, strlen(buf2));
	if(size != strlen(buf2))
	{
		printf("write fail2\n");
		return -1;
	}
	close(fd);
	return 0;
}
