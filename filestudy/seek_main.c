#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	off_t offset;
	offset = lseek(stdin, 0, SEEK_CUR);

	if(-1 == offset){
		printf("stdin cann't seek\n");
	}
	else{
		printf("stdin can seek\n");
	}
	return 0;
}
