
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;

struct inout
{
	char id[20];
	int inTime;
	int outTime;
	void operator=(inout b)
	{
		sprintf(id, "%s", b.id);
		inTime = b.inTime;
		outTime = b.outTime;
	}
};

int main()
{
	int n;
	inout first, last, temp;
	int h, m, s;
	scanf("%d", &n);
	first.inTime = -1;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp.id);
		scanf("%d:%d:%d", &h, &m, &s);
		temp.inTime = h * 10000 + m * 100 + s;
		scanf("%d:%d:%d", &h, &m, &s);
		temp.outTime = h * 10000 + m * 100 + s;
		if (first.inTime == -1)
		{
			first = temp;
			last = temp;
		}
		if(first.inTime>temp.inTime)
		{
			first = temp;
		}
		if (last.outTime < temp.outTime)
			last = temp;
	}
	printf("%s %s", first.id, last.id);

}