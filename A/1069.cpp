
#include <stdio.h>
#include <algorithm>
 
using namespace std;
int main()
{
    int num = 0;
    int n[4] = { 0 };
    int fewer = 0, bigger = 0;
    scanf("%d", &num);
	if(num == 6174)
	{
		printf("7641 - 1467 = 6174");
		return 0;
	}
    if (num % 1111 == 0)
    {
        printf("%04d - %04d = 0000", num, num);
        return 0;
    }
    while (num!=6174)
    {
        for (int i = 0; i < 4; i++)
        {
            n[i] = num % 10;
            num /= 10;
        }
        sort(n, n+4);
        bigger = n[0] + n[1] * 10 + n[2] * 100 + n[3] * 1000;
        fewer = n[3] + n[2] * 10 + n[1] * 100 + n[0] * 1000;
        num = bigger - fewer;
        printf("%04d - %04d = %04d\n", bigger, fewer, num);
    }
	
    return 0;
}