/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
     struct ListNode *newnode =NULL;    //新链表
     struct ListNode *cur = head;       //指针指向头结点
        while(cur!=NULL)    //如果前一个链表里还有结点
        {
           struct  ListNode* next = cur ->next;    //定义next为cur->next
            cur->next = newnode;
            newnode = cur;
            cur = next;
        }
    return newnode;
}
