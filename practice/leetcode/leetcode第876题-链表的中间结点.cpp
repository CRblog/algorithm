/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
找到非空链表的中间结点
//用快慢指针进行查找
//快指针先走一步，进行判断，判断当前指针指向是否为空，如果为空就返回慢指针
//然后再判断，判断完之后慢指针前进，快指针前进。
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast!= NULL)
    {
        fast = fast -> next;
        if(fast!= NULL)
        {
            slow = slow -> next;
            fast = fast ->next;
        }
        else
        {
           return slow;
        }
    }

    return slow;
}
