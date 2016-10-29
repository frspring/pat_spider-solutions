
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
//////////////////////////////
inline int ctoi(char c)
{
	if(c>='0'&&c<='9')
		return c-'0';
	else
		return c-'a'+10;
}
long long strToll(char* s,long long radix)
{
	int len=strlen(s);
	long long sum=0;
	for(int i=0;i<len;i++)
	{
		sum*=radix;
		if(ctoi(s[i])>=radix)
			return -1;
		sum+=ctoi(s[i]);
	}
	return sum;
}
int main()
{
	char n1[11];
	char n2[11];
	int tag,radix;
	scanf("%s%s%d%d",n1,n2,&tag,&radix);
	long long known;
	char* unknown;
	if(tag==1)
	{
		known=strToll(n1,radix);
		unknown=n2;	
	}
	else
	{
		known = strToll(n2,radix);
		unknown = n1;
	}
	long long t=2;
	if(strlen(unknown)==1&&ctoi(unknown[0])<known)
	{
		printf("Impossible");
		return 0;
	}
	while(known > strToll(unknown,t))
	{
		t<<=1;
		if(t<0)
		{
			printf("Impossible");
			return 0;
		}
	}
	long long left=t>>1;
	long long right=t;
	long long mid=(left+right)/2;
	while(left<=right)
	{
		if(known>strToll(unknown,mid))
			left=mid+1;
		else if(known<strToll(unknown,mid))
			right = mid-1;
		else
		{
			printf("%lld",mid);
			return 0;
		}
		mid=(right+left)/2;
	}
	printf("Impossible");

	return 0;
}