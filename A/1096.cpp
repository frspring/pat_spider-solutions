
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int fc[100005]={0};

int main()
{
	int n;
	int cnt=0;
	int max=-1;
	scanf("%d",&n);
	for(int i=2;i<=(int)sqrt((double)n);i++)
	{
		int temp = n;
		while((temp%(i+fc[i]))==0)
		{
			temp/=(i+fc[i]);
			fc[i]++;
			if(fc[i]>max)
				max=fc[i];
		}
	}
	if(max==-1)
	{
		printf("1\n%d",n);
		return 0;
	}
	printf("%d\n",max);
	for(int i=2;i<=(int)sqrt((double)n);i++)
	{
		int temp = n;
		if(fc[i]==max)
		{
			printf("%d",i);
			for(int j=1;j<max;j++)
				printf("*%d",i+j);
			return 0;
		}
	}

	return 0;
}