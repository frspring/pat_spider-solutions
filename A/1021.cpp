
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <set>
using namespace std;

vector<int> graph[10005];
bool isv[10005]={0};
set<int> dpest;
int maxd=0;
void DFS(int begin,int depth)
{
	isv[begin]=true;
	if(depth>maxd&&graph[begin].size()==1)
	{
		dpest.clear();
		maxd=depth;
		dpest.insert(begin);
	}
	else if(depth == maxd&&graph[begin].size()==1)
	{
		dpest.insert(begin);
	}
	for(int i=0;i<graph[begin].size();i++)
	{
		int next=graph[begin][i];
		if(!isv[next])
		{
			DFS(next,depth+1);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!isv[i])
		{
			cnt++;
			DFS(i,0);
		}
	}
	if(cnt>1)
	{
		printf("Error: %d components",cnt);
		return 0;
	}
	set<int> other=dpest;
	fill(isv+1,isv+n+1,false);
	auto i=other.begin();
	DFS(*i,0);
	other.insert(dpest.begin(),dpest.end());
	for(auto i=other.begin();i!=other.end();i++)
		printf("%d\n",*i);
	return 0;
}