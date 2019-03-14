#include<bits/stdc++.h>
using namespace std;

//线性表
顺序表
链表
SeqList.h
////静态顺序表（顺序表的大小是固定的，编译期间决定的）
//typedef struct SeqList{
//	int array[100];//容量是100
//	int size;       //有效数据个数,同时也表示下一个可用位置的下标
//	
//	
//	
//}SeqList;
typedef int SLDataType;
//动态顺序表(在程序运行期间可以动态控制容量的大小)
typedef struct SeqList{
	SLDataType *array;     //指向	堆上空间，存放数据
    int capacity;   //容量
    itn size;       //有效个数
}SeqList;
//服务列表，函数列表
//创建  销毁
//增 删 查 改
三种插入方式
尾插
void SeqListPushBack(SeqList *pSeqList,SLDataType value)

头插
1.从后往前移，一共移size个数
2.空间的下标：[size,1]
  数据的下标：[size-1,0]
3.移动的过程
	array[空间] = array[数据]
void SeqListPushFront(SeqList *pSeqList,SLDataType value)
{
	for(int i=pSeqList->size;i>=1;i--)
	{
		pSeqList->array[i]=pSeqList->array[i-1]
	}
	pSeqList->array[0] = value;
	pSeqList->size++;
}
//插入
SeqList.c
void SeqListInit(SeqList *pSeqList)
{
	assert(pSeqList!=NULL)//地址不为空
	pSeqList->capacity = 10;
	pSeqList->size
}
Main.c
int main()

{
	SeqList seqlist;
	SeqListInit(&seqlist);
}

int main()
{
	return 0;
}
