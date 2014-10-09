#include <sys/stat.h>
#include <stdio.h>

int main(void)
{
		struct stat st;
		if(-1 == stat("test.txt", &st)){
			printf("get stat fail\n");
			return -1;
		}

		printf("size is %d\n",(int)st.st_size);
		return 0;
}
