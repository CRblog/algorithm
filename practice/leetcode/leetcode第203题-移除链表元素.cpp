


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *cur = head;
    while(true){
    if(head ==NULL) return NULL;
        if(cur->val != val) break;
        cur = cur->next;
        head = cur;
    }

while(cur->next){
    if(cur->next->val==val){
        cur->next =cur->next->next;
    }
    else{
        cur = cur -> next;
    }
}return head;
}





if(head==NULL)
{
	return ;
}

//先不管第一个结点
struct ListNode *cur = head;
while(cur->next != NULL)
{
	if(cur->next->value = val)
	{
		struct ListNode *next = cur->next->next;
		free(cur->next);
		cur->next = next;
	}
	else
	{
		cur=cur->next;
	}
	if(head->value=val)
	{
		struct ListNode *newHead
	}
}













