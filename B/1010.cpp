
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<algorithm>
using namespace std;

int main()//C J B
{
	int i = 0;
	int coefficience;
	int exponent;
	int flag = 0;
	while (scanf("%d%d",&coefficience,&exponent)!=EOF)
	{
		i++;
		if (exponent == 0)
			continue;
		else
		{
			flag = 1;
			if(i==1)
				printf("%d %d", coefficience*exponent, exponent - 1);
			else
				printf(" %d %d", coefficience*exponent, exponent - 1);
		}
	}
	if (flag == 0)
		printf("0 0");
}