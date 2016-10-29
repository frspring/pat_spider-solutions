
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	char team[1000][20] = { 0 }, password[1000][20] = { 0 };
	scanf("%d", &n);
	char temp[20];
	int m = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		int len;
		scanf("%s%s", team[cnt], temp);
		len = strlen(temp);
		for (int j = 0; j < len; j++)
		{
			if (flag == 0&&(temp[j]=='1'||temp[j]=='0'||temp[j]=='l'||temp[j]=='O'))
			{
				flag = 1;
				m++;
				cnt++;
			}
			if (temp[j] == '1')
				temp[j] = '@';
			if (temp[j] == '0')
				temp[j] = '%';
			if (temp[j] == 'l')
				temp[j] = 'L';
			if (temp[j] == 'O')
				temp[j] = 'o';
		}
		if(flag == 1)
			strcpy(password[cnt-1], temp);
	}
	if (m > 0)
	{
		printf("%d\n", m);
		for (int i = 0; i < m; i++)
		{
			printf("%s %s\n", team[i], password[i]);
		}
	}
	else
	{
		if (n == 1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified", n);
	}
	return 0;
}