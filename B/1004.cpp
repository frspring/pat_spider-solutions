
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;


struct student
{
	char name[20];
	char num[20];
	int score;
	void operator=(student b)
	{
		sprintf(name, "%s", b.name);
		sprintf(num, "%s", b.num);
		score = b.score;
	}
};
int main()
{
	int n;
	scanf("%d", &n);
	student maxs, mins, temp;
	scanf("%s%s%d", &temp.name, &temp.num, &temp.score);
	maxs = temp;
	mins = temp;
	for (int i = 1; i < n; i++)
	{
		scanf("%s%s%d", &temp.name, &temp.num, &temp.score);
		if (temp.score > maxs.score)
			maxs = temp;
		if (temp.score < mins.score)
			mins = temp;
	}
	printf("%s %s\n", maxs.name, maxs.num);
	printf("%s %s", mins.name, mins.num);

}