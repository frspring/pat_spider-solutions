
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;

struct node
{
	node* lchild;
	node* rchild;
	int data;
	node()
	{
		lchild=0;
		rchild=0;
	}
};
int postOrder[30]={0};
int inOrder[30]={0};
node* creat(int postl,int postr,int inl,int inr)
{
	if(postr<=postl||inr<=inl)
		return NULL;
	int r=postOrder[postr-1];
	int thred=0;
	for(int i=inl;i<inr;i++)
	{
		if(r==inOrder[i])
		{
			thred=i;
			break;
		}
	}
	node *nd = new node;
	nd->data=r;
	nd->lchild=creat(postl,postl+thred-inl,inl,thred);
	nd->rchild=creat(postl+thred-inl,postr-1,thred+1,inr);
	return nd;
}
void BFS(node* root)
{
	queue<node*> qe;
	node *temp;
	qe.push(root);
	while(!qe.empty())
	{
		temp=qe.front();
		qe.pop();
		if(temp->lchild)
			qe.push(temp->lchild);
		if(temp->rchild)
			qe.push(temp->rchild);
		printf("%d",temp->data);
		if(!qe.empty())
		{
			printf(" ");
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",postOrder+i);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",inOrder+i);
	}
	node* root=creat(0,n,0,n);
	BFS(root);
	return 0;
}