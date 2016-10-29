
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

int s;
vector<int> node[105];
int weight[105]={0};
vector<int> sav;
vector<vector<int>> result;
bool cmp(const vector<int>& a,const vector<int>& b)
{
	auto i=a.begin(),j=b.begin();
	while(i!=a.end()&&j!=b.end())
	{
		if((*i)>(*j))
			return true;
		i++,j++;
	}
	return false;
}
void DFS(int root,int sum)
{
	sav.push_back(weight[root]);
	sum+=weight[root];
	if(sum==s&&node[root].empty())
		result.push_back(sav);
	else if(sum>s)
		;
	else
	{
		for(auto i=node[root].begin();i!=node[root].end();i++)
		{
			DFS(*i,sum);
		}
	}
	sav.pop_back();
	return ;
}
int main()
{
	int n,m;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}
	int k;
	int temp;
	int id;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&temp);
			node[id].push_back(temp);
		}
	}
	DFS(0,0);
	sort(result.begin(),result.end());
	for(auto i=result.end()-1;;i--)
	{
		auto j=i->begin();
		printf("%d",*j);
		j++;
		for(;j!=i->end();j++)
		{
			printf(" %d",*j);
		}
		printf("\n");
		if(i==result.begin())
			break;
	}
	return 0;
}