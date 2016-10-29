
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
struct mooncake
{
	double inventory;
	double price;
	double sum;
};
mooncake mc[2000];
bool cmp(mooncake a,mooncake b)
{
	return a.price>b.price;
}
int main()
{
	int n;
	double d;
	scanf("%d%lf",&n,&d);
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&mc[i].inventory);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lf",&mc[i].sum);
		mc[i].price=mc[i].sum/mc[i].inventory;
	}
	sort(mc,mc+n,cmp);
	double profit=0;
	int i=0;
	while(d>0)
	{
		if(d>mc[i].inventory-(1e-8))
		{
			d-=mc[i].inventory;
			profit+=mc[i].sum;
		}
		else
		{
			profit+=d*mc[i].price;
			d=-1;
		}
		i++;
		if(i>=n)
			break;
	}
	printf("%.2f",profit);
    return 0;
}