
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int s=0;
int howMuchOne(int num)
{
	int t=0;
	int len=0;
	char str[10];
	if(num<1)
		return 0;
	sprintf(str,"%d",num);	
	len = strlen(str);
	if(str[0]=='1')
		t+=num-pow(10.0,len-1)+1;
	else
		t+=pow(10.0,len-1);
	t+=(str[0]-'0')*howMuchOne(pow(10.0,len-1)-1);
	num=num-pow(10.0,len-1)*(str[0]-'0');
	t+=howMuchOne(num);
	return t;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",howMuchOne(n));
	return 0;
}