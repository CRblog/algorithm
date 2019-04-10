二叉堆
    逻辑上  完全二叉树
    存储上  数组（顺序存储）
    作用：  找最值，（优先级队列）
    
操作：
    1.向下调整*  （建堆，删除）
    2.建堆
    3.向上调整      （插入）
堆的应用：
    1.排序  堆排序
    2.
最小堆：
root->val <=child->val
最大堆：
root->val >= child->val;

1.要调整[root]所在的结点
    前提：[root]的左右子树已经满足堆的性质
1.5如果[root]所在的结点已经是叶子结点，调整结束
2.找到左右孩子中最小的一个[min]
3. if array[root] <= array[min]
        调整结束
	else
		Swap(&array[root],&array[min]);//将root和两个子节点的最小值对调
		[min] = [root]

void AdjustDown(int array[],int size,int root){
	//判断root是否是叶子结点
	//因为堆是完全二叉树，所以没有左孩子一定没有右孩子，
	//堆是顺序存储，找到左孩子的下标，如果左孩子的下标越界了，则没有左孩子

	while(1){
	int left = 2 * root + 1;
	if(left >= size){
		return ;//是叶子节点
	}
	//找到左右孩子中最小的一个
	//这里一定有左孩子,判断是否有右孩子
	int right = 2*root+2;
	int min;
	if(right<size&&array[right]<array[left]){
		min = right;
	}
	//比较
	if(array[root]<=array[min]){
		return;
	}
	//交换值
	int t = array[root];
	array[root] = array[min];
	array[min] = t;
	
	root = min;
	}
}
void PrintArray(int array[],int size){
	for(int i=0;i<size;i++)
	{
		printf("%d",array[i]);
	}
	printf("\n");
}
//建立堆 O(n)
void CreateHeap(int array[],int size){
	for(int i = (size-2)/2;i>=0;i--){
		AdjustDown(array,size,i);
	}
}
typedef struct Heap{
	int array[100];
	int size;
}Heap;

//初始化
void HeapInit(Heap *heap,int array[],int size){
	memcpy(heap->array,array,size*sizeof(int));
	heap->size = size;
	CreateHeap(heap->array,size);
}
//插入
void HeapPush(Heap *heap,int val){
	heap->array[heap->size++] = val;
	AdjustUp(heap->array,heap->size-1,0);
	heap->size--;
}
//删除
//1.只能删除堆顶元素
void HeapPop(Heap *heap){
	heap->array[0] = heap->array[heap->size-1];//用最后一个把第一个替换掉，然后调整位置
	Adjust(heap->array,heap->size-1,0);
	heap->size--;
}
//向上调整
//1.比不过parent
//2.已经登基了
void AdjustUp(int array[],int size,int child){
	while(child!=0){
		if(child == 0){
			return ;
		}
		int parent = (child-1)/2;
		if(array[parent]<array[child]){
			return;
		}
		int t = array[parent];
		array[parent] = array[child];
		array[child] = t;
		child = parent;
	}
}
//返回堆顶元素
int HeaoTop(Heap *heap){
	return heap->array[0];
}

//堆排序
//升序，建大堆
void HeapSort(int array[],int size){
	CreateHeap(array,size);
	//i表示被找出的最大的数的个数
	for(int i=0;i<size-1;i++){
		//每次循环，会找出最大的一个数放到最后
		int t = array[0];
		array[0] = array[size-i-1];
		array[size-i-1]  = t;
		//向下调整，数据规模是size-1-i
		AdjustDown(array,size-1-i,0);
	}
}

void TopK(int array[],int size,int k){
	int *heap = (int *)malloc(sizeof(int)*k);
	for(int i=0;i<k;i++)
	{
		heap[i] = array[i];
	}
	//针对heap，建小堆
	CreateHeap(heap,k);
	for(int j=k;j<size;j++)
	{
		if(array[i]>heap[0]){
			heap[0] = array[j];
			AdjustDown(heap,k,0);
		}
	}
}
