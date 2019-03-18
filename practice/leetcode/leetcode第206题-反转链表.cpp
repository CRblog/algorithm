/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
     struct ListNode *newnode =NULL;    //������
     struct ListNode *cur = head;       //ָ��ָ��ͷ���
        while(cur!=NULL)    //���ǰһ�������ﻹ�н��
        {
           struct  ListNode* next = cur ->next;    //����nextΪcur->next
            cur->next = newnode;
            newnode = cur;
            cur = next;
        }
    return newnode;
}
