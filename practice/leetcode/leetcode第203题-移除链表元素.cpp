


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *cur = head;
    while(true){
    if(head ==NULL) return NULL;
        if(cur->val != val) break;
        cur = cur->next;
        head = cur;
    }

while(cur->next){
    if(cur->next->val==val){
        cur->next =cur->next->next;
    }
    else{
        cur = cur -> next;
    }


}return head;
}
