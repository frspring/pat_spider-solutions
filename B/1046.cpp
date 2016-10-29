
#include<iostream>
#include<stdio.h>
#include<stdint.h>
using namespace std;
int main()
{
	int n;
	int a, ag, b, bg;
	int ad = 0, bd = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &a, &ag, &b, &bg);
		if (ag == (a + b) && bg != (a + b))
			ad++;
		else if (ag != (a + b) && bg == (a + b))
			bd++;
	}
	printf("%d %d", bd, ad);
}