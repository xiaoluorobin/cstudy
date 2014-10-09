//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	char filename[] = "test.txt";
	fd = open(filename,O_RDWR);
	if(-1 == fd){
		printf("open file %s failure!,fd:%d\n",filename,fd);
	}
	else{
		printf("open file %s succ,fd:%d\n",filename,fd);
	}
	return 0;
}
