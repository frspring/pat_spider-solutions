
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int ai= 0;
	double an[1001] = { 0 };
	int ak = 0, bk = 0, c = 0;
	int bi=0;
	double bn[1001] = { 0 };
	cin >> ak;
	for (int i = 0; i < ak; i++)
	{
		cin >> ai;
		cin >> an[ai];
	}
	cin >> bk;
	for (int i = 0; i < bk; i++)
	{
		cin >> bi;
		cin >> bn[bi];
	}
	for (int i = 0; i <= 1000; i++)
	{
		an[i] += bn[i];
		if (fabs(an[i])>0.001)
			c++;
	}
	printf("%d", c);
	for (int i = 1000; i >= 0; i--)
	{
		if (fabs(an[i])>0.001)
			printf(" %d %1.1f", i, an[i]);
	}
	return 0;
}