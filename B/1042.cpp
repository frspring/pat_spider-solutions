
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
	char t;
	int chtr[128]={0};
	int maxC = 0,maxTime = 0;
	int temp  = 0;
	t=getchar();
	while(t!='\n')
	{
		if((t>='A'&&t<='Z')||(t>='a'&&t<='z'))
		{
			temp = lowerCase(t);
			chtr[temp]++;
			if(chtr[temp]>maxTime||(chtr[temp]==maxTime&&temp<maxC))
			{
				maxC = temp;
				maxTime  = chtr[temp];
			}
		}
		t=getchar();
	}
	printf("%c %d",maxC,maxTime);
	return 0;
}