
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

const int maxn=300;

const int INF=1000000000;
int graph[maxn][maxn];
bool isv[maxn]={false};
int happiness[maxn];
int htonow[maxn]={0};
int pre[maxn]={0};
int Distance[maxn];
int num[maxn]={0};
int n,k,s;
int way[maxn]={0};
string start;

void dijkstra(int begin)
{
	fill(Distance,Distance+maxn,INF);			//初始化最短路径
	fill(num,num+maxn,INF);			//初始化最短路径
	Distance[begin]=0;
	num[begin]=0;
	way[begin]=1;
	for(int i=1;i<=n;i++)
		pre[i]=i;
	for(int j=1;j<=n;j++)
	{
		int mindistance=INF;
		int ans=-1;
		for(int i=1;i<=n;i++)
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
		for(int i=1;i<=n;i++)
		{
			if(Distance[i]>Distance[ans]+graph[ans][i])
			{
				Distance[i]=Distance[ans]+graph[ans][i];
				htonow[i]=htonow[ans]+happiness[i];
				num[i]=num[ans]+1;
				pre[i]=ans;
				way[i]=way[ans];
			}
			else if(Distance[i]==Distance[ans]+graph[ans][i]&&htonow[i]<htonow[ans]+happiness[i])
			{
				htonow[i]=htonow[ans]+happiness[i];
				pre[i]=ans;
				num[i]=num[ans]+1;
				way[i]+=way[ans];
			}
			else if(Distance[i]==Distance[ans]+graph[ans][i]&&htonow[i]==htonow[ans]+happiness[i]&&num[i]>num[ans]+1)
			{
				pre[i]=ans;
				way[i]+=way[ans];
				num[i]=num[ans]+1;
			}
			else if(Distance[i]==Distance[ans]+graph[ans][i])
			{
				way[i]+=way[ans];
			}
		}
	}
}
string cityNum[maxn];
map<string,int> numCity;

void print(int a)
{
	if(pre[a]!=a)
	{
		print(pre[a]);
	}
	cout<<cityNum[a];
	if(a!=numCity["ROM"])
		cout<<"->";
}
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,INF+1);

	cin>>n>>k>>start;
	numCity[start]=1;
	cityNum[1]=start;
	for(int i=2;i<=n;i++)
	{
		string str;
		int temp;
		cin>>str>>temp;
		cityNum[i]=str;
		numCity[str]=i;
		happiness[i]=temp;
	}
	for(int i=0;i<k;i++)
	{
		string a,b;
		int dist;
		cin>>a>>b>>dist;
		graph[numCity[a]][numCity[b]]=graph[numCity[b]][numCity[a]]=dist;
	}
	dijkstra(1);								//dijkstra算法找最短路径
	int end=numCity["ROM"];
	printf("%d %d %d %d\n",way[end],Distance[end],htonow[end],htonow[end]/num[end]);
	print(end);
	return 0;
}