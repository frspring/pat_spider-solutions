
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str[10][9] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
int main()
{
	int sum = 0 , temp;
	while (scanf("%1d",&temp)!=EOF)
	{
		sum += temp;
	}
	if (sum >= 100)
	{
		printf("%s ", str[sum / 100]);
	}
	if (sum >= 10)
	{
		printf("%s ", str[(sum / 10) % 10]);
	}
	printf("%s", str[sum % 10]);
	return 0;
}