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
