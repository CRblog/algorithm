#include<bits/stdc++.h>
using namespace std;
/*
int main(){
	int *p;          野指针
	*p = 100;
	return 0;
    危害：对野指针进行操作，有可能会引起程序的崩溃
三种野指针
	1)指针变量没有初始化
	2)指针指向的内存已经被释放，
而指针本身没有置NULL
	3)指针超过了变量的作用范围
避免方法：
初始化指针时将指针置为NULL，之后再对其进行操作
释放指针时将其置为NULL，最好在编写代码是将free（）进行封装，加上指针的置空
}
*/
链表    重点

[a1| ] -> [a2| ]

#pragma once
typedef int SListDataType
定义的不是链表的数据结构，而是链表中一个结点的结构体
typedef struct ListNode{
	SListDataType value;    //保存的值
	struct ListNode *next;  //保存下一个结点的地址
} Node;


typedef struct SList{
	Node *first;            //Node *head;
}SList;//当first==NULL 表示是个空链表

//初始化
void SListInit(SList * s){
	assert(s!=NULL);
	s->first = NULL;
}
void Test()
{
	SList list;
	SListInit();
}
//1头插
申请一个内存
void SListPushFront(SList *s SListDataType v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node -> value = v;
	node -> next = s->first;
	s->first = node;
}
//尾插
void SListPushBack(SList *s SListDataType v)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node ->value = v;
	node->next = NULL;
	
	if(s->first == NULL){
		//链表为空
		s->first = node;
		return;
	}
	else{
//如何找到最后一个结点（链表中一定有结点）
	Node *cur = s->first;
	while(cur->next!=NULL){
		cur = cur->next
	}
	cur->next = node;
}
}


//头删

void SListPopFront(SList *s){
	assert(s!=NULL);            //不能没有链表
	assert(s->first !=NULL);    //不能没有节点

Node *next = s->first->next;
free(s->first);
s->first=next;
}
//尾删
void SListPopBack(SList *s){
	assert(s!=NULL);            //不能没有链表
	assert(s->first !=NULL);    //不能没有节点
	if(s->first->next == NULL)
	{   //链表中只有一个节点
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












