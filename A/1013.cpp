
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
using namespace std;

bool road[1002][1002]={0};
bool isv[1002]={false};
int n,m,k;
void DFS(int city)
{
	isv[city]=true;
	for(int i=1;i<=n;i++)
	{
		if(!isv[i]&&road[city][i])
		{
			DFS(i);
		}
	}
}
int DfsTrvl()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!isv[i])
		{
			DFS(i);
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		road[a][b]=road[b][a]=true;
	}
	int init=1;
	fill(isv+1,isv+n+1,false);
	for(int i=0;i<k;i++)
	{
		int cnt;
		int temp;
		scanf("%d",&temp);
		isv[temp]=true;
		cnt=DfsTrvl();
		printf("%d\n",cnt-init);
		fill(isv+1,isv+n+1,false);
	}
	return 0;
}