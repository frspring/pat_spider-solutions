
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct student
{
	char name[11];
	char ID[11];
	int score;
};
bool cmp(student a,student b)
{
	return a.score>b.score;
}
student s[200];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%s%s%d",&s[i].name,&s[i].ID,&s[i].score);
	}
	sort(s,s+n,cmp);
	int low,high;
	scanf("%d%d",&low,&high);
	int flag=0;
	for (int i=0;i<n;i++)
	{
		if(s[i].score>=low&&s[i].score<=high)
		{
			printf("%s %s\n",s[i].name,s[i].ID);
			flag = 1;
		}
	}
	if(flag==0)
		printf("NONE");
	return 0;
}