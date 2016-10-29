
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
bool cmp(string a,string b)
{
	char ta[11]={0},tb[11]={0};
	strcpy(ta,a.c_str());
	strcpy(tb,b.c_str());
	int la=strlen(ta);
	int lb=strlen(tb);
	for(int i=0;i<10;i++)
	{
		if(ta[i]==0)
			ta[i] = ta[i-la];
		if(tb[i]==0)
			tb[i] = tb[i-lb];
	}
	ta[10]=tb[10]=0;
	return strcmp(ta,tb)<0;
}
int main()
{
	int n;
	string num[10002];
	scanf("%d",&n);
	int flag = 0;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		//if(num[i])
		//	flag=1;
	}
	//if(flag == 0)
	//{
	//	printf("0");
	//	return 0;
	//}
	int j=0;
	sort(num,num+n,cmp);
	int tm;
	while((tm=atoi(num[j].c_str()))==0&&j<n)
	{
		j++;
	}
	printf("%d",tm);
	j++;
	for(;j<n;j++)
	{
		printf("%s",num[j].c_str());
	}
	return 0;
}