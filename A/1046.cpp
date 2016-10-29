
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;
int distanc[100000] = { 0 };

int main()//C J B
{
	int n = 0,m;
	int sum = 0;
	scanf("%d", &n);
	for (int i = 1; i < n+1; i++)
	{
		scanf("%d", &sum);
		distanc[i] = sum+distanc[i-1];
	}
	scanf("%d", &m);
	int x, y, temp, k;
	for (int i = 0; i < m; i++)
	{
		int dsum = 0;
		scanf("%d%d", &x, &y);
		if (x > y)
		{
			x = x^y;
			y = x^y;
			x = x^y;
			/*
			temp = x;
			x = y;
			y = temp;*/
		}
		dsum = distanc[y-1]-distanc[x-1];
		dsum = (dsum > (distanc[n] >> 1)) ? distanc[n] - dsum : dsum;
		printf("%d\n", dsum);
	}
}