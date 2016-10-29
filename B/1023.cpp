
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
inline char lowerCase(char t)
{
	if(t>='A'&&t<='Z')
		return t-'A'+'a';
	else
		return t;
}
int main()
{
	short num[10000]={0};
	int sum = 0;
	int temp;
	int j=0;
	for (int i=0;i<10;i++)
	{
		scanf("%d",&temp);
		sum+=temp;
		while(temp--)
		{
			num[j++]=i;
		}
	}
	int k=0;
	while(num[k++]==0);
	k--;
	short t;
	t = num[k];
	num[k]=num[0];
	num[0]=t;
	for (int i=0;i<sum;i++)
	{
		printf("%d",num[i]);
	}
	
	return 0;
}