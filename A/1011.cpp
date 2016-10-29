
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
	double odd = 1;
	int wtl;
	for (int j = 0; j < 3; j++)
	{
		double t,c = 0.9;
		for (int i = 0; i < 3; i++)
		{
			scanf("%lf", &t);
			if (c < t)
			{
				c = t;
				wtl = i;
			}
		}
		odd *= c;
		if (wtl == 0)
			printf("W ");
		else if (wtl == 1)
			printf("T ");
		else
			printf("L ");
	}
	printf("%.2f", (odd*0.65 - 1) * 2);
}