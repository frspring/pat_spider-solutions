
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	char a[1003]={0};
	char c[1003]={0};
	int b;
	int r=0;
	scanf("%s%d",a,&b);
	int len=strlen(a);
	int temp=0;
	for(int i=0;i<len;i++)
	{
		temp=10*r+a[i]-'0';
		r=temp%b;
		c[i]=temp/b+'0';
	}
	int cnt=0;
	while(c[cnt]=='0')
		cnt++;
	if(cnt>=strlen(c))
	{
		printf("0 %d",r);
		return 0;
	}
	printf("%s %d",c+cnt,r);
	return 0;
}