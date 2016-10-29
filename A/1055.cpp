
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
struct person
{
	char name[10];
	int age;
	int netWorth;
};
bool cmp(person a,person b)
{
	if (a.netWorth!=b.netWorth)
	{
		return a.netWorth>b.netWorth;
	}
	else if(a.age!=b.age)
	{
		return a.age<b.age;
	}
	else
		return strcmp(a.name,b.name)<0;
}
person mier[100001];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%s%d%d",&mier[i].name,&mier[i].age,&mier[i].netWorth);
	}
	sort(mier,mier+n,cmp);
	int maxmum,lowerAge,higherAge;
	for (int i=0;i<k;i++)
	{
		int cnt=0;
		scanf("%d%d%d",&maxmum,&lowerAge,&higherAge);
		printf("Case #%d:\n",i+1);
		for (int j=0;j<n&&cnt<maxmum;j++)
		{
			if (mier[j].age>=lowerAge&&mier[j].age<=higherAge)
			{
				cnt++;
				printf("%s %d %d\n",mier[j].name,mier[j].age,mier[j].netWorth);
			}
		}
		if (cnt==0)
		{
			printf("None\n");
		}
	}

	return 0;
}