
#include<iostream>
#include<stdio.h>
#include<stdint.h>
#include<string>
#include<algorithm>
using namespace std;

int main()//C J B
{
	int n;
	scanf("%d", &n);
	int position[54];
	int cards[2][54] = { 0 };
	for (int i = 0; i < 54; i++)
	{
		cards[0][i] = i;
	}
	int flag = 1;
	for (int i = 0; i < 54; i++)
	{
		scanf("%d", position + i);
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < 54; i++)
		{
			cards[flag][position[i]-1] = cards[!flag][i];
		}
		flag = !flag;
	}
	flag = !flag;
	for (int i = 0; i < 54; i++)
	{
		if (cards[flag][i] < 13)
			printf("S");
		else if (cards[flag][i] < 26)
			printf("H");
		else if (cards[flag][i] < 39)
			printf("C");
		else if (cards[flag][i] < 52)
			printf("D");
		else
			printf("J");
		printf("%d", cards[flag][i] % 13 + 1);
		if (i != 53)
			printf(" ");

	}
}