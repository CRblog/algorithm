#include<bits/stdc++.h>
using namespace std;

//���Ա�
˳���
����
SeqList.h
////��̬˳���˳���Ĵ�С�ǹ̶��ģ������ڼ�����ģ�
//typedef struct SeqList{
//	int array[100];//������100
//	int size;       //��Ч���ݸ���,ͬʱҲ��ʾ��һ������λ�õ��±�
//	
//	
//	
//}SeqList;
typedef int SLDataType;
//��̬˳���(�ڳ��������ڼ���Զ�̬���������Ĵ�С)
typedef struct SeqList{
	SLDataType *array;     //ָ��	���Ͽռ䣬�������
    int capacity;   //����
    itn size;       //��Ч����
}SeqList;
//�����б������б�
//����  ����
//�� ɾ �� ��
���ֲ��뷽ʽ
β��
void SeqListPushBack(SeqList *pSeqList,SLDataType value)

ͷ��
1.�Ӻ���ǰ�ƣ�һ����size����
2.�ռ���±꣺[size,1]
  ���ݵ��±꣺[size-1,0]
3.�ƶ��Ĺ���
	array[�ռ�] = array[����]
void SeqListPushFront(SeqList *pSeqList,SLDataType value)
{
	for(int i=pSeqList->size;i>=1;i--)
	{
		pSeqList->array[i]=pSeqList->array[i-1]
	}
	pSeqList->array[0] = value;
	pSeqList->size++;
}
//����
SeqList.c
void SeqListInit(SeqList *pSeqList)
{
	assert(pSeqList!=NULL)//��ַ��Ϊ��
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
