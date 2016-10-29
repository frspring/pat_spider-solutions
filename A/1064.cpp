
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
	node* lchild;
	node* rchild;
	node()
	{
		lchild=rchild=NULL;
	}
};
void insert(node* &root,int data)
{
	if(root==NULL)
	{
		root=new node;
		root->data=data;
	}
	else if(data<root->data)
	{
		insert(root->lchild,data);
	}
	else
	{
		insert(root->rchild,data);
	}
}

int sqence[1000];
//1+2+4+..2^N=2^(n+1)-1
//2^(n+1)
void creat(int left,int right,node*& root)
{
	if(left>=right)
		return;
	int lvNum=1;
	while(lvNum-1<=right-left)
		lvNum<<=1;
	lvNum>>=1;
	lvNum--;
	int lb=right-left-lvNum;
	int leftNum=0;
	if(lb>(lvNum+1)/2)
		leftNum=(lvNum+1)/2+(lvNum-1)/2;
	else
		leftNum=(lvNum-1)/2+lb;
	insert(root,sqence[left+leftNum]);
	creat(left,left+leftNum,root);
	creat(left+leftNum+1,right,root);
}
int n;
int cnt=0;
void lvtral(node* root)
{
	queue<node*> qe;
	qe.push(root);
	while(!qe.empty())
	{
		node* top=qe.front();
		qe.pop();
		printf("%d",top->data);
		cnt++;
		if(cnt!=n)
			printf(" ");
		if(top->lchild)
			qe.push(top->lchild);
		if(top->rchild)
			qe.push(top->rchild);
	}
}
int main()
{
	node* rot=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",sqence+i);
	}
	sort(sqence,sqence+n);
	creat(0,n,rot);
	lvtral(rot);
	return 0;
}