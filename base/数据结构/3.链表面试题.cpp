203  移除链表元素
struct ListNode* removeElements(struct)
{
	if(head == NULL)
	{
		return NULL;
	}
	///先不管第一个结点的情况
	struct ListNode *cur = head;
	while(cur->next !=NULL){
		if(cur->next->val = val){
			struct ListNode *next = cur;
		}
	}
}




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





206  链表的反转//三指针法
   1->2->3->4->5
p3的作用，p2的next已经被改变，p3用来指向p2next的地址,下一次改变的方式
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



删除重复结点
需要一个虚结点，用来当前驱结点
比较-
1不等
    往后走
2相等
    判断后面的是否相等，判断后面是否为空

//
ListNode *deleteDuplication(ListNode* pHead){
	if(pHead==NULL)
	{
		return NULL;
	}
	ListNode *fake = (ListNode *)malloc(sizeof(ListNode));
	fake->next = pHead
	ListNode *prev = fake;
	ListNode *p1 = pHead;       //p1和p2负责进行val的比较
	ListNode *p2 = pHead->next;  //p2还有个职责，找第一个不相等的结点
	
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
 			//删除的就是[p1,p2)
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



//牛客  分割链表
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



