
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n;
	map<string,set<int>> titleMap;
	map<string,set<int>> authorMap;
	map<string,set<int>> keywordMap;
	map<string,set<int>> publisherMap;
	set<int> yearMap[4000];
	scanf("%d",&n);
	char temp[100]={0};
	char str[20];
	char* begin;
	int t;
	int yr;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&t);
		gets(temp);
		gets(temp);
		titleMap[temp].insert(t);
		gets(temp);
		authorMap[temp].insert(t);
		gets(temp);
		begin = temp;
		while(1)
		{
			sscanf(begin,"%s",str);
			begin+=strlen(str)+1;
			keywordMap[str].insert(t);
			if(begin>=temp+strlen(temp))
				break;
		}
		gets(temp);
		publisherMap[temp].insert(t);
		scanf("%d",&yr);
		yearMap[yr].insert(t);
	}
	int m;
	scanf("%d",&m);
	int type;
	char query[80];
	for(int i=0;i<m;i++)
	{
		scanf("%d: ",&type);
		gets(query);
		printf("%d: %s\n",type,query);
		switch(type)
		{
		case 1:
			if(titleMap[query].empty())
			{
				printf("Not Found\n");
				break;
			}
			for(auto j=titleMap[query].begin();j!=titleMap[query].end();j++)
			{
				printf("%07d\n",*j);
			}
			break;
		case 2:
			if(authorMap[query].empty())
			{
				printf("Not Found\n");
				break;
			}
			for(auto j=authorMap[query].begin();j!=authorMap[query].end();j++)
			{
				printf("%07d\n",*j);
			}
			break;
		case 3:
			if(keywordMap[query].empty())
			{
				printf("Not Found\n");
				break;
			}
			for(auto j=keywordMap[query].begin();j!=keywordMap[query].end();j++)
			{
				printf("%07d\n",*j);
			}
			break;
		case 4:
			if(publisherMap[query].empty())
			{
				printf("Not Found\n");
				break;
			}
			for(auto j=publisherMap[query].begin();j!=publisherMap[query].end();j++)
			{
				printf("%07d\n",*j);
			}
			break;
		case 5:
			if(yearMap[atoi(query)].empty())
			{
				printf("Not Found\n");
				break;
			}
			for(auto j=yearMap[atoi(query)].begin();j!=yearMap[atoi(query)].end();j++)
			{
				printf("%07d\n",*j);
			}
			break;

		}
	}
	return 0;
}