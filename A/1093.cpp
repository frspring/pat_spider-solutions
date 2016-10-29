
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
char str[100005];
int P[100005]={0};
int A[100005]={0};
int T[100005]={0};

int main()
{
	int len;
	
	gets(str);
	len=strlen(str);
	for(int i=0;i<len;i++)
	{
		switch(str[i])
		{
		case 'P':
			P[i]++;
			break;
		case 'A':
			A[i]++;
			break;
		case 'T':
			T[i]++;
			break;
		}
	}
	for(int i=1;i<len;i++)
	{
		P[i]+=P[i-1];
		A[i]+=A[i-1];
		T[i]+=T[i-1];
	}
	long long sum=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]=='A')
		{
			sum+=P[i]*(T[len-1]-T[i]);
			sum=sum%1000000007;
		}
	}
	printf("%d",sum);
	return 0;
}