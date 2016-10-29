
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;


struct student
{
	long long no;
	int trialSeat;
	int seat;
};
int main()
{
	student pip[1000];
	int n,k;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%d%d", &pip[i].no, &pip[i].trialSeat, &pip[i].seat);
	}
	scanf("%d", &k);
	int test;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &test);
		for (int j = 0; j < n; j++)
		{
			if (test == pip[j].trialSeat)
			{
				printf("%lld %d\n", pip[j].no, pip[j].seat);
			}
		}
	}
	
}