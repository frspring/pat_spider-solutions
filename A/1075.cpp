
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct student
{
	int score[5];
	int sum;
	bool vaild;
	int solved;
	int id;
	student()
	{
		for (int i=0;i<5;i++)
		{
			score[i]=-1;
		}
		solved=0;
		sum=0;
		vaild = false;
	}
};
bool cmp(student a,student b)
{
	if (a.sum!=b.sum)
	{
		return a.sum>b.sum;
	}
	else if(a.solved!=b.solved)
		return a.solved>b.solved;
	else
		return a.id<b.id;
}
student s[100002];

int main()
{
	int prosc[5]={0};
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	for (int i=0;i<k;i++)
	{
		scanf("%d",prosc+i);
	}
	int temp,pn,sn;
	for (int i=0;i<m;i++)
	{
		scanf("%d%d%d",&temp,&pn,&sn);
		if(sn==-1&&s[temp-1].score[pn-1]==-1)
			s[temp-1].score[pn-1] = 0;
		if(s[temp-1].score[pn-1]<sn)
		{
			if (sn==prosc[pn-1])
			{
				s[temp-1].solved++;
			}
			s[temp-1].score[pn-1] = sn;
			s[temp-1].vaild = true;
		}
		s[temp-1].id = temp;
	}
	for (int i=0;i<n;i++)
	{
		if(s[i].vaild)
		{
			for (int j=0;j<k;j++)
			{
				s[i].sum+=(s[i].score[j]==-1)?0:s[i].score[j];
			}
		}
		else
			s[i].sum=-1;
	}
	sort(s,s+n,cmp);
	printf("1 %05d %d",s[0].id,s[0].sum);
	for (int j=0;j<k;j++)
	{
		if(s[0].score[j]!=-1)
			printf(" %d",s[0].score[j]);
		else
			printf(" -");
	}
	printf("\n");
	int rank = 1;
	for (int i=1;i<n;i++)
	{
		if(s[i].vaild)
		{
			if(s[i].sum!=s[i-1].sum)
				rank = i+1;
			printf("%d %05d %d",rank,s[i].id,s[i].sum);
			for (int j=0;j<k;j++)
			{
				if(s[i].score[j]!=-1)
					printf(" %d",s[i].score[j]);
				else
					printf(" -");
			}
			printf("\n");
		}
	}
	return 0;
}