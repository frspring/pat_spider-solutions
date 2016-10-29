
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct student
{
	int id;
	char name[10];
	int score;
};
bool cmp1(student a,student b)
{
	return a.id<b.id;
}
bool cmp3(student a,student b)
{
	if(a.score!=b.score)
		return a.score<b.score;
	else
		return a.id<b.id;
}
bool cmp2(student a,student b)
{
	if(strcmp(a.name,b.name)!=0)
		return strcmp(a.name,b.name)<0;
	else
		return a.id<b.id;

}
student s[100001];
int main()
{
	int n;
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d%s%d",&s[i].id,&s[i].name,&s[i].score);
	}
	switch(m)
	{
	case 1:
		sort(s,s+n,cmp1);
		break;
	case 2:
		sort(s,s+n,cmp2);
		break;
	case 3:
		sort(s,s+n,cmp3);
		break;
	default:
		break;
	}
	for (int i=0;i<n;i++)
	{
		printf("%06d %s %d\n",s[i].id,s[i].name,s[i].score);
	}
	return 0;
}