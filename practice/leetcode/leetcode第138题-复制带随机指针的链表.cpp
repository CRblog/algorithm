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
//在每个结点之后插入一个新结点
       // 1.复制链表中的每一个结点，让新结点跟在老节点的后边
        Node *cur = head;
        while(cur!=NULL){
            Node *newNode = new Node(cur->val,cur->next,cur->random);

            cur -> next = newNode;
            cur = newNode->next;
        }
        //2.新结点的random指向老节点的random的下一个结点
        cur = head;
        while(cur!=NULL)
        {
            Node *newNode = cur->next;
            if(cur->random!=NULL){
                 newNode->random = cur->random->next;
            }
               cur = cur->next->next;
        }
       // 3.拆开新老结点
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
