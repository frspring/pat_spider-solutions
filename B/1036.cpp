
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	char c;
	scanf("%d %c", &n, &c);
	int row;
	row = (int)(n / 2.0 + 0.5);
	char map[20][20] = {0};
	for (int i = 0; i < n; i++)
		map[0][i] = c;
	for (int i = 0; i < n; i++)
		map[row-1][i] = c;
	for (int i = 0; i < row; i++)
	{
		map[i][0] = c;
		map[i][n - 1] = c;
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(map[i][j]!=0)
				putchar(map[i][j]);
			else
			{
				putchar(' ');
			}
		}
		putchar('\n');
	}
}