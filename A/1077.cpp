
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	scanf("%d\n", &n);
	char str[111][260] = { 0 };
	int minLen = 260;
	int len=0;
	string temp;
	for (int i = 0; i < n; i++)
	{
		getline(cin,temp);
		strcpy(str[i], temp.c_str());
		len = strlen(str[i]);
		if (len == 0)
		{
			printf("nai");
			return 0;
		}
		reverse(str[i], str[i]+len);
		minLen = len < minLen ? len : minLen;
	}
	int flag = 1;
	int no = 0;
	for (int i = 0; i < minLen+2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (str[j][i] != str[0][i]||str[j][i]==0||str[0][i]==0)
			{
				flag = 0;
				no = i;
				goto label;
			}
		}
	}
label:
	if (no == 0)
		printf("nai");
	else
	{
		str[0][no] = 0;
		reverse(str[0], str[0] + no);
		printf("%s",str[0]);
	}
	return 0;
}