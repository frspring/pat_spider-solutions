
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	scanf("%d",&n);
	bool num[2000]={false};
	int record[200]={0};
	int t;
	for(int i=0;i<n;i++)
	{
		scanf("%d",record+i);
		t=record[i];
		while(t!=1)
		{
			if(t&1)
				t=(t*3+1)>>1;
			else
				t>>=1;
			num[t]=true;
		}
	}
	sort(record,record+n,cmp);
	bool firstTime=true;
	for(int i=0;i<n;i++)
	{
		if(!num[record[i]])
		{
			if(firstTime)
				firstTime=false;
			else
				printf(" ");
			printf("%d",record[i]);
		}
	}
	return 0;
}