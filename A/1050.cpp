
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
	char s1[10002],s2[10002];
	bool disabled[129]={false};
	gets(s1);
	gets(s2);
	int len1,len2;
	len1 = strlen(s1);
	len2 = strlen(s2);
	for(int i=0;i<len2;i++)
	{
		disabled[s2[i]]=true;
	}
	for(int i=0;i<len1;i++)
	{
		if(disabled[s1[i]])
			continue;
		else
			putchar(s1[i]);
	}
	return 0;
}