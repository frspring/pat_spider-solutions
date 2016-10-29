
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int hashTrans(char c)
{
	if(c>='a'&&c<='z')
		return c-'a'+26;
	if(c>='A'&&c<='Z')
		return c-'A';
	if(c>='0'&&c<='9')
		return c-'0'+52;
	return 64;
}
int main()
{
	int shop[65]={0},eva[65]={0};
	char str1[1002],str2[1002];
	int s,e;
	gets(str1);
	s=strlen(str1);
	gets(str2);
	e=strlen(str2);
	for(int i=0;i<s;i++)
	{
		shop[hashTrans(str1[i])]++;
	}
	for(int i=0;i<e;i++)
	{
		eva[hashTrans(str2[i])]++;
	}
	int flag=1;
	int miss=0;
	for(int i=0;i<62;i++)
	{
		if(shop[i]<eva[i])
		{
			miss+=(eva[i]-shop[i]);
			flag=0;
		}
	}
	if(flag)
	{
		printf("Yes %d",s-e);
	}
	else
	{
		printf("No %d",miss);
	}
}