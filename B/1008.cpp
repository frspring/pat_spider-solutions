
#include<iostream>
#include<stdio.h>
#include<stdint.h>
using namespace std;
int main()
{
	int n = 0, m = 0;
	int num[102] = { 0 };
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", num + i);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d", num[(i + n*100 -m)%n]);
		if (i != n - 1)
			printf(" ");
	}
}