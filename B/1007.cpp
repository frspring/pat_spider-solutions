
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int prime[100002]={0}; 
bool isSieved[100002]={true,true,false};
int main()
{
	int n;
	scanf("%d",&n);	
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
	int primePair=0;
	for(int i=0;i<cnt;i++)
	{
		if(prime[i+1]-prime[i]==2)
			primePair++;
	}
	printf("%d",primePair);
	return 0;
}