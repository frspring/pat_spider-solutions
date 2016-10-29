
#include <stdio.h>


int main()
{
	int num;
	scanf("%d", &num);
	int n[3] = { 0 };
	int i = 0;
	do
	{
		n[i++] = num % 10;
		num /= 10;
	} while (num != 0);
	while (n[2]!=0)
	{
		printf("B");
		n[2]--;
	}
	while (n[1] != 0)
	{
		printf("S");
		n[1]--;
	}
	i = 1;
	while (n[0] != 0)
	{
		printf("%d", i++);
		n[0]--;
	}
	return 0;
}