876快慢指针
{
struct ListNode *fast = head;
struct ListNode *slow = head;
while(fast!=NULL)
{
	fast = fast->next;
	if(fast!=NULL)
	{
		fast = fast->next;
	}
	slow = slow->next;
	fast = fast ->next;
}
return p1;
}


21合并两个结点


1->2->3   1->3->4
1->1->2

if(l1==NULL)
{
	return l2;
}
if(l2==NULL)
{
	return l1;
}
struct Node *c1 = l1;
struct Node *c2 = l2;
struct Node *result =NULL;//结果链表的第一个结点地址
struct Node *tail=NULL;     //结点链表的最后一个结点的地址
while(c1!=NULL&&c2!=NULL)
{
	if(c1->val<=c2->val)
	{
		if(tail==NULL)
		{
			result = tail =c1;
		}
		else{
				//取l1链表的结点
		tail->next = c1;   //末结点指向C1
		tail = c1;          //值换成c1
		}
		c1=c1->next;
	}
	else
	{
		if(tail==NULL)
		{
			result = tail =c2;
		}
		else{
				//取l1链表的结点
		tail->next = c2;   //末结点指向C1
		tail = c2;          //值换成c1
		}
		c2=c2->next;
	}
	
	
}

//l1 或者 l2 有一条链表的所有结点被去完了
if(c1!=NULL)
{
	tail->next = c1;    //代表的是从c1开始的后续所有结点
}
else
{
	tail->next = c2;
}





链表的反转
   1->2->3->4->5

p2->next=p1;
Node * Reverse(Node *head)
{
	Node prev = NULL;
	Node *cur = head;
	
	while(cur!=NULL)
	{
		Node *next = cur->next;
		
        cur->next = prev;
        
        prev = cur;
        cur = next;
}
}



ListNode *small = NULL;
ListNode *small_last = NULL;
ListNode *big = NULL;
ListNode *big_last =NULL;
for(ListNode *c = pHead;c!= NULL;c=c->next)
{
	if(c->val < x)
	{
		if(small_last == NULL)
		{
			small = small_last = c;
		}
		else
		{
			small_last-<next = c;
			small_last = c;
		}
	}
	else
	{
		

	     if(big_last == NULL)
		{
			big = big_last = c;
		}
		else
		{
			big_last-<next = c;
			big_last = c;
		}

	}
}



删除重复结点

ListNode *deleteDuplication(ListNode* pHead){
	ListNode *fake = (ListNode *)malloc(sizeof(ListNode));
	fake->next = pHead
	ListNode *prev = fake;
	ListNode *p1 = pHead;
	ListNode *p2 = pHead->next;
	
	while(p2!=NULL){
		if()
	}
}




