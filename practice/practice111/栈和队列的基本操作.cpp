         链表(双向有头环) VS 顺序表
顺序表：随机下标访问

链表：便于增删 O(1)

栈和队列
栈：
	先进后出(FILO)
用什么实现栈：两者都可以，但顺序表存在扩容问题
typedef struct Stack{
	int array[100];
	int size;
}Stack;
//初始化
	void StackInit(Stack *s){
			size = 0;
	}
//销毁
	void StackDestory(Stack *S){
			size = 0;
	}
//插入
	void StackPush(int v){
			s->array[s->size++] = v;
	}
//删除
	void StackPop(){
		s->size--;
	}
//返回栈顶元素
	int StackTop(){
			return s->array[s->size-1];
	}
//返回栈内数据个数
	int StackSize(){
		return s->size;
	}
//返回栈内是否为空栈
	int StackEmpty(){
		return !s->size;
	}


队列：
	先进先出(FIFO)
	使用链表更好，删除的复杂度更低
	入队列：尾插
	出队列：头删
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
	//头删
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
1. 括号匹配问题。
2. 用队列实现栈。
3. 用栈实现队列。
4. 实现一个最小栈。
5. 设计循环队列。

