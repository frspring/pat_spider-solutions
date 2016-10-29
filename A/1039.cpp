
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

struct student
{
	set<int>stmp;
};
int getId(char *name)
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
student st[200000];
int main()
{
	int n,k;
	char tmpStr[8];
	int courseId,tn;

	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&courseId,&tn);
		for(int j=0;j<tn;j++)
		{
			scanf("%s",tmpStr);
			st[getId(tmpStr)].stmp.insert(courseId);
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s",tmpStr);
		int j=getId(tmpStr);
		printf("%s %d",tmpStr,st[j].stmp.size());
		for(auto it=st[j].stmp.begin();it!=st[j].stmp.end();it++)
		{
			printf(" %d",*it);
		}
		printf("\n");
	}
	return 0;
}