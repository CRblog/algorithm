#include<bits/stdc++.h>
using namespace std;
void SqeListInit(SeqList *pSeqList){
//创建
	//期望传递进来的是一个变量的地址
	//变量的地址肯定不是NULL
	assert(pSeqList != NULL)//判空

	//开辟空间
	//设置容量和size
	pSeqList->capacity = 10;
	pSeqList->array
		=(int *)malloc(sizeof(SLDataType)* pSeqList->capacity);
		//开辟内存
	pSeqList->size = 0;
}
void SeqListDestory(SeqList *pSeqList){
//摧毁
	assert(pSeqList);
	assert(pSeqList->array);
	free(pSeqList->array);
	
	pSeqList->array = NULL;
	pSeqList->capacity = 0;
	pSeqList->size = 0;
}

void SeqListPushBack(SeqList *pSeqList,SLDataType value){//尾插
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}
void SeqListPushFront(SeqList *qSeqlist,SLDataType value){//头插
		for(int i=pSeqList->size;i>=1;i--){
			pSeqList->array[i] = pSeqList->array[i-1];
		}
		pSeqList->array[0] = value;
		pSeqList->size++;
}
int main()
{
	return 0;
}
