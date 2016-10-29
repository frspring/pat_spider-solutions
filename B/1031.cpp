
#include <stdio.h>

const int wofn[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
const char M[12] = "10X98765432";

int main()
{
	int n = 0;
	char id[19];
	int flag = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int weigh = 0;
		int j = 0;
		scanf("%s", id);
		for (j; j < 17; j++)
		{
			if (id[j]<'0' || id[j]>'9')
			{
				flag = 1;
				printf("%s\n", id);
				break;
			}
			weigh += wofn[j] * (id[j] - '0');
		}
		if (j == 17 && M[(weigh % 11)] != id[17])
		{
			flag = 1;
			printf("%s\n", id);
		}
	}
	if (flag == 0)
	{
		printf("All passed");
	}
	return 0;
}