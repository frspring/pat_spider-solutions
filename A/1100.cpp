
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
const char etoml[14][5]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const char etomh[14][5]={"-","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int main()
{
	map<string,int> mtoe;
	for(int i=0;i<13;i++)
	{
		mtoe[etoml[i]]=i;
		mtoe[etomh[i]]=i*13;
	}
	int n;
	scanf("%d",&n);
	char temp[15];
	gets(temp);
	for(int i=0;i<n;i++)
	{
		int num;
		gets(temp);
		if(temp[0]>='0'&&temp[0]<='9')
		{
			num=atoi(temp);
			if(num/13>0&&num%13>0)
			{
				printf("%s %s\n",etomh[num/13],etoml[num%13]);
			}
			else if(num/13>0&&num%13==0)
				printf("%s\n",etomh[num/13]);
			else
				printf("%s\n",etoml[num%13]);
		}
		else
		{
			if(strlen(temp)>5)
			{
				char* h,*l;
				h=temp,l=temp+4;
				temp[3]=0;
				num=mtoe[h]+mtoe[l];
			}
			else
			{
				num=mtoe[temp];
			}
			printf("%d\n",num);
		}
	}
	return 0;
}