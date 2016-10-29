
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int squ[100003];
long long p;
//////////////////////////////
int findPersQu(int m,int n)
{
	int eleNum=n-m;
	int left,right;
	left = m;
	right = n-1;
	int mid=(left+right)/2;

	if(squ[right]<=squ[m]*p)
		return eleNum;
	while(left<=right)
	{
		if(squ[mid]<=squ[m]*p&&squ[mid+1]<=squ[m]*p)
		{
			left = mid+1;
			mid=(left+right)/2;
		}
		else if(squ[mid]<=squ[m]*p&&squ[mid+1]>squ[m]*p)
			break;
		else if(squ[mid]>squ[m]*p)
		{
			right =mid-1;
			mid = (right+left)/2;
		}
	}
	eleNum=mid-m+1;
	return eleNum;
}
int main()
{
	int n;
	int max = 0;
	scanf("%d%lld",&n,&p);
	for(int i=0;i<n;i++)
	{
		scanf("%d",squ+i);
	}
	sort(squ,squ+n);
	int temp;
	for(int i=0;i<n;i++)
	{
		if(max<(temp=findPersQu(i,n)))
			max=temp;
	}
	printf("%d",max);
	return 0;
}