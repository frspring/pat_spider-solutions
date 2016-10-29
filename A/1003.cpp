
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
int way[maxn]={0};
int team[maxn]={0};
int maxTeam[maxn]={0};
int Distance[maxn];
int main()
{
	int n,m,c1,c2;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	fill(graph[0],graph[0]+maxn*maxn,INF);
	fill(Distance,Distance+n,INF);
	Distance[c1]=0;
	way[c1]=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",team+i);
	}
	maxTeam[c1]=team[c1];
	for(int i=0;i<m;i++)
	{
		int a,b,d;
		scanf("%d%d%d",&a,&b,&d);
		graph[a][b]=graph[b][a]=d;
	}
	for(int i=0;i<n;i++)
	{
		int ans=-1;
		int minDis=INF;
		for(int j=0;j<n;j++)
		{
			if(!isv[j]&&Distance[j]<minDis)
			{
				minDis=Distance[j];
				ans=j;
			}
		}
		isv[ans]=true;
		for(int j=0;j<n;j++)
		{
			if(!isv[j]&&Distance[ans]+graph[ans][j]<Distance[j])
			{
				Distance[j]=Distance[ans]+graph[ans][j];
				maxTeam[j]=team[j]+maxTeam[ans];
				way[j]=way[ans];
			}
			else if(!isv[j]&&Distance[ans]+graph[ans][j]==Distance[j])
			{
				if(maxTeam[j]<team[j]+maxTeam[ans])
					maxTeam[j]=team[j]+maxTeam[ans];
				way[j]+=way[ans];
			}
		}
	}
	printf("%d %d",way[c2],maxTeam[c2]);
	return 0;
}