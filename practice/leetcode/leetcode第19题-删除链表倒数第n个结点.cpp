/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    //删除4，则需要把三的next接到它的next->next
    struct ListNode *fast = head;
    struct ListNode *slow = head;

    if(head->next==NULL)
    {
        return NULL;
    }
    if(head->next->next==NULL)
    {
        if(n==2)
        {
            head = head->next;
            head->next = NULL;
        }
        else
        {
            head->next=NULL;
        }
        return head;
    }
    for(int i=1;i<n;i++)
    {
        fast = fast->next;
        if(fast->next==NULL)
        {
            head = head->next;
            return head;
        }


    }
    while(fast->next->next!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next=slow->next->next;
    return head;
 }
