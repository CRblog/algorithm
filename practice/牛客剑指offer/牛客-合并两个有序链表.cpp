/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        struct ListNode *result = NULL;
        struct ListNode *tail = NULL;
        if(pHead1==NULL)
        {
             return pHead2;
        }
        else if(pHead2==NULL)
        {
            return pHead1;
        }
        else{
            if(pHead1->val<pHead2->val)
            {
                result = pHead1;
                pHead1 = pHead1->next;
            }
            else{
                result = pHead2;
                pHead2 = pHead2->next;
            }
            tail = result;
        }
        while(pHead1&&pHead2)
        {
            if(pHead1->val<pHead2->val)
            {
                tail->next = pHead1;
                pHead1=pHead1->next;
            }
            else
            {
                tail->next = pHead2;
                pHead2 = pHead2->next;
            }
            tail = tail->next;
        }
        if(pHead1||pHead2)
        {
            tail->next = pHead1!=NULL?pHead1:pHead2;
        }
        return result;
    }
};
