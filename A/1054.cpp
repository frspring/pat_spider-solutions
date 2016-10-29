
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
	int n,m;
	map<int,int> mp;
	scanf("%d%d",&n,&m);
	int temp;
	for(int i=0;i<m*n;i++)
	{
		scanf("%d",&temp);
		mp[temp]++;
		if(mp[temp]>m*n/2)
		{
			printf("%d",temp);
			return 0;
		}
	}
	return 0;
}