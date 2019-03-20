//Ë«Ö¸Õë
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
   struct ListNode *cur1 = pListHead;
   struct ListNode *cur2 = pListHead;
        if(pListHead==NULL||k==0)
            return NULL;
        for(unsigned int i=1;i<k;i++)
        {   if(cur1->next!=NULL)
                {
                    cur1 = cur1->next;
                }
            else
                   return NULL;
        }
        while(cur1->next!=NULL)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur2;
    }
};
