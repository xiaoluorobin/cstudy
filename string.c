#define END '\0'

int StrLen(char *string)
{
	int i = 0;
	while(*string++ != END)
	{
		i++;
	}
  return i;
}
