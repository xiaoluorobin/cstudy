#include <fcntl.h>
#include <stdio.h>

int main(void)
{
		int i;
		int fd=0;

		for(i = 0; fd >=0; i++)
		{
			fd = open("test.txt",O_RDONLY);
			if(fd > 0){
				printf("fd : %d\n",fd);
			}
			else{
				printf("error, can't open file\n");
				exit(0);
			}
		}
}
