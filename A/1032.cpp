
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
	char data;
	int addr;
	int next;
	node()
	{
		addr=-1;
	}
};
node ind[100012];
int list1[100012];
int list2[100012];
int main()
{
	int begin1,begin2,n;
	scanf("%d%d%d",&begin1,&begin2,&n);
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		ind[temp].addr=temp;
		scanf(" %c %d",&ind[temp].data,&ind[temp].next);
	}
	fill(list1,list1+100002,-1);
	int cnt1=0;
	while(begin1!=-1)
	{
		list1[cnt1] = ind[begin1].addr;
		begin1=ind[begin1].next;
		cnt1++;
	}
	int cnt2=0;
	while(begin2!=-1)
	{
		list2[cnt2] = ind[begin2].addr;
		begin2=ind[begin2].next;
		cnt2++;
	}
	reverse(list1,list1+cnt1);
	reverse(list2,list2+cnt2);
	int point=0;
	while(list1[point]==list2[point])
	{
		point++;
		if(point>=cnt1||point>=cnt2)
			break;
	}
	if(point == 0)
		printf("-1");
	else if(list1[point-1]==-1)
		printf("-1");
	else
		printf("%05d",list1[point-1]);
	return 0;
}