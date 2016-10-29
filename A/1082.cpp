
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const char str[10][9] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
const char mun[7][8] = { ""," Shi"," Bai"," Qian"," Wan"," Yi" };
int main()
{
	char num[12] = { 0 };
	char t[12] = { 0 };
	scanf("%s", num);
	if (num[0] == '0')
	{
		printf("ling");
		return 0;
	}
	if (num[0] == '-')
	{
		printf("Fu ");
		strcpy(num , num+1);
	}
	int length = strlen(num);
	char out[20][20] = { 0 };
	int flag = 0;
	int index = 0;
	for (int i = 0; i < length; i++)
	{
		int temp = num[i] - '0';
		if (temp == 0)
		{
			if (length -1 - i == 4&&flag>4&&flag<9)
				sprintf(out[i], "Wan");
			else if (length - 1 - i == 8)
				sprintf(out[i], "Yi");
			else if (num[i+1]!='0'&&num[i+1]!=0)
			{
				sprintf(out[i], "ling");
				flag = 0;
				index = i;
			}
			continue;
		}
		if(length - i -1==4)
			sprintf(out[i], "%s%s Wan", str[temp], mun[(length-i-1) % 4]);
		else if(length - i-1==8)
			sprintf(out[i], "%s%s Yi", str[temp], mun[(length - i-1) % 4]);
		else sprintf(out[i], "%s%s", str[temp], mun[(length - i-1) %4]);
		flag = length - i;
	}
	if (flag == 0)
		out[index][0] = 0;
	printf("%s", out[0]);
	for (int i =1; i<length; i++)
	{
		if(out[i][0]!=0)
			printf(" %s", out[i]);
	}
	return 0;
}