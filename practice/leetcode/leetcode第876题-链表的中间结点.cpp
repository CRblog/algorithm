/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
�ҵ��ǿ�������м���
//�ÿ���ָ����в���
//��ָ������һ���������жϣ��жϵ�ǰָ��ָ���Ƿ�Ϊ�գ����Ϊ�վͷ�����ָ��
//Ȼ�����жϣ��ж���֮����ָ��ǰ������ָ��ǰ����
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
