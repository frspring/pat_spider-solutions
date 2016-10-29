
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
	double nomial[2][1001] = { 0 };
	double result[2001] = { 0 };
	int k1, k2;
	int temp;
	scanf("%d", &k1);
	for (int i = 0; i < k1; i++)
	{
		scanf("%d", &temp);
		scanf("%lf",&nomial[0][temp]);
	}
	scanf("%d", &k2);
	for (int i = 0; i < k2; i++)
	{
		scanf("%d", &temp);
		scanf("%lf",&nomial[1][temp]);
	}
	for (int i = 1000; i >= 0; i--)
	{
		if (nomial[0][i]  > 0.01 || nomial[0][i] < -0.01)
		{
			for (int j = 1000; j >= 0; j--)
			{
				result[i + j] += nomial[0][i] * nomial[1][j];
			}
		}
	}
	int k = 0;
	for (int i = 0; i < 2001; i++)
	{
		if (result[i] > 0.01||result[i] < -0.01)
			k++;
	}
	printf("%d", k);
	for (int i = 2000; i >=0 ; i--)
	{
		if (result[i] > 0.01||result[i] < -0.01)
			printf(" %d %.1f", i, result[i]);
	}
	if (k == 0)
		printf(" 0 0.0");
}