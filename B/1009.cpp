
#include <stdio.h>


int main()
{
	char str[80][80] = { 0 };
	int i = 0;
	while (scanf("%s",str+i)!=EOF)
	{
		i++;
	} 
	printf("%s", str[i-1]);
	for (int j = i-2; j >=0; j--)
	{
		printf(" %s", str[j]);
	}
	return 0;
}