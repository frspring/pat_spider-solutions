
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
struct car
{
	char num[10];
	int in;
	int out;
	bool vaild;
	int time;
	car(){vaild=false;in=-1;out=-1;}
};
struct record
{
	char num[10];
	int time;
	bool isIn;
};
record rd[10010];
car cars[10010];
int carInSec[86405]={0};
int carNum[86405]={0};
bool cmp(record a,record b)
{
	if(strcmp(a.num,b.num)!=0)
		return strcmp(a.num,b.num)<0;
	return a.time<b.time;
}
int main()
{
	int n,k;
	char dir[5];
	int h,m,s;
	int cnt =0;
	int max=-1;
	scanf("%d%d",&n,&k);
	map<string,int> mp;
	for(int i=0;i<n;i++)
	{
		scanf("%s %d:%d:%d %s",rd[i].num,&h,&m,&s,dir);
		rd[i].isIn = strcmp(dir,"in")==0;
		rd[i].time = h*3600+m*60+s;
	}
	sort(rd,rd+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(!cars[cnt].vaild)
		{
			if(i>0&&rd[i].time==rd[i-1].time&&strcmp(rd[i].num,rd[i-1].num)==0)
				continue;
			if(rd[i].isIn)
				cars[cnt].in=rd[i].time;
			else if(i>0&&rd[i-1].isIn&&strcmp(rd[i].num,rd[i-1].num)==0)
			{
				cars[cnt].out=rd[i].time;
				cars[cnt].vaild=true;
				cars[cnt].time=cars[cnt].out-cars[cnt].in;
				strcpy(cars[cnt].num,rd[i].num);
				mp[cars[cnt].num]+=cars[cnt].time;
				max = max<mp[cars[cnt].num]?mp[cars[cnt].num]:max;
				cnt++;
			}
		}
	}
	for(int i=0;i<cnt;i++)
	{
		if(cars[i].vaild)
		{
			carInSec[cars[i].in]++;
			carInSec[cars[i].out]--;
		}
	}
	carNum[0]=carInSec[0];
	for(int i=1;i<86400;i++)
	{
		carNum[i]=carNum[i-1]+carInSec[i];
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d:%d:%d",&h,&m,&s);
		printf("%d\n",carNum[h*3600+m*60+s]);
	}
	for(auto i=mp.begin();i!=mp.end();i++)
	{
		if(i->second==max)
			printf("%s ",i->first.c_str());
	}
	printf("%02d:%02d:%02d",max/3600,(max%3600)/60,max%60);
	return 0;
}