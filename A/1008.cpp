
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int now =0;
	int temp;
	int time = 0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		time+= 5 + abs(now-temp)*(now>temp?4:6);
		now=temp;
	}
	printf("%d",time);
	return 0;

}