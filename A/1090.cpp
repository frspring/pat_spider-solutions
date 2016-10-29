
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
	int root;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		if(temp>=0)
		{
			node[temp].push_back(i);
		}
		else
		{
			root=i;
		}
	}
	queue<int> qe;
	qe.push(root);
	price[root]=begin;
	double pmax=0;
	while(!qe.empty())
	{
		int top=qe.front();
		qe.pop();
		pmax=max(pmax,price[top]);
		for(auto i=node[top].begin();i!=node[top].end();i++)
		{
			price[*i]=price[top]*p/100.0+price[top];
			qe.push(*i);
		}
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(price[i]==pmax)
			cnt++;
	}
	printf("%.2f %d",pmax,cnt);
	return 0;
}