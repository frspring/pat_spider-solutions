
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int num[10002]={0};
int bet[100002]={0};
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&bet[i]);
		num[bet[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		if(num[bet[i]]==1)
		{
			printf("%d",bet[i]);
			return 0;
		}
	}
	printf("None");
	return 0;
}