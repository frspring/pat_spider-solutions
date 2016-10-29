
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;


struct person
{
	char name[10];
	int date;
	void operator=(person b)
	{
		sprintf(name, "%s", b.name);
		date = b.date;
	}
};
int main()
{
	int n;
	scanf("%d", &n);
	person maxs, mins , temp;
	int y, m, d, time=0;
	mins.date = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%s%d/%d/%d", &temp.name, &y, &m, &d);
		temp.date = y * 10000 + m * 100 + d;
		if (temp.date > 18140905 && temp.date < 20140907)
		{
			time++;
			if (mins.date == 0)
			{
				mins = temp;
				maxs = temp;
			}
			if (temp.date > mins.date)
				mins = temp;
			if (temp.date < maxs.date)
				maxs = temp;
		}
	}
	if (time == 0)
		printf("0");
	else
		printf("%d %s %s", time, maxs.name, mins.name);

}