#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd;
	int i;
	size_t size = -1;
	char buf[10];
	char filename[] = "test.txt";

	fd = open(filename,O_RDONLY);
	if(-1 == fd){
		printf("Open file %s failure,fd:%d\n",filename,fd);
	}else {
		printf ("Open file %s succ,fd:%d\n",filename,fd);
	}

	while(size){
		size = read(fd,buf,10);
		if(-1 == size)
		{
			close(fd);
			printf("read file error occurs\n");
		}
		else{
			if(size >0 ){
				printf("read %d bytes:",(int)size);
				printf("\"");
				for(i = 0;i<size;i++){
					printf("%d ",*(buf+i));
				}
				printf("\"\n");
			}
			else{
				printf("reach the end of file\n");
			}
		}

	}
	return 0;
}
