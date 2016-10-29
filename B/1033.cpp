
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
		return c-'a';
	if(c>='A'&&c<='Z')
		return c-'A';
	if(c>='0'&&c<='9')
		return c-'0'+26;
	switch(c)
	{
	case '_':
		return 36;
	case ',':
		return 37;
	case '.':
		return 38;
	case '-':
		return 39;
	case '+':
		return 40;
	default:
		return 41;
	}
}
int main()
{
	char str[50];
	bool disabled[60]={false};
	gets(str);
	for(int i=0;str[i]!=0;i++)
		disabled[hashTrans(str[i])]=true;
	char t[100001];
	gets(t);
	int len = strlen(t);
	for(int i=0;i<len;i++)
	{
		if(t[i]<='Z'&&t[i]>='A'&&disabled[40])
			continue;
		if(disabled[hashTrans(t[i])])
			continue;
		putchar(t[i]);
	}
    printf("\n");
}