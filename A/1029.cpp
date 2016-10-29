
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
//////////////////////////////
int squence1[1000003]={0};
int squence2[1000003]={0};
int squ[2000005]={0};
int main()
{
	int n1,n2;
	scanf("%d",&n1);
	for(int i=0;i<n1;i++)
	{
		scanf("%d",squence1+i);
	}
	scanf("%d",&n2);
	for(int i=0;i<n2;i++)
	{
		scanf("%d",squence2+i);
	}
	int i=0,j=0;
	int index;
	for(index=0;i<n1&&j<n2;index++)
	{
		if(squence1[i]<=squence2[j])
		{
			squ[index]=squence1[i];
			i++;
		}
		else
		{
			squ[index]=squence2[j];
			j++;
		}
	}
	while(i<n1)
	{
		squ[index++]=squence1[i++];
	}
	while(j<n2)
	{
		squ[index++]=squence2[j++];
	}
	if((n1+n2)&1)
		printf("%d",squ[(n1+n2)/2]);
	else
		printf("%d",squ[(n1+n2)/2-1]);
	return 0;
}