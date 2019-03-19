˳���һ����Է�Ϊ��

1.��̬˳���ʹ�ö�������洢

//��̬˳����̶���С
//typedef struct SeqList{
//int array[100];
//int size; //��Ч���ݸ�����Ҳ���Ա�ʾ��һ������λ�õ��±꣩
//}SeqList;

2.��̬˳���ʹ�ö�̬���ٵ�����洢

//��̬˳������������ڼ���Կ��������Ĵ�С��
typedef int SLDataType? //���������޸�

typedef struct SeqList{
	SLDataType *array; 	 //ָ��ѿռ䣬�������
	int capacity;
	int size; 			 //��Ч���ݸ���
}SeqList;

˳���Ļ���������

���������١����롢ɾ�����޸ġ�����

1.������˳���Ĵ�������malloc ���붯̬�ڴ�ռ�,Ҫע������жϱ����ĵ�ַ�Ƿ�Ϊ�գ�Ϊ�յĻ����޷����в�����

void SeqListInit(SeqList *pSeqList){
	//�����ĵ�ַ��Ϊ�գ����������������п�
	assert(pSeqList!=NULL);
	//�п���assert����if(pSeqList!=NULL)
	//assert�Ļ�ֱ�Ӷ��Ե���Ҫ��ֵ���룬if�Ļ�����else����

	pSeqList->capacity = 10;
	pSeqList->array = (int *)malloc(sizeof(SLDataType)*pSeqList->capacity);
	pSeqList->size = 0;
}

2.˳��������

	���Ǽ򵥵��пգ����ٵĻ�Ҳ����ɾ������Ԫ�أ�ֱ�ӽ��ڴ��ͷŵ���size��capacity��Ϊ0�ͺá�����Ҫ֪������ÿ���ڴ涼�����ٵĴ洢�����ݣ�����д��ʱֱ�ӿ��Ը��ǣ��ͷ��ڴ�ʱҲ�Ͳ���һ����ɾ����

void SeqListDestory(SeqList *pSeqList){
	assert(pSeqList);
	assert(pSeqList -> array);
	free(pSeqList -> array);//���ͷŵ��ռ�
	pSeqList->array = NULL;
	pSeqList->capacity = 0;
	pSeqList->size = 0;
}
3.β��

����˼�壬���Ǵ�˳����ĩβ���в��룬ֻҪ��size��һ�ٲ���ͺá������ʱ�临�Ӷ�ΪO(1)��

//β��    ���Ӷ�O(1)
void SeqListPushBack(SeqList *pSeqList,SLDataType value){
	pSeqList->array[pSeqList->size] = value;    //�����ֱ�Ӹ�ֵ�ͺ�
	pSeqList->size++;
}
4.ͷ��

�Ƚ����ݴӺ���ǰȫ�������һλ��Ȼ��嵽��һ����λ���ϡ�������������һ��ѭ�����������ĸ��Ӷ�ΪO(n)��

//ͷ��      O(n)
void SeqListPushFront(SeqList *qSeqlist,SLDataType value){
		for(int i=pSeqList->size;i>=1;i--){
		//����һ�飬�������
			pSeqList->array[i] = pSeqList->array[i-1];
		}
		pSeqList->array[0] = value;         //������֮��ֵ������һ��
		pSeqList->size++;
}
5.�м����

	��������Ҫ��pos�����Ԫ��һ������ƶ�һλ���ٲ����������ѭ���Ŀ�ʼ�ͽ�����Ϊ���֣����������������������൱�ڸ����á�

	��ô��Ҫ˵������λ�õĸ��һ���ǵ�ǰ�������ڵ����꣬һ�������ݽ�Ҫת�Ƶ�������

	��һ�ִӵ�ǰ���ݵ����꿪ʼת�ƣ��һ���ͼӦ�ÿ�����⣬�Ȱ����һ��Ԫ���ƶ�����һ��λ�ã�������ѭ������ôѭ�����Ǵ�size-1��ʼ��pos����



void SeqListInsert(SeqList *pSeqList,int pos,SLDataType value);
{
	for(int i=pSeqList->size-1;i>=pos;i--)
	//ע��ѭ���Ŀ�ʼ�ͽ���
	{
		pSeqList->array[i+1] = pSeqList->array[i];      //
	}
	pSeqList->array[pos] = value;
	pSeqList->size++;
}
	�ڶ����ǰ�ǰһ�������ֵ�滻����ǰλ��

void SeqListInsert(SeqList *pSeqList,int pos,SLDataType value);
{
	for(int i=pSeqList->size;i>=pos+1;i--)
	//ע��ѭ���Ŀ�ʼ�ͽ���
	{
		pSeqList->array[i] = pSeqList->array[i-1];      //
	}
	pSeqList->array[pos] = value;
	pSeqList->size++;
}
д��ʱ����Թ۲�ѭ���Ĵ�����Ҫ�ƶ������ݸ����Ƿ���ͬ������ͬ�����

6.βɾ

//ɾ��    ֱ��size-1
void SeqListPopBack(SeqList *pSeqList)
{
	assert(pSeqList->size > 0);
	pSeqList->szie--;
}
7.ͷɾ

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
8.����λ��ɾ��

//����λ����ɾ��  O(n)
void SeqListErase(SeqList *pSeqList��int pos)
{
	for(int i=pos+1;i<=pSeqList->size-1;i++)

	{
		pSeqList->array[i-1]=pSeqList->array[i];
	}
	pSeqList->size--;
}
9.����

int SeqListSearch(const SeqList *ps,SLDataType value){
		for(int i=0;i<ps->size;i++)
		{
			if(ps->array[i]==value)
			{
				return i;
			}
		}
}
10.�޸�

void SeqListModify(SeqList *ps,SLDataType value)
{
	assert(pos >=0 &&pos < ps->size);
	ps->array[pos] = value;
}
11.����

���ݵ�ʱ��һ���������������������������Ҫ���������裺

1)������ת�Ƶ���������ڴ���

2)�ɿռ��ͷ�

3)�����ı�

static void CheckCapacity(SeqList *pSeqList)
{
	if(pSeqList->size < pSeqList->capacity)
	{
		return;
	}
	int newCapacity = pSeqList->capacity * 2;
	SLDataType * newArray
		= (SLDataType *)malloc(sizeof(SLDataType)* newCapacity);
	assert(newArray);
	for(int i=0;i < pSeqList->size;i++)
	{
		pSeqList->newArray[i]=pSeqList->array[i];
	}
}


