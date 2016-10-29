
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

struct node
{
	int data;
	int addr;
	int next;
	node()
	{
		addr=-1;
	}
};

node ind[100012];
node list[100012];
node extra[100012];
bool isVauleExist[10005]={false};
int main()
{
	int add,n;
	scanf("%d%d",&add,&n);
	int temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		ind[temp].addr=temp;
		scanf("%d%d",&ind[temp].data,&ind[temp].next);
	}
	int begin = add;
	int cnt=0;
	int ent=0;
	while(begin!=-1)
	{
		if(isVauleExist[abs(ind[begin].data)])
		{
			extra[ent].data=ind[begin].data;
			extra[ent].addr=begin;
			ent++;
		}
		else
		{
			list[cnt].data=ind[begin].data;
			list[cnt].addr=begin;
			isVauleExist[abs(ind[begin].data)]=true;
			cnt++;
		}
		begin = ind[begin].next;
	}
	for(int i=0;i<cnt;i++)
	{
		printf("%05d %d ",list[i].addr,list[i].data);
		if(list[i+1].addr==-1)
			printf("-1\n");
		else
			printf("%05d\n",list[i+1].addr);
	}
	for(int i=0;i<ent;i++)
	{
		printf("%05d %d ",extra[i].addr,extra[i].data);
		if(extra[i+1].addr==-1)
			printf("-1\n");
		else
			printf("%05d\n",extra[i+1].addr);
	}
	return 0;
}