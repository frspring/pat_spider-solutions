
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
//////////////////////////////

int acc[100003]={0};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	acc[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",acc+i);
		acc[i]+=acc[i-1];
	}
	int temp;
	int min=9999999;
	for(int i=0;i<=n;i++)
	{
		int left=i,right=n;
		int mid=(left+right)/2;
		while(left<=right)
		{
			temp = acc[mid]-acc[i]; 
			if(temp<m)
			{
				left=mid+1;
				mid=(left+right)/2;
			}
			else if(temp==m)
			{
				min=-1;
				printf("%d-%d\n",i+1,mid);
				break;
			}
			else if(temp>m)
			{
				if(temp<min)
					min=temp;
				right = mid-1;
				mid=(left+right)/2;
			}
		}
	}
	if(min==-1)
		return 0;
	for(int i=0;i<=n;i++)
	{
		int left=i,right=n;
		int mid=(left+right)/2;
		while(left<=right)
		{
			temp = acc[mid]-acc[i]; 
			if(temp<m)
			{
				left=mid+1;
				mid=(left+right)/2;
			}
			else if(temp>m)
			{
				if(temp==min)
				{
					printf("%d-%d\n",i+1,mid);
					break;
				}
				right = mid-1;
				mid=(left+right)/2;
			}
		}
	}
	return 0;
}