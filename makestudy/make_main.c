#include <stdio.h>
#include "add.h"
#include "sub.h"

int main(void)
{
	int i=100;
	int j=1;

	printf("add i+j=%d j=%d\r\n",add(i,j),j);
	printf("sub i-j=%d\r\n",sub(i,j));
}
