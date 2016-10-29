


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

int graph[2002][2002]={0};
map<string,int> strtoi;
string itostr[2002];
int point[2002]={0};
bool isv[2002]={false};
int n,k;
int ind=0;

int maxTime=-1;
int maxMember=-1;
int number=0;
int flag=false;
int totalTime=0;
void DFS(int begin)
{
	if(!isv[begin])
		number++;
	isv[begin]=true;
	if(point[begin]>maxTime)
	{
		maxTime=point[begin];
		maxMember=begin;
	}
	if(totalTime>k)
		flag=true;
	for(int i=0;i<ind;i++)
	{
		if(graph[begin][i]>0)
		{
			totalTime+=graph[begin][i];
			graph[begin][i]=graph[i][begin]=0;
			DFS(i);
		}
	}
}
struct gang
{
	string head;
	int num;
	gang(string h,int n)
	{
		head=h;
		num=n;
	}
};
bool cmp(gang a,gang b)
{
	return a.head<b.head;
}
int main()
{
	scanf("%d%d",&n,&k);
	int temp;
	string a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>temp;
		if(strtoi.find(a)==strtoi.end())
		{
			strtoi[a]=ind;
			itostr[ind]=a;
			ind++;
		}
		if(strtoi.find(b)==strtoi.end())
		{
			strtoi[b]=ind;
			itostr[ind]=b;
			ind++;
		}
		graph[strtoi[a]][strtoi[b]]+=temp;
		graph[strtoi[b]][strtoi[a]]+=temp;
		point[strtoi[a]]+=temp;
		point[strtoi[b]]+=temp;
	}

	vector<gang> g;
	for(int i=0;i<ind;i++)
	{
		if(!isv[i])
		{
			DFS(i);
			if(flag&&number>2)
			{
				g.push_back(gang(itostr[maxMember],number));
			}
			totalTime=0;
			maxTime=maxMember=-1;
			flag=false;
			number=0;
		}
	}
	sort(g.begin(),g.end(),cmp);
	printf("%d\n",g.size());
	for(int i=0;i<g.size();i++)
	{
		cout<<g[i].head<<" "<<g[i].num<<endl;
	}
	return 0;
}