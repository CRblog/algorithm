�����
    �߼���  ��ȫ������
    �洢��  ���飨˳��洢��
    ���ã�  ����ֵ�������ȼ����У�
    
������
    1.���µ���*  �����ѣ�ɾ����
    2.����
    3.���ϵ���      �����룩
�ѵ�Ӧ�ã�
    1.����  ������
    2.
��С�ѣ�
root->val <=child->val
���ѣ�
root->val >= child->val;

1.Ҫ����[root]���ڵĽ��
    ǰ�᣺[root]�����������Ѿ�����ѵ�����
1.5���[root]���ڵĽ���Ѿ���Ҷ�ӽ�㣬��������
2.�ҵ����Һ�������С��һ��[min]
3. if array[root] <= array[min]
        ��������
	else
		Swap(&array[root],&array[min]);//��root�������ӽڵ����Сֵ�Ե�
		[min] = [root]

void AdjustDown(int array[],int size,int root){
	//�ж�root�Ƿ���Ҷ�ӽ��
	//��Ϊ������ȫ������������û������һ��û���Һ��ӣ�
	//����˳��洢���ҵ����ӵ��±꣬������ӵ��±�Խ���ˣ���û������

	while(1){
	int left = 2 * root + 1;
	if(left >= size){
		return ;//��Ҷ�ӽڵ�
	}
	//�ҵ����Һ�������С��һ��
	//����һ��������,�ж��Ƿ����Һ���
	int right = 2*root+2;
	int min;
	if(right<size&&array[right]<array[left]){
		min = right;
	}
	//�Ƚ�
	if(array[root]<=array[min]){
		return;
	}
	//����ֵ
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
//������ O(n)
void CreateHeap(int array[],int size){
	for(int i = (size-2)/2;i>=0;i--){
		AdjustDown(array,size,i);
	}
}
typedef struct Heap{
	int array[100];
	int size;
}Heap;

//��ʼ��
void HeapInit(Heap *heap,int array[],int size){
	memcpy(heap->array,array,size*sizeof(int));
	heap->size = size;
	CreateHeap(heap->array,size);
}
//����
void HeapPush(Heap *heap,int val){
	heap->array[heap->size++] = val;
	AdjustUp(heap->array,heap->size-1,0);
	heap->size--;
}
//ɾ��
//1.ֻ��ɾ���Ѷ�Ԫ��
void HeapPop(Heap *heap){
	heap->array[0] = heap->array[heap->size-1];//�����һ���ѵ�һ���滻����Ȼ�����λ��
	Adjust(heap->array,heap->size-1,0);
	heap->size--;
}
//���ϵ���
//1.�Ȳ���parent
//2.�Ѿ��ǻ���
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
//���ضѶ�Ԫ��
int HeaoTop(Heap *heap){
	return heap->array[0];
}

//������
//���򣬽����
void HeapSort(int array[],int size){
	CreateHeap(array,size);
	//i��ʾ���ҳ����������ĸ���
	for(int i=0;i<size-1;i++){
		//ÿ��ѭ�������ҳ�����һ�����ŵ����
		int t = array[0];
		array[0] = array[size-i-1];
		array[size-i-1]  = t;
		//���µ��������ݹ�ģ��size-1-i
		AdjustDown(array,size-1-i,0);
	}
}

void TopK(int array[],int size,int k){
	int *heap = (int *)malloc(sizeof(int)*k);
	for(int i=0;i<k;i++)
	{
		heap[i] = array[i];
	}
	//���heap����С��
	CreateHeap(heap,k);
	for(int j=k;j<size;j++)
	{
		if(array[i]>heap[0]){
			heap[0] = array[j];
			AdjustDown(heap,k,0);
		}
	}
}
