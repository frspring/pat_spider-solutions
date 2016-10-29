
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int main()
{
	map<string,int> pl;
	string str;
	getline(cin,str);
	int max=0;
	for(int i=0;i<str.length();i++)
	{
		string word;
		while(!isalnum(str[i])&&i<str.length())
		{
			i++;
			if(i>=str.length())
				goto label;
		}
		while(isalnum(str[i])&&i<str.length())
		{
			word+=tolower(str[i]);
			i++;
			if(i>=str.length())
				goto label;
		}
label:
		if(word.length()!=0)
		{
			pl[word]++;
			if(pl[word]>max)
				max=pl[word];
		}
	}
	for(auto i=pl.begin();i!=pl.end();i++)
	{
		if(max==i->second)
		{
			printf("%s ",i->first.c_str());
			break;
		}
	}
	printf("%d",max);
	return 0;
}