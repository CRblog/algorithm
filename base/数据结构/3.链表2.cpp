����
void PushBack(SList *s,SListDataType v)
{
	//�н�㣬�޽��
	Node *node = (Node* )malloc(sizeof(Node));
	if()
	{
		
	}
	else
	{
		//�����һ�����
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
	//û�н�㣬ֱ��assert
	//ֻ��һ�����
    //����һ���������
    
}

/*
1.��������cur��㣬ʵ��Ҫ�ı����cur��ǰ��
2.������һ��������������
    ����һ�����㣬��һ����������ǰ�����

*/

Node *SListFind(SList *s,SListDataType v)
{
	for(Node *cur=s->first;cur!=NULL;cur = cur->next)
	
	{
		if()
	}
}
//��pos�ĺ���������
void SLis      (               ){
	Node *node = (Node *)malloc                 ;
	node->value = v;
	node->next = pos->next;
	pos->next = node;

}

//posһ���������еĽ�㣬����pos������������һ�����
void
{
	Node *next = pos->next;
	pos->next = pos->next->next;
}


//����
void {
	for(Node *cur = s->first;cur!=NULL;cur = next){
		next = cur->next;
		free(cur);
	}
	s->first = NULL;

}
