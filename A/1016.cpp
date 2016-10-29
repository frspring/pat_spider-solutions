
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;


struct order
{
	char name[21];
	int time;
	int state;//0 is offline
};
bool cmp(order a,order b)
{
	if(strcmp(a.name,b.name)!=0)
		return strcmp(a.name,b.name)<0;
	else if(a.time!=b.time)
		return a.time<b.time;
	else return true;
}
int chargeRate[25]={0};
order temp[1000];
int main()
{
	char t[10];
	for (int i=0;i<24;i++)
	{
		scanf("%d",&chargeRate[i]);
	}
	int n;
	int mon,day,h,m;
	char tst[10];
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%s %d:%d:%d:%d %s",temp[i].name,&mon,&day,&h,&m,tst);
		temp[i].time=mon*24*60*31+day*24*60+h*60+m;
		temp[i].state=strcmp(tst,"off-line")!=0;
	}



	sort(temp,temp+n,cmp);
	int flag = 1;
	double money=0;
	double teMoney;
	int btw;
	for (int i=1;i<n;i++)
	{
		if(strcmp(temp[i].name,temp[i-1].name)==0)
		{
			if(temp[i].state==0&&temp[i-1].state==1)
			{
				teMoney = 0;
				if(flag)
				{
					money=0;
					flag=0;
					printf("%s %02d\n",temp[i].name,temp[i].time/(31*24*60));
				}
				printf("%02d:%02d:%02d ",(temp[i-1].time/(24*60))%31,temp[i-1].time/60%24,temp[i-1].time%60);
				printf("%02d:%02d:%02d ",(temp[i].time/(24*60))%31,temp[i].time/60%24,temp[i].time%60);
				btw = temp[i].time-temp[i-1].time;
				printf("%d ",btw);
				for (int j=temp[i-1].time;j<temp[i].time;j++)
				{
					teMoney+=chargeRate[j/60%24];
				}
				printf("$%.2f\n",teMoney/100.0);
				money+=teMoney/100.0;
			}
			if(((i<n-1&&strcmp(temp[i].name,temp[i+1].name)!=0)||i>=n-1)&&flag==0)
				printf("Total amount: $%.2f\n",money);
		}
		else
			flag = 1;

	}
	return 0;
}