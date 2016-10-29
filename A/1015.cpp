
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int prime[110002]={0}; 
bool isSieved[110002]={true,true,false};
int main()
{
	int m,end;
	int n=110000;
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
	int num,d;
	while(1)
	{
		scanf("%d",&num);
		if(num<0)
			break;
		scanf("%d",&d);
		int f=0;
		for(int i=0;i<cnt;i++)
		{
			if(prime[i]==num)
			{
				f=1;
				break;
			}
		}
		int revesedNum=0;
		while(num!=0)
		{
			revesedNum*=d;
			revesedNum+=num%d;
			num/=d;
		}

		for(int i=0;i<cnt;i++)
		{
			if(prime[i]==revesedNum&&f)
			{
				printf("Yes\n");
				f=2;
				break;
			}
		}
		if(f<2)
			printf("No\n");
	}
	return 0;
}