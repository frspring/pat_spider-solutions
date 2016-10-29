
#include <stdio.h>

typedef struct _money
{
	int knut = 0;
	int sickle = 0;
	int gallon = 0;
}money;

int main()
{
	money a, b, c;
	scanf("%d.%d.%d", &a.gallon, &a.sickle, &a.knut);
	scanf("%d.%d.%d", &b.gallon, &b.sickle, &b.knut);
	c.knut = a.knut + b.knut;
	if (c.knut >= 29)
	{
		c.knut -= 29;
		c.sickle++;
	}
	c.sickle += a.sickle + b.sickle;
	if (c.sickle >= 17)
	{
		c.sickle -= 17;
		c.gallon++;
	}
	c.gallon += a.gallon + b.gallon;
	printf("%d.%d.%d", c.gallon, c.sickle, c.knut);
	return 0;
}