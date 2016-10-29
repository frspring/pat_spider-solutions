
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<algorithm>
using namespace std;
int main()
{
	int n = 0, Anum[5] = { 0 },Aout[5];
	int A1sum = 0;
	int A2[1002] = { 0 },A2sum=0;
	double A4sum = 0;
	int A5max = 0;
	int temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		switch (temp%5)
		{
		case 0:
			A1sum += temp & 1 ? 0 : temp;
			break;
		case 1:
			A2[Anum[1]] = temp;
			break;
		case 2:
			break;
		case 3:
			A4sum += temp;
			break;
		case 4:
			A5max = A5max > temp ? A5max : temp;
			break;
		default:
			break;
		}
		Anum[temp % 5]++;
		if (temp % 5 == 0 && temp % 10 != 0)
			Anum[temp % 5]--;
	}
	Aout[0] = A1sum;
	for (int i = 0; i < Anum[1]; i++)
	{
		if (i % 2 == 0)
			A2sum += A2[i];
		else
			A2sum -= A2[i];
	}
	Aout[1] = A2sum;
	Aout[2] = Anum[2];
	A4sum = A4sum*1.0 / Anum[3];
	Aout[4] = A5max;
	for (int i = 0; i < 5; i++)
	{
		if (Anum[i] == 0)
			printf("N");
		else
		{
			if (i == 3)
				printf("%.1lf", A4sum);
			else printf("%d", Aout[i]);
		}
		if (i != 4)
			printf(" ");
	}
}