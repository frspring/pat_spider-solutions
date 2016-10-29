
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

const int maxn=702;

const int INF=1000000000;
int graph[maxn][maxn];
int cost[maxn][maxn];
bool isv[maxn]={false};
int allCost[maxn];
int pre[maxn]={0};
int Distance[maxn];
int n,m,start,destiny;

void dijkstra(int begin)
{
	fill(Distance,Distance+maxn,INF);			//初始化最短路径
	fill(allCost,allCost+maxn,INF);			//初始化最短路径
	Distance[begin]=0;
	allCost[begin]=0;
	for(int i=0;i<n;i++)
		pre[i]=i;
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
		if(ans==-1)
			return ;
		isv[ans]=true;
		for(int i=0;i<=n;i++)
		{
			if(Distance[i]>Distance[ans]+graph[ans][i])
			{
				Distance[i]=Distance[ans]+graph[ans][i];
				allCost[i]=allCost[ans]+cost[ans][i];
				pre[i]=ans;
			}
			else if(Distance[i]==Distance[ans]+graph[ans][i]&&allCost[i]>allCost[ans]+cost[ans][i])
			{
				allCost[i]=allCost[ans]+cost[ans][i];
				pre[i]=ans;
			}
		}
	}
}
void print(int a)				//递归打印路径，用while(1)测试得到是此函数发生段错误
{
	if(start==a)
	{
		printf("%d ",start);
		return ;
	}
	print(pre[a]);
	printf("%d ",a);
	return ;
}
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,INF);
	scanf("%d%d%d%d",&n,&m,&start,&destiny);
	
	for(int i=0;i<m;i++)
	{
		int a,b,dist,cos;
		scanf("%d%d%d%d",&a,&b,&dist,&cos);
		graph[a][b]=graph[b][a]=dist;
		cost[a][b]=cost[b][a]=cos;
	}
	dijkstra(start);								//dijkstra算法找最短路径
	print(destiny);
	printf("%d %d",Distance[destiny],allCost[destiny]);
	return 0;
}