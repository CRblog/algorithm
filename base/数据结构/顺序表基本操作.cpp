#include<bits/stdc++.h>
using namespace std;
尾插  O(1)      平均O(1)
尾插  O(1)

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
//尾插O(1)
void SeqListPushBack(SeqList *pSeqList,SLDataType value){
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}
//头插O(n)
void SeqListPushFront(SeqList *qSeqlist,SLDataType value){
		for(int i=pSeqList->size;i>=1;i--){
			pSeqList->array[i] = pSeqList->array[i-1];
		}
		pSeqList->array[0] = value;
		pSeqList->size++;
}
//中间插入,两种方式，size到pos+1  或者size-1到pos 复杂度O(n)
void SeqListInsert(Seqlist *s,int pos,DT v);
{
	for(int i=pSeqList->size;i>=pos+1;i--)
	{
		pSeqList->array[i] = pSeqList->array[i-1];
	}
	pSeqList->array[pos] = v;
	pSeqList->size++;
}
//删除    直接size-1
void SeqListPopBack(SeqList *ps)
{
	assert(ps->size > 0);
	ps->szie--;
}
//头删  O(n)  0 -> size-2或者1 -> size-1
void SeqListHeadBack(SeqList *pSeqList)
{
	assert(pSeqList->size>0);
	for(int i=0;i<=pSeqList->size-2;i++)
	{
		pSeqList->array[i]=pSeqList->array[i+1];
	}
	pSeqList->size--;
}
//根据位置做删除  O(n)
void SeqListErase()
{
	for(int i=pos+1;i<=ps->size-1;i++)
	
	{
		ps->array[i-1]=ps->array[i];
	}
	ps->size--;
}
//查找

int SeqListSearch(const SeqList *ps,SLDataType value){
		for(int i=0;i<ps->size;i++)
		{
			if(ps->array[i]==value)
			{
				return i;
			}
		}
}
//修改
void SeqListModify(SeqList *ps,SLDataType value)
{
	assert(pos >=0 &&pos < ps->size);
	ps->array[pos] = value;
}
//假如插入时容量已满，  扩容
1)将数据转移到新空间
2)旧空间释放
3)容量改变
//通常来说，扩容大小是原来的两倍



static是改变了函数的链接属性  从外部链接属性 -> 内部链接属性
static void CheckCapacity()
{
	if(ps->size < ps->capacity)
	{
		return;
	}
	int newCapacity = ps->capacity * 2;
	SLDataType * newArray
		= (SLDataType *)malloc(sizeof(SLDataType)* newCapacity);
	assert(newArray);
	for(int i=0;i < ps->size;i++)
	{
		ps->newArray[i]=ps->array[i];
	}
}
void SeqListRemove(SeqList *ps,SLDataType value)
{
	
}
void SeqListRemoveAll(SeqList *ps,SLDataType value)
{   //find一个存一个
	int i,j;
	for(i=0,j=0;i<ps->size;i++){
		
	}
}
//二分查找
int main()
{
	return 0;
}
