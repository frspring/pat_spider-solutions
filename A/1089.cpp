
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
bool isInc(int* s,int size)
{
	if(size==1)
		return true;
	for(int i=1;i<size;i++)
	{
		if(s[i]<s[i-1])
			return false;
	}
	return true;
}
//////////////////////////////
int main()
{
	int squence[103];
	int sorted[103];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",squence+i);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",sorted+i);
	}

	bool isInsert=true;
	int last=1;
	int cnt=1;
	int state = 0;
	for(;cnt<n;cnt++)
	{
		if(sorted[cnt]<sorted[cnt-1]&&state==0)
		{
			state=1;
		}
		if(state==1&&sorted[cnt]!=squence[cnt])
			isInsert=false;
	}

	if(isInsert)
	{
		printf("Insertion Sort\n");
		for(int i=1;i<n;i++)
		if(sorted[i]<sorted[i-1])
		{
			sort(sorted,sorted+i+1);
			for(int j=0;j<n;j++)
			{
				printf("%d",sorted[j]);
				if(j!=n-1)
					printf(" ");
			}
			return 0;
		}
		for(int j=0;j<n;j++)
		{
			printf("%d",sorted[j]);
			if(j!=n-1)
				printf(" ");
		}
		return 0;
	}
	else
	{
		int step=2;
		printf("Merge Sort\n");
		while(1)
		{
			for(int i=0;i<n;i+=step)
			{
				if(i+step>n)
				{
					if(!isInc(sorted+i,n-i))
					goto label;
				}
				else if(!isInc(sorted+i,step))
					goto label;
			}
			step<<=1;
		}
label:
		for(int i=0;i<n;i+=step)
		{
			if(i+step>n)
				step=n-i;
			sort(sorted+i,sorted+i+step);
		}
		for(int j=0;j<n;j++)
		{
			printf("%d",sorted[j]);
			if(j!=n-1)
				printf(" ");
		}
	}
	return 0;
}