
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
struct node
{
	int address;
	int data;
	int next;
	node()
	{
		address=-1;
	}
};
node list[100005];
node qst[100005];
int main()
{
	int first,n,k;
	int a,d,p;
	scanf("%d%d%d",&first,&n,&k);

	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&d,&p);
		list[a].address=a;
		list[a].data=d;
		list[a].next=p;
	}
	int cnt=0;
	for(int i=0;first!=-1;i++)
	{
		qst[i]=list[first];
		first=list[first].next;
		cnt++;
	}
	int time=cnt/k;
	for(int i=0;i<time;i++)
	{
		reverse(qst+i*k,qst+i*k+k);
	}
	for(int i=0;i<cnt;i++)
	{
		qst[i].next=qst[i+1].address;
		printf("%05d %d ",qst[i].address,qst[i].data);
		if(qst[i].next!=-1)
			printf("%05d\n",qst[i].next);
		else
			printf("-1\n");
	}

	return 0;
}