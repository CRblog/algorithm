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

void CreateHeap(int array[],int size){
	for(int i = (size-2)/2;i>=0;i--){
		AdjustDown(array,size,i);
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
