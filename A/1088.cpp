
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
	long long front;
	int isT;
	long long uu;
	char str[30];
	ration()
	{
		front=-1;
		isT=1;
	}
	void simplify()
	{
		if(down<0)
		{
			up=-up;
			down=-down;
		}
		if(up<0)
		{
			isT=-1;
			up=-up;
		}
		else
		{
			isT=1;
		}
		if(up==0)
		{
			down=1;
			return;
		}
		int t=gcd(up,down);
		up/=t;
		down/=t;
	}
	char* print()
	{
		if(front == -2)
		{
			printf("Inf");
			return str;
		}
		front = up/down;
		uu = up%down;
		if(isT==-1)
			printf("(-");
		if(front>0)
		{
			printf("%lld",front);
			if(uu>0)
				printf(" ");
	
		}
		if(uu>0)
			printf("%lld/%lld",uu,down);
		else if(front>0)
			;
		else
			printf("0");
		if(isT==-1)
			printf(")");
		return str;
	}
};
int main()
{
	int n;
	ration a,b,c;
	scanf("%lld/%lld",&a.up,&a.down);
	scanf("%lld/%lld",&b.up,&b.down);
	a.simplify();
	b.simplify();
	c.up=a.up*b.down*a.isT+a.down*b.up*b.isT;
	c.down=a.down*b.down;
	a.print();
	printf(" + ");
	b.print();
	printf(" = ");
	c.simplify();
	c.print();
	printf("\n");
	//-
	c.up=a.up*b.down*a.isT - a.down*b.up*b.isT;
	c.down=a.down*b.down;
	a.print();
	printf(" - ");
	b.print();
	printf(" = ");
	c.simplify();
	c.print();
	printf("\n");
	//*
	c.up=a.up*b.up*a.isT*b.isT;
	c.down=a.down*b.down;
	a.print();
	printf(" * ");
	b.print();
	printf(" = ");
	c.simplify();
	c.print();
	printf("\n");
	// /
	c.up=a.up*b.down*a.isT*b.isT;
	c.down=a.down*b.up;
	a.print();
	printf(" / ");
	b.print();
	printf(" = ");
	if(b.up==0)
		printf("Inf");
	else
	{
		c.simplify();
		c.print();
	}
	printf("\n");

	return 0;
}