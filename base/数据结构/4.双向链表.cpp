//��������

typedef struct Node{
	int value;
	struct Node *next;
}Node;
//��ָ������
Node * Reverse(Node *head)
{
	Node *pre = NULL;
	Node *cur = head;
	while(cur!=NULL)
	{
		Node *next = cur->next;
		
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}
//��ͨ����

Node * Reverse(Node *head){
	Node *result = NULL;
	Node *cur = head;
	while(cur!=NULL)
	{
		Node *next = cur->next;
		
		cur->next = result;
		result = cur;
		cur = next;
	}
	return result;
}

//ͷ��









�����ཻ��һ����Y�ͣ���Ϊ�������ָ��ֻ��һ������
�󽻵㣺���ļ��̵ģ���������N��������һ���ߣ��ж���ȣ����������ཻ�����ཻ���ؿ�



141��  142
struct LsitNode *fast = head;
struct ListNode *slow = head;
while(1)
{
	if(fast == NULL)
	{
		return false;
	}
	fast = fast->next;
	if(fast == NULL)
	{
		return false;
	}
	fast = fast->next;
	slow = slow->next;
	if(fast == slow)
	{
		return true;
	}
}



˫������
struct Node{
	int val;
	struct Node *next;
	struct Node *prev;
};


ѭ������
���һ��ָ���һ��


��ͷ���


typedef struct DNode{
	int value;
	struct DNode *prev;
	struct DNode *next;
}DNode;

void DListInit(DNode **node){//����ָ��
	//����ͷ�ڵ�
	DNode *head = (DNdoe *)malloc(sizeof(DNode));
	
	head->next = head;
	head->prev = head;
	
	*node = head;
}




//˳�������������

˳���
    1.����ɾ���Ƚ��鷳������β���βɾ����O(n)��
    2.�����±�������
����
    1.��ɾ����O(1)(˫��)
    2.��֧���������
