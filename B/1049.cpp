
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int main()
{
	int n;
	double num[100002];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",num+i);
	}
	double sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=num[i]*(n-i)*(i+1);
		//for(int j=i;j<n;j++)
		//{
		//	sum+=num[j]*(n-j);
		//}
	}
	printf("%.2f",sum);
	return 0;

}