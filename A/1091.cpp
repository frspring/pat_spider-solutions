
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


char map[62][1288][130]={0};
struct cor
{
	int z;
	int y;
	int x;
	cor(int z,int y,int x)
	{
		this->x=x;
		this->y=y;
		this->z=z;
	}
	cor(){};
};
int cnt=0;
const int nextX[6]={0,1,0,-1,0,0};
const int nextY[6]={1,0,-1,0,0,0};
const int nextZ[6]={0,0,0,0,1,-1};
void BFS(int z,int y,int x)
{
	cor t(z,y,x);
	queue<cor> qe;
	qe.push(t);
	map[z][y][x]=3;
	cnt=1;
	while(!qe.empty())
	{
		cor top;
		top = qe.front();
		qe.pop();
		for(int i=0;i<6;i++)
		{
			t.x=top.x+nextX[i];
			t.y=top.y+nextY[i];
			t.z=top.z+nextZ[i];
			if(map[t.z][t.y][t.x]==1)
			{
				cnt++;
				qe.push(t);
				map[t.z][t.y][t.x]=3;
			}
		}
	}
}
//M<1286,N<128
//M行数
//N列数
int main()
{
	int m,n,l,t;
	int temp;
	scanf("%d%d%d%d",&m,&n,&l,&t);//遍历都从1开始到n结束
	for(int z=1;z<=l;z++)
	{
		for(int y=1;y<=m;y++)
		{
			for(int x=1;x<=n;x++)
			{
				scanf("%d",&temp);
				map[z][y][x]=temp;
			}
		}
	}
	int sum=0;
	for(int z=1;z<=l;z++)
	{
		for(int y=1;y<=m;y++)
		{
			for(int x=1;x<=n;x++)
			{
				if((map[z][y][x]==1))
				{
					BFS(z,y,x);
					if(cnt>=t)
						sum+=cnt;
					cnt=0;
				}
			}
		}
	}
	printf("%d",sum);
	return 0;
}