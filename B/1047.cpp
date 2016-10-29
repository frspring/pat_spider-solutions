
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int main()
{
	int score[10005]={0};
	int n;
	int maxScore=0,bestTeam;
	int teamNum,member,temp;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d-%d %d",&teamNum,&member,&temp);
		score[teamNum] += temp;
		if(score[teamNum]>maxScore)
		{
			maxScore=score[teamNum];
			bestTeam=teamNum;
		}
	}
	printf("%d %d",bestTeam,maxScore);
	return 0;
}