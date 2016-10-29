
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
	int n,m;
	scanf("%d%d",&n,&m);
	int faceVaule[100005]={0};
	int coin[2000]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%d",faceVaule+i);
		coin[faceVaule[i]]++;
	}
	sort(faceVaule,faceVaule+n);
	for(int i=0;i<n;i++)
	{
		if(m==2*faceVaule[i])
		{
			if(coin[faceVaule[i]]>1)
			{
				printf("%d %d",faceVaule[i],faceVaule[i]);
				return 0;
			}
		}
		else if(faceVaule[i]<m)
		{
			if(coin[m-faceVaule[i]])
			{
				printf("%d %d",faceVaule[i],m-faceVaule[i]);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0;
}