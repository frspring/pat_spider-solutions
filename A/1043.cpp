
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

void preTrv(node* root,vector<int>& vc)
{
	if(root==NULL)
		return;
	vc.push_back(root->data);
	preTrv(root->lchild,vc);
	preTrv(root->rchild,vc);
}
void postTrv(node* root,vector<int>& vc)
{
	if(root==NULL)
		return;
	postTrv(root->lchild,vc);
	postTrv(root->rchild,vc);
	vc.push_back(root->data);
}
void mirTrv(node* root,vector<int>& vc)
{
	if(root==NULL)
		return;
	vc.push_back(root->data);
	mirTrv(root->rchild,vc);
	mirTrv(root->lchild,vc);
}
void mirpTrv(node* root,vector<int>& vc)
{
	if(root==NULL)
		return;
	mirpTrv(root->rchild,vc);
	mirpTrv(root->lchild,vc);
	vc.push_back(root->data);
}
int main()
{
	int n;
	scanf("%d",&n);
	int temp;
	node* root = NULL;
	vector<int> orig;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		orig.push_back(temp);
		insert(root,temp);
	}

	vector<int> pre;
	vector<int> mir;
	vector<int> post;
	preTrv(root,pre);
	mirTrv(root,mir);
	if(orig==pre)
	{
		printf("YES\n");
		postTrv(root,post);
		for(int i=0;i<post.size();i++)
		{
			printf("%d",post[i]);
			if(i!=post.size()-1)
				printf(" ");
		}
	}
	else if(orig==mir)
	{
		printf("YES\n");
		mirpTrv(root,post);
		for(int i=0;i<post.size();i++)
		{
			printf("%d",post[i]);
			if(i!=post.size()-1)
				printf(" ");
		}
	}
	else
		printf("NO");

	return 0;
}