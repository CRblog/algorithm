/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
//��ÿ�����֮�����һ���½��
       // 1.���������е�ÿһ����㣬���½������Ͻڵ�ĺ��
        Node *cur = head;
        while(cur!=NULL){
            Node *newNode = new Node(cur->val,cur->next,cur->random);

            cur -> next = newNode;
            cur = newNode->next;
        }
        //2.�½���randomָ���Ͻڵ��random����һ�����
        cur = head;
        while(cur!=NULL)
        {
            Node *newNode = cur->next;
            if(cur->random!=NULL){
                 newNode->random = cur->random->next;
            }
               cur = cur->next->next;
        }
       // 3.�����Ͻ��
        cur = head;
        Node *newHead = NULL;
        if(head!=NULL)
        {
            newHead = head->next;
        }
         while(cur!=NULL)
         {
             Node *newNode = cur->next;
             cur->next = newNode->next;
             if(newNode->next!=NULL)
             {
                newNode->next = newNode->next->next;
             }
                       cur = cur->next;
         }
        return newHead;
    }
};
