#include<bits/stdc++.h>
using namespace std;


typedef struct ListNode{
	int val;
	struct ListNode *next;
}Node;

typedef struct SList{
	Node *first;
}SList


int deleteList(ListNode *s)
{
	struct Node *fake = (Node*)malloc(sizeof(Node*));
	fake->next = s;
	struct Node *cur = s->first;
	struct Node *pre = fake;
	
	struct Node *p2 = s->next;
	if(cur==NULL)
	{
		return NULL;
	}
	while(cur!=NULL)
	{
		if(cur->val!=p2->val)
		{
			pre = cur;
			cur = p2;
			p2 = p2->next;
		}
	    while(p2!=NULL&&cur->val==p2->val)
		{
			p2=p2->next;
			if(cur->val!=p2->next->val)
			{
				cur->next = p2->next;
			}
		}
		return s;
	}
}
int main()
{
	int n;
	cin>>first;
	while(n--)
	{
		cin>>Node>>Node.val>>Node.next;
	}
	cout<<deleteList(first)<<endl;
  return 0;
}
