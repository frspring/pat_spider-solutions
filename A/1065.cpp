
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;

int main()//C J B
{
	long double a, b, c;
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%Lf%Lf%Lf", &a, &b,&c);
		printf("Case #%d: ",i+1);
		if (a + b > c+0.0001)
			printf("true");
		else
		{
			printf("false");
		}
		printf("\n");
	}
}