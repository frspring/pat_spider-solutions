
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
bool cmp(node a,node b)
{
	return a.data<b.data;
}

node ind[100012];
node list[100012];
int main()
{
	int n,add;
	scanf("%d%d",&n,&add);
	int begin=add;
	int temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		ind[temp].addr=temp;
		scanf("%d%d",&ind[temp].data,&ind[temp].next);
	}
	int cnt=0;
	
	while(begin!=-1)
	{
		list[cnt].addr=ind[begin].addr;
		list[cnt].data=ind[begin].data;
		cnt++;
		begin=ind[begin].next;
	}
  	if(cnt==0)
	{
		printf("0 -1");
		return 0;
	}
	sort(list,list+cnt,cmp);
	printf("%d %05d\n",cnt,list[0].addr);
	for(int i=0;i<cnt;i++)
	{
		printf("%05d %d ",list[i].addr,list[i].data);
		if(list[i+1].addr==-1)
			printf("-1\n");
		else
		{
			printf("%05d\n",list[i+1].addr);
		}
	}
	return 0;
}