
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool isSieved[20000]={true,true,false};
int prime[20000]={0};

const int maxn=20000;
void primeGen()
{
	int cnt=0;
	for(int k=2;k<maxn;k++)
	{
		if(!isSieved[k])
		{
			prime[cnt++]=k;
			for(int i=k;i<maxn;i+=k)
				isSieved[i]=true;
		}
	}
}
struct factor
{
	int fac;
	int cnt;
	factor()
	{
		cnt=0;
	}
};
int main()
{
	factor fc[40];
	primeGen();
	int n;
	int count=0;
	int sum=0;
	scanf("%d",&n);
	printf("%d=",n);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(int i=0;prime[i]<=sqrt((double)n);i++)
	{
		int flag=0;
		while(n%prime[i]==0)
		{
			sum++;
			fc[count].fac=prime[i];
			fc[count].cnt++;
			n/=prime[i];
			flag=1;
		}
		count+=flag;
	}
	if(n!=1)
	{
		fc[count].fac=n;
		fc[count].cnt++;
		count++;
	}
	for(int i=0;i<count;i++)
	{
		printf("%d",fc[i].fac);
		if(fc[i].cnt!=1)
			printf("^%d",fc[i].cnt);
		if(i!=count-1)
			printf("*");
	}

	return 0;
}