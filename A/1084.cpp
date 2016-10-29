
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int hashtrans(char c)
{
	if(c>='a'&&c<='z')
		return c-'a';
	if(c>='A'&&c<='Z')
		return c-'A';
	if(c>='0'&&c<='9')
		return c-'0'+26;
	if(c=='_')
		return 36;
	return 37;
}
int main()
{
	int in[40]={0};
	int out[40]={0};
	char str1[100],str2[100];
	scanf("%s",str1);
	scanf("%s",str2);
	for (int i=0;str2[i]!=0;i++)
	{
		out[hashtrans(str2[i])]=1;
	}
	for (int i=0;str1[i]!=0;i++)
	{
		if(!out[hashtrans(str1[i])])
		{
			out[hashtrans(str1[i])]=1;
			if(str1[i]>='a'&&str1[i]<='z')
				str1[i]=str1[i]-'a'+'A';
			printf("%c",str1[i]);

		}
	}
}