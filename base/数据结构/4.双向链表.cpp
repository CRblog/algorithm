//链表逆置

typedef struct Node{
	int value;
	struct Node *next;
}Node;
//三指针逆置
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
//普通逆置

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

//头插









链表相交：一定是Y型，因为单链表的指向只有一个方向
求交点：长的减短的，长的先走N步，两个一起走，判断相等，如果相等则相交，不相交返回空



141求环  142
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



双向链表
struct Node{
	int val;
	struct Node *next;
	struct Node *prev;
};


循环链表
最后一个指向第一个


带头结点


typedef struct DNode{
	int value;
	struct DNode *prev;
	struct DNode *next;
}DNode;

void DListInit(DNode **node){//二级指针
	//创建头节点
	DNode *head = (DNdoe *)malloc(sizeof(DNode));
	
	head->next = head;
	head->prev = head;
	
	*node = head;
}




//顺序表和链表的区别

顺序表：
    1.插入删除比较麻烦（除了尾插和尾删都是O(n)）
    2.根据下标随便访问
链表：
    1.增删都是O(1)(双向)
    2.不支持随机访问
