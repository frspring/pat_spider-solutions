
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

vector<int> sqence;
vector<int> temp;
int powTable[500];
int maxmum=0;
int n;
int k;
void DFS(int now,int sum,int numSum,int used)
{
	if(sum==n&&used==k)
	{
		if(numSum>maxmum)
		{
			maxmum=numSum;
			sqence=temp;
		}
		return;
	}
	else if(used>=k)
	{
		return ;
	}
	if(n - sum<k-used)
		return ;
	temp.push_back(now);
	DFS(now,sum+powTable[now],numSum+now,used+1);
	temp.pop_back();
	if(now>1)
	{
		DFS(now-1,sum,numSum,used);
	}
}
int main()
{
	int p;
	scanf("%d%d%d",&n,&k,&p);
	int first=pow((double)n,1.0/p);
	for(int i=1;i<=first;i++)
	{
		powTable[i]=pow((double)i,p);
	}
	DFS(first,0,0,0);
	if(sqence.empty())
	{
		printf("Impossible");
	}
	else
	{
		printf("%d = ",n);
		for(int i=0;i<sqence.size();i++)
		{
			printf("%d^%d",sqence[i],p);
			if(i!=sqence.size()-1)
				printf(" + ");
		}
	}
	return 0;
}