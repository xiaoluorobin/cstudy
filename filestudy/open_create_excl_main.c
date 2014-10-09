#include<fcntl.h>
#include<stdio.h>

int main(void)
{
	int fd;
	char filename[] = "test.txt";

	fd = open(filename,O_RDWR|O_CREAT|O_EXCL,S_IRWXU);
	if(-1 == fd){
		printf("file exist!,reopen it");
		fd = open(filename,O_RDWR);
		printf("fd:%d\n",fd);
	}
	else{
		printf("open file %s succ,fd:%d\n",filename,fd);
	}
	return 0;
}
