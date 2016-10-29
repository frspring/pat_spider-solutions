
#include <stdio.h>


int main()
{
	char temp=0;
	int num[10] = { 0 };
	while (scanf("%c",&temp)!=EOF)
	{
		/*if (temp == '\n')
			break;
		*/num[temp - '0']++;
	} 
	for (int i = 0; i < 10; i++)
	{
		if (num[i] != 0)
		{
			printf("%d:%d\n", i, num[i]);
		}
	}
	return 0;
}