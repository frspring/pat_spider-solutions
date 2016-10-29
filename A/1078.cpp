
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool isSieved[100015]={true,true,false};
int prime[100015]={0};

void primeGen()
{
	int n=100004;
	int temp=2;
	int cnt=0;
	while(1)
	{
		prime[cnt]=temp;
		cnt++;
		for(int i=temp;i<n;i+=temp)
		{
			isSieved[i]=true;
		}
		int j=temp;
		for(;j<n;j++)
		{
			if(!isSieved[j])
			{
				temp=j;
				break;
			}
		}
		if(j==n)
			break;
	}
}
bool used[11000]={false};
int main()
{
	primeGen();
	
	int mSize,n;
	scanf("%d%d",&mSize,&n);
	int prSize;
	for(int i=0;;i++)
	{
		if(prime[i]>=mSize)
		{
			prSize=prime[i];
			break;
		}
	}
	int temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		int t=temp%prSize;
		if(i!=0)
			printf(" ");
		if(!used[t])
		{
			used[t]=true;
			printf("%d",t);
			continue;
		}
		int j=1;
		for(;j<prSize;j++)
		{
			if(!used[(t+j*j)%prSize])
			{
				used[(t+j*j)%prSize]=true;
				printf("%d",(t+j*j)%prSize);
				break;
			}
		}
		if(j==prSize)
			printf("-");
	}

	return 0;
}