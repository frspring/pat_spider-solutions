
#include<stdio.h>
#include<stdint.h>
#include<algorithm>
#include<math.h>
using namespace std;
//3*n-2=N
int main()
{
	int a, b, d, sum;
	scanf("%d%d%d", &a, &b, &d);
	sum = a + b;
	char oNum[70];
	int i = 0;
	if (sum == 0)
	{
		printf("0");
		return 0;
	}
	while (sum != 0)
	{
		oNum[i] = sum%d+'0';
		sum /= d;
		i++;
	}
	for (;i>0 ; i--)
	{
		putchar(oNum[i-1]);
	}
	
	return 0;
}