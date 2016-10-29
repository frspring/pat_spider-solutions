
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n = 0, i = 0;
	scanf("%d", &n);
	while (n!=1)
	{
		i++;
		n = n % 2 ? (3 * n + 1) / 2 : n / 2;
	}
	printf("%d", i);
	return 0;
}