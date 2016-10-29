
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main()
{
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);

	for(int i=0;i<k;i++)
	{
		stack<int> sd;
		queue<int> sqence;
		for(int i=0;i<n;i++)
		{
			int num;
			scanf("%d",&num);
			sqence.push(num);
		}
		int num;
		int it=1;
		num = sqence.front();
		while(!sqence.empty())
		{
			sd.push(it);
			it++;
			if(sd.size()>m)
				break;
			while(!sd.empty()&&sd.top()==sqence.front())
			{
				sd.pop();
				sqence.pop();
			}
		}
		if(sqence.empty()&&sd.empty())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}