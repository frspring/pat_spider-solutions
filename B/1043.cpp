
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int hashTrans(char c)
{
	if(c>='a'&&c<='z')
		return c-'a'+26;
	if(c>='A'&&c<='Z')
		return c-'A';
	if(c>='0'&&c<='9')
		return c-'0'+52;
	return 64;
}

const char pat[7]="PATest";
int main()
{
	int n;
	char str[100002];
	gets(str);
	n=strlen(str);
	map<char,int> mp;
	for(int i=0;i<n;i++)
	{
		mp[str[i]]++;
	}
	while(n--)
	{
		for(int i=0;i<6;i++)
		if(mp[pat[i]]>0)
		{
			mp[pat[i]]--;
			putchar(pat[i]);
		}
	}
}