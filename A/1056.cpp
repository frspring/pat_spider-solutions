
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

struct player
{
	int w;
	int rank;
};
struct mice
{
	int id;
	int rank;
	int w;
};
mice mi[5000];
player p[5000];
int main()
{
	int np,ng;
	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++)
	{
		scanf("%d",&p[i].w);
	}
	int ss;
	for(int i=0;i<np;i++)
	{
		scanf("%d",&ss);
		mi[i].w=p[ss].w;
		mi[i].id=ss;
	}
	queue<mice> qe;
	for(int i=0;i<np;i++)
	{
		qe.push(mi[i]);
	}
	while(qe.size()>1)
	{
		int k=qe.size()/ng+1;
		if(qe.size()%ng==0)
			k=qe.size()/ng;
		int len=qe.size();
		for(int i=0;i<k;i++)
		{
			int mx=0;
			queue<mice> temp;
			player t;
			for(int j=0;i*ng+j<len&&j<ng;j++)
			{
				mx=max(qe.front().w,mx);
				temp.push(qe.front());
				qe.pop();
			}
			while(!temp.empty())
			{
				if(temp.front().w==mx)
				{
					qe.push(temp.front());
					temp.pop();
				}
				else
				{
					p[temp.front().id].rank=k+1;
					temp.pop();
				}
			}//一个组排完
		}//全部组排完
	}//下一次
	p[qe.front().id].rank=1;
	for(int i=0;i<np;i++)
	{
		printf("%d",p[i].rank);
		if(i!=np-1)
			printf(" ");
	}
	return 0;
}