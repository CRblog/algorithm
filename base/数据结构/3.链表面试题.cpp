876����ָ��
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


21�ϲ��������


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
struct Node *result =NULL;//�������ĵ�һ������ַ
struct Node *tail=NULL;     //�����������һ�����ĵ�ַ
while(c1!=NULL&&c2!=NULL)
{
	if(c1->val<=c2->val)
	{
		if(tail==NULL)
		{
			result = tail =c1;
		}
		else{
				//ȡl1����Ľ��
		tail->next = c1;   //ĩ���ָ��C1
		tail = c1;          //ֵ����c1
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
				//ȡl1����Ľ��
		tail->next = c2;   //ĩ���ָ��C1
		tail = c2;          //ֵ����c1
		}
		c2=c2->next;
	}
	
	
}

//l1 ���� l2 ��һ����������н�㱻ȥ����
if(c1!=NULL)
{
	tail->next = c1;    //������Ǵ�c1��ʼ�ĺ������н��
}
else
{
	tail->next = c2;
}





����ķ�ת
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



ɾ���ظ����

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




