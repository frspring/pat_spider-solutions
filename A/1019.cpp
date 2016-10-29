
#include<stdio.h>
#include<stdint.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;
//3*n-2=N
int main()
{
	int num, base;
	scanf("%d%d", &num, &base);
	int bnum[60] = { 0 };
	int i = 0;
	if (num == 0)
	{
		printf("Yes\n0");
		return 0;
	}
	else
	{
		while (num!=0)
		{
			bnum[i] = num%base;
			num /= base;
			i++;
		}
	}
	bnum[i] = 0;
	int flag = 1;
	int rnum[60] = { 0 };
	memcpy(rnum, bnum,i*sizeof(int));
	reverse(bnum, bnum + i);
	if (memcmp(rnum, bnum,i*sizeof(int)) != 0)
		printf("No\n");
	else
		printf("Yes\n");
	int j = i;
	i = 0;
	printf("%d", bnum[i++]);
	while (i<j)
	{
		putchar(' ');
		printf("%d", bnum[i++]);
	}
	return 0;
}