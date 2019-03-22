/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//思路：
遍历测链表的长度，然后长的减短的
让长的和短的走到一样的距离，一起出发，就会一起到达公共点，用相等判断
int getLength(struct ListNode *head)
{
    int l=0;
    for(struct ListNode *n = head;n!=NULL;n=n->next)
    {
        l++;
    }
    return l;
    }
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    struct ListNode *longer = headA;
    struct ListNode *shorter = headB;
    int d = lenA-lenB;
    if(lenB>lenA)
    {
        longer = headB;
        shorter = headA;
        d = lenB-lenA;
    }
    for(int i=0;i<d;i++)
    {
        longer = longer->next;
    }
    while(longer!=shorter)
    {
        longer = longer->next;
        shorter = shorter->next;
    }
    return longer;
}
