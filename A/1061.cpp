
#include <stdio.h>

const char week[7][5] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

int main()
{
	char id[4][70] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		scanf("%s", id[i]);
	}
	int i = 0;
	int cnt = 0;
	int h = 0;
	while (id[0][i] != 0 && id[1][i] != 0)
	{
		if (id[0][i] == id[1][i] && cnt == 0 && id[0][i] <= 'G'&&id[0][i] >= 'A')
		{
			printf("%s ", week[id[0][i] - 'A']);
			i++;
			break;
		}
		i++;
	}
	while (id[0][i] != 0 && id[1][i] != 0)
	{
		if (id[0][i] == id[1][i] && ((id[0][i] <= 'N'&&id[0][i] >= 'A') || (id[0][i] <= '9'&&id[0][i] >= '0')))
		{
			if (id[0][i] >= '0'&&id[0][i] <= '9')
				h = id[0][i] - '0';
			else
			{
				h = 10 + (id[0][i] - 'A');
			}
			printf("%02d:", h);
			break;
		}
		i++;
	}
	i = 0;
	while (id[2][i]!=0&&id[3][i]!=0)
	{
		if (id[2][i] == id[3][i] && ((id[2][i] >= 'A'&&id[2][i]<='Z')||(id[2][i]>='a'&&id[2][i] <= 'z')))
		{
			printf("%02d", i%60);
			break;
		}
		i++;
	}
	return 0;
}