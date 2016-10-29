
#include<iostream>
#include<stdio.h>
#include<stdint.h>
using namespace std;
int main()
{
	int n = 0;
	long long a, b, pa=0, pb=0;
	int da, db;
	scanf("%lld%d%lld%d", &a, &da, &b, &db);
	while (a!=0)
	{
		if (a % 10 == da)
		{
			pa *= 10;
			pa += da;
		}
		a /= 10;
	}
	while (b != 0)
	{
		if (b % 10 == db)
		{
			pb *= 10;
			pb += db;
		}
		b /= 10;
	}
	printf("%ld", pa + pb);
}