203  �Ƴ�����Ԫ��
struct ListNode* removeElements(struct)
{
	if(head == NULL)
	{
		return NULL;
	}
	///�Ȳ��ܵ�һ���������
	struct ListNode *cur = head;
	while(cur->next !=NULL){
		if(cur->next->val = val){
			struct ListNode *next = cur;
		}
	}
}




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





206  ����ķ�ת//��ָ�뷨
   1->2->3->4->5
p3�����ã�p2��next�Ѿ����ı䣬p3����ָ��p2next�ĵ�ַ,��һ�θı�ķ�ʽ
{
	if(head == NULL||head->next == NULL)
	{
		return head;
	}
struct ListNode *p1 = NULL;         ///
struct ListNode *p2 = head;
struct ListNode *p3 = head->next;
	while(p2!=NULL)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if(p3!=NULL)
		{
			p3 = p3->next;
		}
	}
	return p1;
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
��Ҫһ�����㣬������ǰ�����
�Ƚ�-
1����
    ������
2���
    �жϺ�����Ƿ���ȣ��жϺ����Ƿ�Ϊ��

//
ListNode *deleteDuplication(ListNode* pHead){
	if(pHead==NULL)
	{
		return NULL;
	}
	ListNode *fake = (ListNode *)malloc(sizeof(ListNode));
	fake->next = pHead
	ListNode *prev = fake;
	ListNode *p1 = pHead;       //p1��p2�������val�ıȽ�
	ListNode *p2 = pHead->next;  //p2���и�ְ���ҵ�һ������ȵĽ��
	
	while(p2!=NULL){
		if(p1->val!=p2->val)
		{
			pre = p1;
			p1 = p2;
			p2 = p2->next;
		}
		else{
			while(p2!=NULL&&p2->val == p1->val){
				p2 = p2->next;
 			}
 			//ɾ���ľ���[p1,p2)
 			prev->next = p2;
 			if(p2!=NULL)
 			{
 				p2 = p2->next;
			}
		}
	}
	pHead =fake->next;
	free(fake);
}



//ţ��  �ָ�����
ListNode* partition (ListNode* pHead,int x)
{
	ListNode *small = NULL;
	ListNode *small_last = NULL;
	ListNode *big = NULL;
	ListNode *big_last = NULL;
	for(ListNode *c = pHead;c!=NULL;c=c->next){
		if(c->val < x){
			if(small_last == NULL){
				small = small_last = c;
			}
			else
			{
				small_last->next = c;
				small_last = c;
			}
		}
		else{
			if(big_last==NULL){
				big = big_last=c;
			}
			else{
				big_last->next = c;
				big_last = c;
			}
		}
	}
	if(small_last!=NULL){
		small_last->next  =big;
	}
	if(big_last!=NULL){
		big_last->next = NULL
	}
	if(small!=NULL){
		return small;
	}
	else
	{
		return big;
	}
	return small;
}



