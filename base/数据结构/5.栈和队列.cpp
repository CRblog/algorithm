难度：1  链表的头插/头删/尾插/尾删
	  2  逆置/
	  3  删除重复结点/复制复杂链表
	  
	  
具体用途的数据结构（线性结构）
用顺序表来实现栈：代码简单，但是扩容问题会影响性能
栈:
    调用栈
    约束：先进后出：FILO
	//静态顺序表
typedef struct Stack{
	int array[100];
	int size;
}Stack;

//初始化
void StackInit();
//销毁
void StackDestroy();
//插入
void StackPush(Stack *s,int v){
	s->array[s->size-1];
}
//删除
void StackPop();
//返回栈顶得到数据，不需要删除栈顶的数据
int StackTop();
//返回站内数据个数
int StackSize();
//返回栈内是否为空

int StackEmpty()
{
	return !s->size;
}
    
    
队列:
	约束：先进先出：FIFO
    用链表实现（单链表）
    
typedef struct Node{
	int value;
	struct Node *next;
}Node;

typedef struct Queue{
	Node *head;
	Node *last;
}Queue;
void QueueDestroy()
{
	//free所有节点
}
QueuePush()
{
	
}
QueuePop()
QueueFront()
QueueSize(){
	
}
	
//
依次遍历字符串中的每一个字符
    如果是左括号
        压栈
    如果是右括号
        判断当前栈是否为空栈
            右括号多于左括号
        取出栈顶括号（左括号）
        拿左括号和右括号进行匹配
            如果不匹配  return false
        弹出栈顶的左括号
如果栈里还有左括号
    return false
return true

	
最小栈的实现：
    两个栈实现，左边正常存放，右边存放的是要入栈的和当前右边栈顶的最小元素
Don't Panic


栈：括号匹配   逆波兰表达式（后缀表达式）
    迷宫暴力破解法
	
	
