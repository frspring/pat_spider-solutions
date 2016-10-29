
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

const int maxn=502;

const int INF=1000000000;
int graph[maxn][maxn];
bool isv[maxn]={false};
int current[maxn]={0};
vector<int> pre[maxn];
int Distance[maxn];
int cap,n,m,sp;

void dijkstra(int begin)
{
	Distance[begin]=0;
	for(int j=0;j<=n;j++)
	{
		int mindistance=INF;
		int ans=-1;
		for(int i=0;i<=n;i++)
		{
			if(Distance[i]<mindistance&&!isv[i])
			{
				mindistance=Distance[i];
				ans=i;
			}
		}
		isv[ans]=true;
		for(int i=0;i<=n;i++)
		{
			if(Distance[i]>Distance[ans]+graph[ans][i])
			{
				Distance[i]=Distance[ans]+graph[ans][i];
				pre[i].clear();
				pre[i].push_back(ans);
			}
			else if(Distance[i]==Distance[ans]+graph[ans][i])
			{
				pre[i].push_back(ans);
			}
		}
	}
}
vector<int> tempRoad;
vector<vector<int>> bestRoad;
int left=0;
int take=0;
void DFS(int begin)
{
	tempRoad.push_back(begin);
	if(begin==0)
	{
		bestRoad.push_back(tempRoad);
	}
	for(int i=0;i<pre[begin].size();i++)
	{
		DFS(pre[begin][i]);
	}
	tempRoad.pop_back();
}
int main()
{
	scanf("%d%d%d%d",&cap,&n,&sp,&m);
	fill(graph[0],graph[0]+maxn*maxn,INF);
	fill(Distance,Distance+maxn,INF);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",current+i);
		current[i]-=cap/2;

	}
	for(int i=0;i<m;i++)
	{
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		graph[a][b]=graph[b][a]=d;
	}
	current[0]=0;
	dijkstra(0);
	DFS(sp);

	int minNum=INF;
	int remain;
	vector<int> opt;
	for(int i=0;i<bestRoad.size();i++)
	{
		int t=0;
		int mn=0;
		reverse(bestRoad[i].begin(),bestRoad[i].end());
		for(int j=0;j<bestRoad[i].size();j++)
		{
			t+=current[bestRoad[i][j]];
			if(t<0)
			{
				mn+=-t;
				t=0;
			}
		}
		if(minNum>mn)
		{
			minNum=mn;
			opt=bestRoad[i];
			remain=t;
		}
		else if(minNum==mn&&remain>t)
		{
			minNum=mn;
			opt=bestRoad[i];
			remain=t;
		}
	}
	printf("%d ",minNum);
	for(int i=0;i<opt.size();i++)
	{
		printf("%d",opt[i]);
		if(i!=opt.size()-1)
			printf("->");
	}
	printf(" %d",remain);
	
	return 0;
}