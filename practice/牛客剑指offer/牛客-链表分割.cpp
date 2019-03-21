/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
      ListNode *small = NULL;
      ListNode *small_last = NULL;
      ListNode *big = NULL;
      ListNode *big_last = NULL;
      for(ListNode *c = pHead;c!=NULL;c=c->next){
          if(c->val < x)//小于的值放进一个链表
          {
              if(small_last == NULL){//第一步，为空的时候
                  small = small_last = c;
              }
              else{
                  small_last->next = c;//指向c
                  small_last = c;
              }
          }
          else{//大于的值放一个链表
              if(big_last == NULL){//同上
                  big = big_last = c;
              }
              else{
                  big_last->next = c;
                  big_last = c;
              }
          }
      }
        //
        if(small_last!=NULL){
            small_last->next = big;
        }
        if(big_last!=NULL){
            big_last -> next = NULL;
        }
        if(small!=NULL){
            return small;
        }
        else{
            return big;
        }
        return small;
    }
};
