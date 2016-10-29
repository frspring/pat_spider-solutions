
#include<stdio.h>
#include<stdint.h>
#include<algorithm>
#include<math.h>
using namespace std;
//2*n*n-1=N
int main()
{
	int n;
	char c;
	char map[200][200] = { 0 };
	scanf("%d %c", &n, &c);
	int sline = 0;
	sline = (int)sqrt((n + 1) / 2.0);
	int line = 0;
	int extra = 0;
	extra = n - (2 * sline*sline - 1);
	int offset;
	for (int i = 0; i < sline; i++)
	{
		for (int j = sline-i; j < sline+i+1; j++)
		{
			map[sline + i-1][j-1] = c;
			map[sline - i-1][j-1] = c;
		}
	}
	for (int i = 0; i < 2*sline-1; i++)
	{
		for (int j = 0; j < 2*sline-1; j++)
		{
			if (map[i][j] == 0 && j >= sline)
			{
				continue;
			}
			if (map[i][j] == 0)
				putchar(' ');
			else
				putchar(map[i][j]);
		}
		putchar('\n');
	}
	printf("%d", extra);
	return 0;
}