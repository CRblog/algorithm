#include<bits/stdc++.h>
using namespace std;
#pragma once

typedef struct Node{
	Node *left;
	Node *right;
	char value;
}Node;
//查找值
Node * Find(Node *root,int value);
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->value==value)
	{
		return root;
	}
	Node *result = Find(root->left,value);
	if(Find(root->left,value)!=NULL)
	{
		return result;
	}
	Node *result = Find(root->right,value);
	if(Find(root->right,value)!=NULL)
	{
		return result;
	}
	else
	{
		return NULL;
	}
}
typedef struct{
	Node *root;
	int used;       //创建过程中用掉的前序值个数
}Result;


//2019 04 01
CreateTree(char preorder){
	if(size==0)
	{
			Result r = {NULL,0};
		return  r;
	}
	char rootValue = preorder[0];
	if(rootValue=='#')
	{
		Result r ={NULL,1};
		return r;
	}
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;    //根
	Result leftResult = CreateTree(preorder + 1,size - 1);
	root->left  =leftResult.root;
	
	Result rightResult  =CreateTree(
		preorder + 1 + leftResult.used,
		size - 1 - leftResult.used);
		root->right = rightResult.root;
		
		Result r = {root,1 + leftResult.used + rightResult.used};
		return r;
}

