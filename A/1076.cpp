
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
#include <string>
#include <map>
using namespace std;

bool graph[1002][1002]={0};
bool isv[1002]={false};
int depth[1002]={0};
int n,l;

int BFS(int root)
{
	int member=0;
	queue<int> qe;
	qe.push(root);
	isv[root]=true;
	while(!qe.empty())
	{
		int top = qe.front();
		qe.pop();
		for(int i=1;i<=n;i++)
		{
			if(!isv[i]&&graph[i][top]&&depth[top]<l)
			{
				member++;
				isv[i]=true;
				depth[i]=depth[top]+1;
				qe.push(i);
			}
		}
	}
	return member;
}
int main()
{
	scanf("%d%d",&n,&l);
	int temp;

	for(int i=1;i<=n;i++)
	{
		int m;
		scanf("%d",&m);
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&temp);
			graph[i][temp]=true;
		}
	}
	int k;
	int sum;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		fill(isv+1,isv+n+1,false);
		fill(depth+1,depth+n+1,0);
		scanf("%d",&temp);
		sum = BFS(temp);
		printf("%d\n",sum);
	}
	return 0;
}