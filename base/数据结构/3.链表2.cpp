链表
void PushBack(SList *s,SListDataType v)
{
	//有结点，无结点
	Node *node = (Node* )malloc(sizeof(Node));
	if()
	{
		
	}
	else
	{
		//找最后一个结点
		Node *p;
		p = s->first;
		while(p->next != NULL){
			p = p->next;
		}
		p ->next = node;
	}
}
void PopBack(SList *s)
{
	//没有结点，直接assert
	//只有一个结点
    //多余一个结点的情况
    
}

/*
1.操作的是cur结点，实际要改变的是cur的前驱
2.往往第一个结点是特殊情况
    创建一个虚结点，第一个结点就有了前驱结点

*/

Node *SListFind(SList *s,SListDataType v)
{
	for(Node *cur=s->first;cur!=NULL;cur = cur->next)
	
	{
		if()
	}
}
//在pos的后面做插入
void SLis      (               ){
	Node *node = (Node *)malloc                 ;
	node->value = v;
	node->next = pos->next;
	pos->next = node;

}

//pos一定是链表中的结点，并且pos不是链表的最后一个结点
void
{
	Node *next = pos->next;
	pos->next = pos->next->next;
}


//销毁
void {
	for(Node *cur = s->first;cur!=NULL;cur = next){
		next = cur->next;
		free(cur);
	}
	s->first = NULL;

}
