
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int score[101]={0};
	int temp;
	for (int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		score[temp]++;
	}
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		printf("%d",score[temp]);	
		if(i!=n-1)
			printf(" ");
	}
	return 0;
}