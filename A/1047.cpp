
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int getId(char* name)
{
	int id=0;
	for(int i=0;i<3;i++)
	{
		id*=26;
		id+=name[i]-'A';
	}
	id*=10;
	id+=name[3]-'0';
	return id;
}
char str[5]={0};
char* idToStr(int id)
{
	str[3]=id%10+'0';
	id/=10;
	for(int i=2;i>=0;i--)
	{
		str[i]=id%26+'A';
		id/=26;
	}
	return str;
}
vector<int> course[2505];
int cNum[2505];
char name[40005][5];
bool cmp(int a,int b)
{
	return strcmp(name[a],name[b])<0;
}
int main()
{
	int n,k;
	char tempstr[5];
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int c,temp;
		scanf("%s%d",name[i],&c);
		for(int j=0;j<c;j++)
		{
			scanf("%d",&temp);
			course[temp].push_back(i);
		}
	}
	for(int i=1;i<=k;i++)
	{
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin(),course[i].end(),cmp);
		for(auto j=course[i].begin();j!=course[i].end();j++)
		{
			printf("%s\n",name[*j]);
		}
	}
	return 0;
}