
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int squ[100002]={0};
int numInLine[100002]={0};
int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0;
	int temp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",squ+i);
		numInLine[squ[i]]=i;
	}
	int k = 1;
	while(1)
	{
		if(squ[0]==0)
		{
			int flag=true;
			for(int i=k;i<n;i++)
			{
				if(squ[i]!=i)
				{
					if(i>k)
						k=i;
					int a=squ[i];
					swap(squ[i],squ[numInLine[0]]);
					swap(numInLine[0],numInLine[a]);
					cnt++;
					flag = false;
					break;
				}
			}
			if(flag)
			{
				printf("%d",cnt);
				return 0;
			}
		}
		else
		{
			//numInLine[0]:0所在位置，也即要与0交换的数字
			//squ[numInLine[0]]：0；
			//numInLine[numInLine[0]]：要与0交换的数字所在的位置
			//squ[numInLine[numInLine[0]]]：要与0交换的数字
			cnt++;
			swap(squ[numInLine[0]],squ[numInLine[numInLine[0]]]);
			swap(numInLine[0],numInLine[numInLine[0]]);
		}
	}
	printf("%d",cnt);
	return 0;
}