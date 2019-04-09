#include<bits/stdc++.h>
using namespace std;
//
int main()
{
	if(root ==NULL)
	{
	   printf("\n");
	}
	queue<Node *> 	q;
	q.push(root);
	while(!q.empty())
	{
	Node *front = q.front();
	q.pop();
	printf("%c",front->value);
	if(front->left!=NULL)
	{	
	q.push(front->left);
	}
	if(front->right!=NULL)
	{
	q.push(front->right);
	
	}
   	return 0;
}
