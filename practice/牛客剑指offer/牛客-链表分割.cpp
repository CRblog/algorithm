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
          if(c->val < x)//С�ڵ�ֵ�Ž�һ������
          {
              if(small_last == NULL){//��һ����Ϊ�յ�ʱ��
                  small = small_last = c;
              }
              else{
                  small_last->next = c;//ָ��c
                  small_last = c;
              }
          }
          else{//���ڵ�ֵ��һ������
              if(big_last == NULL){//ͬ��
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
