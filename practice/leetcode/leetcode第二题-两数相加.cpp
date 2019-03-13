/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //�㷨˼·�����ڴ������
        //�ӵ�ʱ���ж�ע��Ҫ�ж����޽�λ
        ListNode *pHead = new ListNode(0);
        ListNode *pCurrent = pHead;
        int overload = 0;      //��λ
        while(l1||l2||overload)
        {
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+overload;
                if(sum>=10)
                {
                    sum %= 10;
                    overload = 1;
                }
                else
                    overload = 0;
            pCurrent->next = new ListNode(sum);
            pCurrent = pCurrent->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
       return pHead->next;}
};
