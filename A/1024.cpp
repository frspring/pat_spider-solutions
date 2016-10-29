
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

void stringAdd(char* a,char *b)
{
	int i=0;
	int sum;
	int c=0;
	while(a[i]!=0)
	{
		sum = a[i]-'0'+b[i]-'0'+c;
		a[i] = sum%10+'0';
		c=sum/10;
		i++;
	}
	if(c==1)
	{
		a[i]='1';
		a[i+1]=0;
	}
	reverse(a,a+strlen(a));
}
int main()
{
	char num[100];
	int n;
	char sn[100];
	int i=0;
	scanf("%s%d",num,&n);


	for(;i<n;i++)
	{
		strcpy(sn,num);
		reverse(sn,sn+strlen(sn));
		if(strcmp(sn,num)==0)
			break;
		stringAdd(num,sn);
	}
	printf("%s\n%d",num,i);
	return 0;
}
