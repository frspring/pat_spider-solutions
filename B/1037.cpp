
#include<stdio.h>
#include<stdint.h>
#include<algorithm>
#include<math.h>
using namespace std;
//3*n-2=N
int main()
{
	int galleon[2], sickle[2], knut[2];
	scanf("%d.%d.%d", galleon, sickle, knut);
	scanf("%d.%d.%d", galleon+1, sickle+1, knut+1);
	int price, money;
	price = galleon[0] * 17 * 29 + sickle[0] * 29 + knut[0];
	money = galleon[1] * 17 * 29 + sickle[1] * 29 + knut[1];
	int out;
	out = money - price;
	if (out < 0)
	{
		printf("-");
		out = -out;
	}
	printf("%d.%d.%d", out / (29 * 17), (out / 29) % 17, out % 29);
	
	return 0;
}