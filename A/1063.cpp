
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int main()
{
	set<int> numSet[60];
	int n;
	int temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&temp);
			numSet[i+1].insert(temp);
		}
	}
	int k;
	scanf("%d",&k);
	int a,b;
	set<int> st;
	double f;
	for(int i=0;i<k;i++)
	{
		int same=0;
		scanf("%d%d",&a,&b);
		int sum=numSet[a].size()+numSet[b].size();		
		for(auto i=numSet[a].begin();i!=numSet[a].end();i++)
		{
			if(numSet[b].find(*i)!=numSet[b].end())
			{
				sum--;
				same++;
			}
		}
		printf("%.1f%%\n",same*1.0/sum*100.0);
	}
	return 0;
}