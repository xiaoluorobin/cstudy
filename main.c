#include <stdio.h>

extern int StrLen(char *string);

int main(void)
{
	char str[]="123456";
	int len = StrLen(str);
	printf("length is %i",len);
}
