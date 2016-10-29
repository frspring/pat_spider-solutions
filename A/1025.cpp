
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct student
{
	long long id;
	int score;
	int location;
	int rank;
	int locrank;
};
bool cmpl(student a,student b)
{
	return a.score>b.score;
}
bool cmp(student a,student b)
{
	if(a.rank<b.rank)
		return true;
	else if(a.rank>b.rank)
		return false;
	else
		return a.id<b.id;
}
student ss[30005];
int main()
{
	int n,m;
	int cnt = 0;
	scanf("%d",&n);	
	for(int i=0;i<n;i++)
	{
		int begin=cnt;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
		{
			scanf("%lld%d",&ss[cnt].id,&ss[cnt].score);
			ss[cnt].location=1+i;
			cnt++;
		}
		sort(ss+begin,ss+cnt,cmpl);
		int acc = 1;
		for(int j = 0,k=1;j<m;j++)
		{
			ss[begin+j].locrank = k;
			if(j<m-1)
			{
				if(ss[begin+j].score!=ss[begin+j+1].score)
				{
						k+=acc;
						acc=1;
				}
				else
					acc++;
			}
		}
	}
	sort(ss,ss+cnt,cmpl);
	int acc = 1;
	for(int j = 0,k=1;j<cnt;j++)
	{
		ss[j].rank = k;
		if(j<cnt-1)
		{
			if(ss[j].score!=ss[j+1].score)
			{
					k+=acc;
					acc=1;
			}
			else
				acc++;
		}
	}
	sort(ss,ss+cnt,cmp);
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++)
		printf("%013lld %d %d %d\n",ss[i].id,ss[i].rank,ss[i].location,ss[i].locrank);

	
	return 0;
}
