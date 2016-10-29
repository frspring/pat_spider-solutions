
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
int n;
int cnt=0;
void postTvel(node* root)
{
	if(root==NULL)
		return;
	postTvel(root->lchild);
	postTvel(root->rchild);
	printf("%d",root->data);
	cnt++;
	if(cnt!=n)
	{
		printf(" ");
	}
}
int main()
{
	node* root=new node;
	node* it=root;
	stack<node*> sk;
	scanf("%d",&n);
	int temp;
	char str[6];
	scanf("%s %d",str,&temp);
	it->data=temp;
	sk.push(it);
	for(int i=1;i<2*n;i++)
	{
		scanf("%s",str);
		if(strcmp(str,"Push")==0)
		{
			scanf("%d",&temp);
			if(it->lchild==NULL)
			{
				it->lchild=new node;
				it=it->lchild;
			}
			else
			{
				it->rchild = new node;
				it=it->rchild;
			}
			it->data=temp;
			sk.push(it);
		}
		else
		{
			it = sk.top();
			sk.pop();
		}
	}
	postTvel(root);
	return 0;
}