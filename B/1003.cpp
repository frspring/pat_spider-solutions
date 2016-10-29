
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int main()
{
	int n;
	char str[102];
	scanf("%d",&n);
	int p,t;
	for(int i=0;i<n;i++)
	{
		int pn=0,tn=0,isPat=1;
		scanf("%s",str);
		for(int j=0;str[j]!=0;j++)
		{
			if(str[j]=='P')
			{
				p=j;
				pn++;
			}
			else if(str[j]=='T')
			{
				t=j;
				tn++;
			}
			else if(str[j]!='A')
				isPat=0;
		}
		if(isPat==0)
		{
			printf("NO");
		}
		else if(pn!=1||tn!=1)
		{
			printf("NO");
		}
		else if(t-p<=1)
		{
			printf("NO");
		}
		else if(t-p==2)
			printf("YES");
		else if(p==0)
			printf("YES");
		else if((strlen(str)-t-1)/p>=(t-p-1))
			printf("YES");
		else 
			printf("NO");
		putchar('\n');
	}
	return 0;

}