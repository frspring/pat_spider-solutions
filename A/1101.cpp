
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int leftNum[100005];
int rightNum[100005];
int num[100005];
int main()
{
	int n;
	vector<int> vt;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",num+i);
	}
	int max=0;
	int min=1000000002;
	for(int i=0;i<n;i++)
	{
		if(num[i]>max)
			max=num[i];
		leftNum[i]=max;
		if(num[n-i-1]<min)
			min=num[n-i-1];
		rightNum[n-i-1]=min;
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(leftNum[i]<=num[i]&&rightNum[i]>=num[i])
		{
			cnt++;
			vt.push_back(num[i]);
		}
	}
	printf("%d\n",cnt);
	if(cnt==0)
		printf("\n");
	auto itr=vt.begin();
	for(int i=0;i<cnt;i++)
	{
		printf("%d",*itr);
		itr++;
		if(i!=cnt-1)
		{
			printf(" ");
		}
	}
	return 0;
}