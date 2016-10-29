
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
void stanarlize(char*a,int& p)
{
	for(int i=0;a[i]!=0;i++)
	{
		if(a[i]!='0')
		{
			strcpy(a,a+i);
			break;
		}
	}
	p=strlen(a);
	if(a[0]=='0')
	{
		p=0;
		a[1]=0;
		return ;
	}
	if(a[0]=='.')
	{
		for(int i=0;a[i]!=0;i++)
		{
			if(a[i]!='.'&&a[i]!='0')
			{
				p=-i+1;
				strcpy(a,a+i);
				break;
			}
		}
		if(a[0]=='.')
		{
			a[0]='0';
			a[1]=0;
			p=0;
		}
	}
	else
	{
		for(int i=0;a[i]!=0;i++)
		{
			if(a[i]=='.')
			{
				p=i;
				strcpy(a+i,a+i+1);
				break;
			}
		}
	}
}
int main()
{
	char a[110]={0},b[110]={0};
	int n;
	scanf("%d%s%s",&n,a,b);
	int lenA=strlen(a);
	int lenB=strlen(b);
	int cnt1=lenA;
	int cnt2=lenB;
	stanarlize(a,cnt1);
	stanarlize(b,cnt2);
	fill(a+strlen(a),a+110,0);
	fill(b+strlen(b),b+110,0);
	for(int i=0;i<n;i++)
	{
		if(a[i]==0)
			a[i]='0';
		if(b[i]==0)
			b[i]='0';
	}
	if(memcmp(a,b,sizeof(char)*n)==0&cnt1==cnt2)
	{
		a[n]=0;
		printf("YES 0.%s*10^%d",a,cnt1);
	}
	else
	{

		a[n]=0;
		b[n]=0;
		printf("NO ");
		printf("0.%s*10^%d",a,cnt1);
		printf(" 0.%s*10^%d",b,cnt2);
	}
	return 0;
}