
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
struct stop
{
	double distance;
	double price;
};
bool cmp(stop a,stop b)
{
	if(a.distance!=b.distance)
		return a.distance<b.distance;
	else
		return a.price<b.price;
}
int main()
{
	double cm,distan,davg;
	int n;
	scanf("%lf%lf%lf%d",&cm,&distan,&davg,&n);
	stop sp[550];
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf",&sp[i].price,&sp[i].distance);
	}
	double farest=0;
	double payed = 0;
	sort(sp,sp+n,cmp);
	double temprice=99999999999;
	double t=0;
	int begin=-1;
	sp[n].distance=distan;
	sp[n].price=0;
    while(t<distan)
	{
		int flag = 0;
		double min=99999999999;
		stop temp;
		for(int i=begin+1;sp[i].distance<=farest&&i<=n;i++)
		{
			if(sp[i].price<min)
				min=sp[i].price;
			if(sp[i].price<=temprice)
			{
				flag=1;
				payed+=(sp[i].distance-t)*temprice/davg;
				t=sp[i].distance;
				temprice=sp[i].price;
				temp=sp[i];
				while(fabs(sp[i].distance-sp[i+1].distance)<1e-7)
					i++;
				begin=i;
				farest=temp.distance+cm*davg;
				goto label;
			}
		}
		for(int i=begin+1;sp[i].distance<=farest&&i<=n;i++)
		{
			if(fabs(min-sp[i].price)<1e-7)
			{
				flag=1;
				temp=sp[i];
				payed+=(farest-t)*temprice/davg;
				t=farest;
				temprice=sp[i].price;
				while(fabs(sp[i].distance-sp[i+1].distance)<1e-7)
					i++;
				begin=i;
				farest=temp.distance+cm*davg;
				goto label;
			}
		}
label:
		if(flag==0)
		{
			printf("The maximum travel distance = %.2f",farest);
			return 0;
		}
	}

	printf("%.2f",payed);
	return 0;
}