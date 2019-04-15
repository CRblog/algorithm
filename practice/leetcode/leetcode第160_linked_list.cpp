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
    struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
        struct ListNode *cur1 = headA;
        struct ListNode *cur2 = headB;
        struct ListNode *ans = NULL;
        int len1 =0;
        int len2 =0;
        if(headA==NULL||headB==NULL)
        {
            return NULL;
        }
        while(cur1->next!=NULL)
        {
            cur1 = cur1->next;
            len1++;
        }
        while(cur2->next!=NULL)
        {
            cur2 = cur2->next;
            len2++;
        }
        cur1 = headA;
        cur2 = headB;
        if(len1>len2)
        {
            int times = len1-len2;
            while(times--)
            {
                cur1 = cur1->next;
            }
        }
        else
        {
            int times = len2-len1;
            while(times--)
            {

                cur2 = cur2->next;
            }
        }
       while(cur1!=NULL && cur2!=NULL)
       {
           if(cur1==cur2)
           {
               ans = cur1;
               break;
           }
           cur1 = cur1->next;
           cur2 = cur2->next;
       }
        return ans;
    }
};
