#include <dlfcn.h>
#include <stdio.h>

int main(void)
{
	char src[]="123456";
	int(*funstr)(char *str);
	void *phandle = dlopen("./libstr.so",RTLD_LAZY);
	if(!phandle)
	{
		printf("failed to load library!\n");
	}
	char *perr = dlerror();
	if(perr != NULL)
	{
		printf("%s\n",perr);
		return 0;
	}

	funstr = dlsym(phandle,"StrLen");

	perr = dlerror();
	if(perr != NULL)
	{
		printf("%s\n",perr);
		return 0;
	}
	printf("this len is:%d\n",funstr(src));
	dlclose(phandle);
	return 0;
}
