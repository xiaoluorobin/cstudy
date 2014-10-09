#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ret;
	printf("system process id is,%d\n",getpid());
	ret = system("ping www.hisense.com -c 2");
	printf("return is %d\n",ret);
	return 0;
}
