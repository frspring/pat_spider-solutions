
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	int temp,t;
	scanf("%d", &n);
	int school[100002] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &temp,&t);
		school[temp] += t;
	}
	temp = 0, t = -1;
	for (int i = 0; i < n+1; i++)
	{
		if (t < school[i])
		{
			t = school[i];
			temp = i;
		}
	}
	printf("%d %d", temp, t);

}