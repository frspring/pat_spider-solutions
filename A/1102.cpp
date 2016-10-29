
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
	node(int vaule)
	{
		lchild=0;
		rchild=0;
		data=vaule;
	}
};
int n;
int ct=0;
void levTvel(node* root)
{
	queue<node*> qw;
	qw.push(root);
	while(!qw.empty())
	{
		root=qw.front();
		qw.pop();
		printf("%d",root->data);
		ct++;
		if(ct!=n)
			printf(" "); 
		if(root->rchild)
			qw.push(root->rchild);
		if(root->lchild)
			qw.push(root->lchild);

	}
}
int cnt=0;
void postTvel(node* root)
{
	if(root==NULL)
		return;
	postTvel(root->rchild);
	printf("%d",root->data);
	cnt++;
	if(cnt!=n)
	{
		printf(" ");
	}
	postTvel(root->lchild);
	
}
struct lr
{
	int l;
	int r;
};
int main()
{
	bool stime[20]={0};
	lr sqen[20];
	scanf("%d",&n);
	char str[20];
	getchar();
	for(int i=0;i<n;i++)
	{
		gets(str);
		sqen[i].l=(str[0]=='-')? 19:str[0]-'0';
		sqen[i].r=(str[2]=='-')? 19:str[2]-'0';
		stime[sqen[i].l]=stime[sqen[i].r]=true;
	}
	node* root=new node;
	for(int i=0;i<n;i++)
	{
		if(!stime[i])
		{
			root->data=i;
			break;
		}
	}
	node* it=root;
	queue<node*> qe;
	qe.push(it);
	while(!qe.empty())
	{
		it=qe.front();
		qe.pop();
		if(sqen[it->data].l!=19)
		{
			it->lchild=new node(sqen[it->data].l);
			qe.push(it->lchild);
		}
		if(sqen[it->data].r!=19)
		{
			it->rchild=new node(sqen[it->data].r);
			qe.push(it->rchild);
		}
	}
	levTvel(root);
	printf("\n");
	postTvel(root);
	return 0;
}