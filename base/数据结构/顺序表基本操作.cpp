#include<bits/stdc++.h>
using namespace std;
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

void SeqListPushBack(SeqList *pSeqList,SLDataType value){//β��
	pSeqList->array[pSeqList->size] = value;
	pSeqList->size++;
}
void SeqListPushFront(SeqList *qSeqlist,SLDataType value){//ͷ��
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
