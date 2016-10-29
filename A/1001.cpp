
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
	long a, b, c;
	int r[3];
	cin >> a >> b;
	c = a + b;
	if (c<0)
	{
		printf("-");
		c = -c;
	}
	r[0] = c % 1000;
	c /= 1000;
	r[1] = (c) % 1000;
	c /= 1000;
	r[2] = (c) % 1000;

	if (r[2] != 0)
	{
		printf("%d,", r[2]);
		printf("%03d,", r[1]);
		printf("%03d", r[0]);
	}
	else if(r[1] != 0)
	{
		printf("%d,", r[1]);
		printf("%03d", r[0]);

	}
	else
	{
		printf("%d", r[0]);
	}
	return 0;
}