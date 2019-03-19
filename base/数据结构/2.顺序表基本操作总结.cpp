顺序表一般可以分为：

1.静态顺序表：使用定常数组存储

//静态顺序表，固定大小
//typedef struct SeqList{
//int array[100];
//int size; //有效数据个数（也可以表示下一个可用位置的下标）
//}SeqList;

2.动态顺序表：使用动态开辟的数组存储

//动态顺序表（程序运行期间可以控制容量的大小）
typedef int SLDataType? //方便类型修改

typedef struct SeqList{
	SLDataType *array; 	 //指向堆空间，存放数据
	int capacity;
	int size; 			 //有效数据个数
}SeqList;

顺序表的基本操作：

创建、销毁、插入、删除、修改、查找

1.首先是顺序表的创建，用malloc 申请动态内存空间,要注意的是判断变量的地址是否为空，为空的话就无法进行操作了

void SeqListInit(SeqList *pSeqList){
	//变量的地址不为空，所以首先在这里判空
	assert(pSeqList!=NULL);
	//判空用assert或者if(pSeqList!=NULL)
	//assert的话直接断言掉不要空值传入，if的话另外else处理

	pSeqList->capacity = 10;
	pSeqList->array = (int *)malloc(sizeof(SLDataType)*pSeqList->capacity);
	pSeqList->size = 0;
}

2.顺序表的销毁

	还是简单的判空，销毁的话也不用删除所有元素，直接将内存释放掉，size，capacity置为0就好。我们要知道的是每块内存都或多或少的存储着数据，我们写入时直接可以覆盖，释放内存时也就不用一个个删除了

void SeqListDestory(SeqList *pSeqList){
	assert(pSeqList);
	assert(pSeqList -> array);
	free(pSeqList -> array);//先释放掉空间
	pSeqList->array = NULL;
	pSeqList->capacity = 0;
	pSeqList->size = 0;
}
3.尾插

顾名思义，就是从顺序表的末尾进行插入，只要将size加一再插入就好。这里的时间复杂度为O(1)。

//尾插    复杂度O(1)
void SeqListPushBack(SeqList *pSeqList,SLDataType value){
	pSeqList->array[pSeqList->size] = value;    //后面的直接给值就好
	pSeqList->size++;
}
4.头插

先将数据从后往前全部向后移一位，然后插到第一个的位置上。由于我们用了一个循环，所以它的复杂度为O(n)。

//头插      O(n)
void SeqListPushFront(SeqList *qSeqlist,SLDataType value){
		for(int i=pSeqList->size;i>=1;i--){
		//遍历一遍，都向后移
			pSeqList->array[i] = pSeqList->array[i-1];
		}
		pSeqList->array[0] = value;         //遍历完之后将值传给第一个
		pSeqList->size++;
}
5.中间插入

	大体是需要将pos后面的元素一次向后移动一位，再插入进来。但循环的开始和结束分为两种，我们在这里分两种情况，相当于给和拿。

	那么就要说到两种位置的概念，一种是当前数据所在的坐标，一种是数据将要转移到的坐标

	第一种从当前数据的坐标开始转移，我画了图应该可以理解，先把最后一个元素移动到下一个位置，再依次循环，那么循环就是从size-1开始到pos结束



void SeqListInsert(SeqList *pSeqList,int pos,SLDataType value);
{
	for(int i=pSeqList->size-1;i>=pos;i--)
	//注意循环的开始和结束
	{
		pSeqList->array[i+1] = pSeqList->array[i];      //
	}
	pSeqList->array[pos] = value;
	pSeqList->size++;
}
	第二种是把前一个坐标的值替换到当前位置

void SeqListInsert(SeqList *pSeqList,int pos,SLDataType value);
{
	for(int i=pSeqList->size;i>=pos+1;i--)
	//注意循环的开始和结束
	{
		pSeqList->array[i] = pSeqList->array[i-1];      //
	}
	pSeqList->array[pos] = value;
	pSeqList->size++;
}
写的时候可以观察循环的次数和要移动的数据个数是否相同，不相同则错误

6.尾删

//删除    直接size-1
void SeqListPopBack(SeqList *pSeqList)
{
	assert(pSeqList->size > 0);
	pSeqList->szie--;
}
7.头删

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
8.根据位置删除

//根据位置做删除  O(n)
void SeqListErase(SeqList *pSeqList，int pos)
{
	for(int i=pos+1;i<=pSeqList->size-1;i++)

	{
		pSeqList->array[i-1]=pSeqList->array[i];
	}
	pSeqList->size--;
}
9.查找

int SeqListSearch(const SeqList *ps,SLDataType value){
		for(int i=0;i<ps->size;i++)
		{
			if(ps->array[i]==value)
			{
				return i;
			}
		}
}
10.修改

void SeqListModify(SeqList *ps,SLDataType value)
{
	assert(pos >=0 &&pos < ps->size);
	ps->array[pos] = value;
}
11.扩容

扩容的时候一定是容量已满的情况，所以我们要有三个步骤：

1)将数据转移到新申请的内存中

2)旧空间释放

3)容量改变

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


