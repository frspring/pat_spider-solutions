
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int coupons[100002];
int vaule[100002];
int main()
{
	int nc,np;
	scanf("%d",&nc);
	for(int i=0;i<nc;i++)
	{
		scanf("%d",coupons+i);
	}
	scanf("%d",&np);
	for(int i=0;i<np;i++)
	{
		scanf("%d",vaule+i);
	}
	sort(coupons,coupons+nc);
	sort(vaule,vaule+np);
	int sum=0;
	for( int i=0;i<nc&&i<np;i++)
	{
		if(coupons[i]<0&&vaule[i]<0)
			sum+=coupons[i]*vaule[i];
		else
			break;
	}
	for(int i=0;i<nc&&i<np;i++)
	{
		if(coupons[nc-1-i]>0&&vaule[np-1-i]>0)
			sum+=coupons[nc-1-i]*vaule[np-1-i];
		else
			break;
	}
	printf("%d",sum);
	return 0;
}