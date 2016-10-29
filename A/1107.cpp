
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


vector<int> per[1002];
int father[1002];
bool cmp(int a,int b)
{
	return a>b;
}
int findFather(int x)
{
	int a=x;
	while(father[x]!=x)
	{
		x=father[x];
	}
	int temp;
	while(father[a]!=a)
	{
		temp=a;
		a=father[a];
		father[temp]=father[a];
	}
	return x;
}
void Union(int a,int b)
{
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb)
		father[fb]=fa;
}
int main()
{
	int n;
	int num[1002]={0};
	scanf("%d",&n);
	for(int i=0;i<1002;i++)
		father[i]=i;
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d:",&t);
		for(int j=0;j<t;j++)
		{
			int temp;
			scanf("%d:",&temp);
			per[temp].push_back(i);
		}
	}
	for(int i=0;i<1002;i++)
	{
		auto end = per[i].end();
		for(auto j=per[i].begin();j!=end;j++)
		{
			if(j+1!=end)
				Union(j[0],j[1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		num[findFather(i)]++;
	}
	sort(num+1,num+n+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(num[i]!=0)
			cnt++;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d",num[i]);
		if(i!=cnt)
			printf(" ");
	}
	return 0;
}