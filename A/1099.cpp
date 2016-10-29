
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
using namespace std;

struct node
{
	int data;
	int lchild;
	int rchild;
	node()
	{
		lchild=-1;
		rchild=-1;
	}
};
node tree[200];
int sqence[200];
int indx=0;
void intral(int root)
{
	if(root==-1)
		return ;
	intral(tree[root].lchild);
	tree[root].data=sqence[indx];
	indx++;
	intral(tree[root].rchild);
}
int n;
int cnt=0;
void lvtral()
{
	queue<int> qe;
	qe.push(0);
	while(!qe.empty())
	{
		int top=qe.front();
		qe.pop();
		printf("%d",tree[top].data);
		cnt++;
		if(cnt!=n)
			printf(" ");
		if(tree[top].lchild!=-1)
			qe.push(tree[top].lchild);
		if(tree[top].rchild!=-1)
			qe.push(tree[top].rchild);
	}
}
int main()
{
	scanf("%d",&n);
	int l;
	int r;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&l,&r);
		tree[i].lchild=l;
		tree[i].rchild=r;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",sqence+i);
	}
	sort(sqence,sqence+n);
	intral(0);
	lvtral();
	return 0;
}