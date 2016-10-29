
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int prime[200002]={0}; 
bool isSieved[200002]={true,true,false};
int main()
{
	int m,end;
	scanf("%d%d",&m,&end);
	int n=200000;
	int cnt=0;
	int temp=2;
	while(1)
	{
		prime[cnt]=temp;
		cnt++;
		for(int i=temp;i<=n;i+=temp)
		{
			isSieved[i]=true;
		}
		int j=temp;
		for(j;j<=n;j++)
		{
			if(!isSieved[j])
			{
				temp=j;
				break;
			}
		}
		if(j==n+1)
			break;
	}
	int flag=1;
	for(int i=m-1;i<end;i++)
	{
		printf("%d",prime[i]);
		if((i-m+1)%10==9)
			printf("\n");
		else if(i!=end-1)
			printf(" ");
	}
	return 0;
}