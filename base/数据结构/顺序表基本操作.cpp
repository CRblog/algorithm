#include<bits/stdc++.h>
using namespace std;
β��  O(1)      ƽ��O(1)
β��  O(1)

void SqeListInit(SeqList *pSeqList){
//����
	//�������ݽ�������һ�������ĵ�ַ
	//�����ĵ�ַ�϶�����NULL
	assert(pSeqList != NULL)//�п�

	//���ٿռ�
	//����������size
	pSeqList->capacity = 10;
	pSeqList->array
		=(int *)malloc(sizeof(SLDataType)* pSeqList->capacity);
		//�����ڴ�
	pSeqList->size = 0;
}
void SeqListDestory(SeqList *pSeqList){
//�ݻ�
	assert(pSeqList);
	assert(pSeqList->array);
	free(pSeqList->array);
	
	pSeqList->array = NULL;
	pSeqList->capacity = 0;
	pSeqList->size = 0;
}
//β��O(1)
void SeqListPushBack(SeqList *pSeqList,SLDataType value){
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}
//ͷ��O(n)
void SeqListPushFront(SeqList *qSeqlist,SLDataType value){
		for(int i=pSeqList->size;i>=1;i--){
			pSeqList->array[i] = pSeqList->array[i-1];
		}
		pSeqList->array[0] = value;
		pSeqList->size++;
}
//�м����,���ַ�ʽ��size��pos+1  ����size-1��pos ���Ӷ�O(n)
void SeqListInsert(Seqlist *s,int pos,DT v);
{
	for(int i=pSeqList->size;i>=pos+1;i--)
	{
		pSeqList->array[i] = pSeqList->array[i-1];
	}
	pSeqList->array[pos] = v;
	pSeqList->size++;
}
//ɾ��    ֱ��size-1
void SeqListPopBack(SeqList *ps)
{
	assert(ps->size > 0);
	ps->szie--;
}
//ͷɾ  O(n)  0 -> size-2����1 -> size-1
void SeqListHeadBack(SeqList *pSeqList)
{
	assert(pSeqList->size>0);
	for(int i=0;i<=pSeqList->size-2;i++)
	{
		pSeqList->array[i]=pSeqList->array[i+1];
	}
	pSeqList->size--;
}
//����λ����ɾ��  O(n)
void SeqListErase()
{
	for(int i=pos+1;i<=ps->size-1;i++)
	
	{
		ps->array[i-1]=ps->array[i];
	}
	ps->size--;
}
//����

int SeqListSearch(const SeqList *ps,SLDataType value){
		for(int i=0;i<ps->size;i++)
		{
			if(ps->array[i]==value)
			{
				return i;
			}
		}
}
//�޸�
void SeqListModify(SeqList *ps,SLDataType value)
{
	assert(pos >=0 &&pos < ps->size);
	ps->array[pos] = value;
}
//�������ʱ����������  ����
1)������ת�Ƶ��¿ռ�
2)�ɿռ��ͷ�
3)�����ı�
//ͨ����˵�����ݴ�С��ԭ��������



static�Ǹı��˺�������������  ���ⲿ�������� -> �ڲ���������
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
{   //findһ����һ��
	int i,j;
	for(i=0,j=0;i<ps->size;i++){
		
	}
}
//���ֲ���
int main()
{
	return 0;
}
