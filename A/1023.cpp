
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int timeOfN[10]={0};
int test[10]={0};
int main()
{
	char num[24];
	gets(num);
	int len=strlen(num);
	for(int i=0;i<len;i++)
	{
		timeOfN[num[i]-'0']++;
	}
	reverse(num,num+len);
	int c=0;
	for(int i=0;i<len;i++)
	{
		int t;
		t=(num[i]-'0')*2+c;
		c=(int)(t>9);
		num[i]=t%10+'0';
	}
	num[len]=c==1?1+'0':0;
	num[len+1]=0;
	reverse(num,num+len+c);
	if(c==1)
	{
		printf("No\n");
		printf("%s",num);
		return 0;
	}
	for(int i=0;i<len;i++)
	{
		test[num[i]-'0']++;
	}
	bool flag=true;
	for(int i=0;i<10;i++)
	{
		if(test[i]!=timeOfN[i])
			flag=false;
	}
	if(flag)
		printf("Yes\n%s",num);
	else
		printf("No\n%s",num);
	return 0;
}