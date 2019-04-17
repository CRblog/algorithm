typedef int DataType;

typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
} Heap;


int Swap(DataType* pLeft,DataType* pRight)
{
	int tmp =  *pLeft;
     *pLeft = *pRight;
     *pRight = tmp;
}
void AdjustDown(int array,int size,int parent){
		int child = parent * 2+1;
		if(child+1<size&&array[child+1]<array[child])
		{
			child += 1;
		}
		if(array[child] < array[parent])
		{
			Swap(&array[child],&array[parent]);
			parent = child;
			child = parent * 2+1;
		}
		else
			return ;
}
void AdjustUp(DataType* array,int size,int child)
{
	int parent = 2*(child-1);
	while(child)
	{
	if(array[child] < array[parent])
	{
		Swap(&array[parent],&array[child]);
		child = parent;
		parent = 2*(child-1);
	}
	else
		return ;
	}
}
void CreateHeap(Heap* hp,int* array,int size);
{
	 hp->_array = (DataType*)malloc(size*sizeof(DataType));
	 if(hp->_array==NULL)
	 {
		assert(0);
	 }
	 hp->_capacity = size;
	 for(int i=0;i<size;i++)
	 {
	 	hp->_array[i] = array[i];
	 }
	 hp->_size = size;
	for(int i=(size-2)/2;i>=0;i--)
	{
		AdjustDown(hp->_array,hp->_size,i);
	}
}
void DestoryHeap(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_capacity = 0;
	hp->_size = 0;
}
void CheckCapacity(Heap* hp){
	assert(hp);
	if(hp->_size == hp->_capacity)
	{
		int newCapacity = 2*hp->_capacity;   //一般给两倍比较好
		DataType* pTemp = (DataType*)malloc(newCapacity*sizeof(DataType));
		if(pTemp == NULL)
		{
			assert(pTemp);
			return;
		}
		for(int i=0;i<hp->_size;i++)
		{
			pTemp[i] = hp->_array[i];
		}
		free(hp->_array);
		hp->_array = pTemp;
		hp->_capacity = newCapacity;
	}
}
void InsertHeap(Heap* hp,DataType data){
	//向上调整
	CheckCapacity(hp);
	hp->_size[hp->_size++] = data;//放到最后一个位置
	AdjustUp(hp->_array,hp->_size,hp->_size-1);
}
void EraseHeap(Heap* hp){
	if(EmptyHeap(hp))
		return ;
	Swap(&hp->_array[0],&hp->_array[hp->_size-1]);
	AdjustDown(hp->_array,hp->_size-1,0);
}
int sizeHeap(Heap* hp){
	assert(hp);
	return hp->_size;
}
int EmptyHeap(Heap* hp){
	assert(hp)
	return 0==hp->_size;
}
int TopHeap(Heap* hp){
	assert(hp);
	return hp->_array[0];
}

