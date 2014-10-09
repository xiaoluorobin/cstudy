#include <linux/cdrom.h>
#include <stdio.h>
#include <fcntl.h>

int main(void){

	int fd = open("/dev/cdrom",O_RDONLY);
	if(fd < 0){
		printf("open cdrom fail\n");
		return -1;
	}
	if(!ioctl(fd,CDROMEJECT,NULL)){
		printf("succ ejected\n");
	}
	else{
		printf("fail to ejected\n");
	}
	close(fd);
	return 0;
}
