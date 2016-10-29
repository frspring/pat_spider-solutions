
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

long long gcd(long long a,long long b)
{
	return b!=0?gcd(b,a%b):a;
}

struct ration
{
	long long up;
	long long down;
	ration()
	{
		up=0;
		down=1;
	}
	void simplify()
	{
		long long temp;
		if(up==0)
		{
			down=1;
			return;
		}
		if(down<0)
		{
			up=-up;
			down=-down;
		}
		temp = up<0?-up:up;
		long long t=gcd(temp,down);
		up/=t;
		down/=t;
	}
	void rationAdd(ration b)
	{
		ration temp=*this;
		this->up=temp.up*b.down+temp.down*b.up;
		this->down=temp.down*b.down;
		this->simplify();
	}
};


int main()
{
	int n;
	scanf("%d",&n);
	ration temp;
	ration sum;
	for(int i=0;i<n;i++)
	{
		scanf("%lld/%lld",&temp.up,&temp.down);
		temp.simplify();
		sum.rationAdd(temp);
	}
	long long integer=0;
	if(sum.up<0)
	{
		printf("-");
		sum.up=-sum.up;
	}
	integer=sum.up/sum.down;
	sum.up=sum.up%sum.down;
	if(integer==0&&sum.up==0)
		printf("0");
	if(integer>0)
		printf("%lld",integer);
	if(integer>0&&sum.up>0)
		printf(" ");
	if(sum.up>0)
		printf("%lld/%lld",sum.up,sum.down);
	return 0;
}