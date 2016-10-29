
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;

struct app
{
	int ge;
	int gi;
	int choice[6];
	double final;
	int id;
	int admit;
};
bool cmp(app a,app b)
{
	if (a.final!=b.final)
	{
		return a.final>b.final;
	}
	else 
		return a.ge>b.ge;
}
bool cmp1(app a,app b)
{
	return a.id<b.id;
}
app student[40001];
int main()
{
	int quota[101]={0};
	int recived[101]={0};
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<m;i++)
	{
		scanf("%d",quota+i);
	}
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&student[i].ge,&student[i].gi);
		student[i].final=(student[i].ge + student[i].gi)/2.0;
		student[i].id = i;
		student[i].admit=999;
		for (int j=0;j<k;j++)
		{
			scanf("%d",&student[i].choice[j]);
		}
	}
	sort(student,student+n,cmp);
	for (int i=0;i<n;i++)
	{
		int offset = 0;
		for (int j=0;j<k;j++)
		{
			if(recived[student[i].choice[j]]<quota[student[i].choice[j]])
			{
				recived[student[i].choice[j]]++;
				student[i].admit=student[i].choice[j];
				break;
			}
			if(student[i].ge==student[i-1].ge&&student[i].gi==student[i-1].gi)
			{
				student[i].admit=student[i-1].admit;
				break;
			}
		}
	}
	int temp;
	sort(student,student+n,cmp1);
	for (int i=0;i<m;i++)
	{
			int flag1=1;

		for(int j=0;j<n;j++)
		{
			if(student[j].admit==i)
			{
				if(flag1)
				{
					flag1 = 0;
					printf("%d",student[j].id);
				}
				else
					printf(" %d",student[j].id);
			}
		}
		printf("\n");
	}
	return 0;
}