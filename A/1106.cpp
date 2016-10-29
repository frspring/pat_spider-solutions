
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
	int temp;
	int k;
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
	}
	queue<int> qe;
	qe.push(0);
	price[0]=begin;
	double pmin=1e10;
	while(!qe.empty())
	{
		int top=qe.front();
		qe.pop();
		if(node[top].empty())
			pmin=min(pmin,price[top]);
		for(auto i=node[top].begin();i!=node[top].end();i++)
		{
			price[*i]=price[top]*p/100.0+price[top];
			qe.push(*i);
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(price[i]==pmin&&node[i].empty())
			cnt++;
	}
	printf("%.4f %d",pmin,cnt);
	return 0;
}