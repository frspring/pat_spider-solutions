
#include<stdio.h>
#include<stdint.h>
#include<algorithm>
#include<math.h>
using namespace std;
//3*n-2=N
int main()
{
	char str[2000] = { 0 };
	scanf("%s", str);
	int length = 0;
	int count = 0;
	while (str[length]!=0)
	{
		length++;
	}
	int sideLine = 0;
	int bottom = 0;
	sideLine = (length + 2) / 3.0;
	bottom = length + 2 - 2 * sideLine;
	int fcount = length-1;
	for (int i = 0; i < sideLine-1; i++)
	{
		putchar(str[count++]);
		for (int j = 1; j < bottom-1; j++)
		{
			putchar(' ');
		}
		putchar(str[fcount--]);
		putchar('\n');
	}
	while (count<fcount+1)
	{
		putchar(str[count++]);
	}
	return 0;
}