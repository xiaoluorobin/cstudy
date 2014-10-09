#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	int i;
  ssize_t size = -1;
	char buf[] = "my name is robin.";
	char filename[] = "test.txt";
	fd = open(filename,O_RDWR|O_APPEND);
	if(-1 == fd){
		printf("open file %s fail,fd:%d\n",filename,fd);
	}
	else{
		printf("Open succ\n");
	}
	size = write(fd,buf,strlen(buf));
	printf("write %d bytes to file %s\n",(int)size,filename);
	close(fd);
	return 0;
}
