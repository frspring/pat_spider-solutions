
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

vector<int> node[100005];
double price[100005]={0};

int main()
{
	int n;
	double begin;
	double p;
	scanf("%d%lf%lf",&n,&begin,&p);
	price[0]=begin;
	int k;
	int temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&k);
		if(k!=0)
		{
			for(int j=0;j<k;j++)
			{
				scanf("%d",&temp);
				node[i].push_back(temp);
			}
		}
		else
		{
			scanf("%d",&temp);
			node[i].push_back(-1*temp);	
		}
	}
	queue<int> qe;
	qe.push(0);
	double sum=0;
	while(!qe.empty())
	{
		int top=qe.front();
		qe.pop();
		if(node[top].back()>0)
		{
			for(auto i=node[top].begin();i!=node[top].end();i++)
			{
				price[*i]=price[top]*p/100.0+price[top];	
				qe.push(*i);
			}
		}
		else
		{
			sum+=price[top]*(-1.0)*node[top].back();
		}
	}
	printf("%.1f",sum);
	return 0;
}