
#include <stdio.h>


int main()
{
	int RGB[3];
	scanf("%d%d%d", RGB, RGB+1, RGB+2);
	int color[3][2];
	for (int i = 0; i < 3; i++)
	{
		color[i][0] = RGB[i] / 13;
		color[i][1] = RGB[i] % 13;
	}
	printf("#%X%X%X%X%X%X", color[0][0], color[0][1], color[1][0]
		, color[1][1], color[2][0], color[2][1]);
	return 0;
}