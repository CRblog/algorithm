/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        struct ListNode *fake = (ListNode *)malloc(sizeof(struct ListNode));
        fake->next = pHead;
        struct ListNode *prev = fake;
        struct ListNode *p1 = pHead;
        struct ListNode *p2 = pHead->next;

        if(pHead==NULL)
        {
            return NULL;
        }
        while(p2!=NULL)
        {
          if(p1->val != p2->val){
              prev = p1;
              p1 = p2;
              p2 = p2->next;
          }
            else{
                while(p2!=NULL&&p2->val ==p1->val)
                {
                    p2 = p2->next;
                }
                prev->next = p2;
                p1 = p2;
                if(p2!=NULL)
                {
                p2 = p2->next;
                }

            }
        }
        pHead = fake->next;
        free(fake);
        return pHead;
    }
};















