#include<bits/stdc++.h>
using namespace std;
/*
int main(){
	int *p;          Ұָ��
	*p = 100;
	return 0;
    Σ������Ұָ����в������п��ܻ��������ı���
����Ұָ��
	1)ָ�����û�г�ʼ��
	2)ָ��ָ����ڴ��Ѿ����ͷţ�
��ָ�뱾��û����NULL
	3)ָ�볬���˱��������÷�Χ
���ⷽ����
��ʼ��ָ��ʱ��ָ����ΪNULL��֮���ٶ�����в���
�ͷ�ָ��ʱ������ΪNULL������ڱ�д�����ǽ�free�������з�װ������ָ����ÿ�
}
*/
����    �ص�

[a1| ] -> [a2| ]

#pragma once
typedef int SListDataType
����Ĳ�����������ݽṹ������������һ�����Ľṹ��
typedef struct ListNode{
	SListDataType value;    //�����ֵ
	struct ListNode *next;  //������һ�����ĵ�ַ
} Node;


typedef struct SList{
	Node *first;            //Node *head;
}SList;//��first==NULL ��ʾ�Ǹ�������

//��ʼ��
void SListInit(SList * s){
	assert(s!=NULL);
	s->first = NULL;
}
void Test()
{
	SList list;
	SListInit();
}
//1ͷ��
����һ���ڴ�
void SListPushFront(SList *s SListDataType v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node -> value = v;
	node -> next = s->first;
	s->first = node;
}
//β��
void SListPushBack(SList *s SListDataType v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node ->value = v;
	node->next = NULL;
	
	if(s->first == NULL){
		//����Ϊ��
		s->first = node;
		return;
	}
	else{
//����ҵ����һ����㣨������һ���н�㣩
	Node *cur = s->first;
	while(cur->next!=NULL){
		cur = cur->next
	}
	cur->next = node;
}
}


//ͷɾ

void SListPopFront(SList *s){
	assert(s!=NULL);            //����û������
	assert(s->first !=NULL);    //����û�нڵ�

Node *next = s->first->next;
free(s->first);
s->first=next;
}
//βɾ
void SListPopBack(SList *s){
	assert(s!=NULL);            //����û������
	assert(s->first !=NULL);    //����û�нڵ�
	if(s->first->next == NULL)
	{   //������ֻ��һ���ڵ�
		free(s->first);
		s->first = NULL;
		return ;
	}
	Node *cur;
	for(cur = s->first;cur->next->next!=NULL;cur = cur->next){
		free(cur->next);
		cur->next = NULL;
	}
}

Leetcode 206












