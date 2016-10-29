
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

vector<int> node[105];
int numInDepth[105]={0};
int ans=0,inx=1;
void DFS(int root,int depth)
{
	numInDepth[depth]++;
	if(numInDepth[depth]>ans)
	{
		ans=numInDepth[depth];
		inx=depth;
	}
	for(auto i=node[root].begin();i!=node[root].end();i++)
	{
		DFS(*i,depth+1);
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
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
	DFS(1,1);
	printf("%d %d",ans,inx);
	return 0;
}