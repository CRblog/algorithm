         ����(˫����ͷ��) VS ˳���
˳�������±����

����������ɾ O(1)

ջ�Ͷ���
ջ��
	�Ƚ����(FILO)
��ʲôʵ��ջ�����߶����ԣ���˳��������������
typedef struct Stack{
	int array[100];
	int size;
}Stack;
//��ʼ��
	void StackInit(Stack *s){
			size = 0;
	}
//����
	void StackDestory(Stack *S){
			size = 0;
	}
//����
	void StackPush(int v){
			s->array[s->size++] = v;
	}
//ɾ��
	void StackPop(){
		s->size--;
	}
//����ջ��Ԫ��
	int StackTop(){
			return s->array[s->size-1];
	}
//����ջ�����ݸ���
	int StackSize(){
		return s->size;
	}
//����ջ���Ƿ�Ϊ��ջ
	int StackEmpty(){
		return !s->size;
	}


���У�
	�Ƚ��ȳ�(FIFO)
	ʹ��������ã�ɾ���ĸ��Ӷȸ���
	����У�β��
	�����У�ͷɾ
typedef struct Node{
	int value;
	struct Node *next;
} Node;

typedef struct Queue{
	Node *head;
	Node *last;
}Queue;
QueueInit(Queue *q){
	q->head = q->last = NULL;
}
QueueDestory(Queue *q){
	Node *cur,*next;
	for(cur = q->head;cur!=NULL;cur = next){
		next = cur->next;
		free(cur);
	}
	q->head = q->last = NULL;
}
QueuePush(Queue *q,int v){
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;
	if(q->head == NULL){
		q->head = node;
		q->last = node;
	}
	else
	{
		q->last->next = node;
		q->last = node;
	}
}
QueuePop(Queue *q){
	//ͷɾ
	Node *second = q->head->next;
	free(q->head);
	q->head = second;
	if(q->head == NULL){
		q->last = NULL;
	}
}
QueueFront(){
	return q->head->value;
}
QueueSize(){
	int size = 0;
	for(Node*c = q->head;c!=NULL;c = c->next)
	{
		size++;
	}
	return size;
}
QueueEmpty(){
	if(q->head == NULL)
	{
		return 1;
	}
	else
		return 0;
}
1. ����ƥ�����⡣
2. �ö���ʵ��ջ��
3. ��ջʵ�ֶ��С�
4. ʵ��һ����Сջ��
5. ���ѭ�����С�

