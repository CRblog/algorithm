//��������
void insertSort(int* array) {
  int temp;
  for (int i = 1; i < length; i++) {
    for (int j = 0; j < i; j++) {
      if (array[j] > array[i]) {
        temp = array[i];
        for (int k = i - 1; k >= j; k--) {
          array[k + 1] = array[k];
        }
        array[j] = temp;
      }
    }
  }
}
//ð������
void bubbleSort(int* array) {
  for (int i = 0; i < length - 1; i++) {
    for (int j = 0; j < length - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        array[j] ^= array[j + 1];
        array[j + 1] ^= array[j];
        array[j] ^= array[j + 1];
      }
    }
  }
}


//ѡ������
void selectionSort(int* array) {
  for (int i = 0; i < length; i++) {
    int j = i;
    for (int k = i + 1; k < length; k++) {
      if (array[k] < array[j]) {
        j = k;
      }
    }
    if (j != i) {
      array[j] ^= array[i];
      array[i] ^= array[j];
      array[j] ^= array[i];
    }
  }
}


//ϣ������
void shellsort(int array[],const int start,const int end)
{
	int sign=end-start+1;//��ʼ��������
	int temp = 0;
	do{
		sign=sign / 3 + 1;  //���ֱ�־
		for(int i=start + sign;i<=end;i++)   //����Ԫ�صĵ�һ������ʼ�Ƚ�
		{
			cout<<"          "<<array[i]<<" "<<array[i-sign]<<endl;
			if(array[i-sign]>array[i]){     //ǰ����ں���
				temp=array[i];              //temp=�����ֵ
				int j=i-sign;               //j=ǰ������
				do{
					array[j+sign]=array[j]; //����ǰ���ֵ
					j-=sign;
					cout<<"   "<<j<<endl; //
				}while(j>=start&&array[j]>temp);
				array[j+sign] = temp;
			}
		}
	}while(sign > 1);
}
//����
//1.hover��
int Parition_1(int array[],int left,int right){
	int begin = left;
	int end = right;
	while(begin < end){
		while(begin < end && array[begin]<=array[right]){
			begin++;
		}
		while(begin < end && array[end] >= array[right]){
			end--;
		}
		Swap(array + begin,array + end);
	}
	Swap(array + begin,array + right);
	return begin;
}
//2.�ڿӷ�
int Partition2(int array[],int left,int right){
	int begin = left,end = right;
	int pivot = array[right];
	
	while(begin < end){
		while(begin < end && array[begin] <= pivot){
			begin++;
		}
		array[end] = array[begin];
		while(begin < end && array[end] >= pivot){
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = pivot;
	return begin;
}
//ǰ���±귨
int Partition3(int array[],int left,int right)
{
	int d =left;
	for(int i = left;i<right;i++)
	{
		if(array[i] < array[right]){
			Swap(array + d,array + i);
			d++;
		}
	}
	Swap(array + d,array+right);
	return d;
}

//�鲢����
void mergeSort(int* array, int first, int end) {
  if (first < end) {
    int mid = (first + end) / 2;
    mergeSort(array, first, mid);
    mergeSort(array, mid + 1, end);
    merge(array, first, mid, end);
  }
}
void merge(int* array, int first, int mid, int end) {
  int n1 = mid - first + 1;
  int n2 = end - mid;
  int* leftgroup = (int*)malloc(sizeof(int) * n1);
  int* rightgroup = (int*)malloc(sizeof(int) * n2);
  for (int i = 0; i < n1; i++) {
    leftgroup[i] = array[first + i];
  }
  for (int i = 0; i < n2; i++) {
    rightgroup[i] = array[mid + i + 1];
  }
  int i = 0, j = 0, k = first;
  while (i < n1 && j < n2) {
    if (leftgroup[i] < rightgroup[j]) {
      array[k++] = leftgroup[i++];
    } else {
      array[k++] = rightgroup[j++];
    }
  }
  while (i < n1) {
    array[k++] = leftgroup[i++];
  }
  while (j < n2) {
    array[k++] = rightgroup[j++];
  }
  free(leftgroup);
  free(rightgroup);
}
//������,���
void Creatheap(int array[], int size)
{
    for (int i = (size - 2) / 2; i >= 0; i--)
    {
        AdjustDown(array, size, i);
    }
}
void HeapSort(int array[],int size)
{
	Creatheap(array,size);
	for (int ?i = 0; i < size-1; i++)
	{
		Swap(&array[0], array + size - 1 - i);
		//���µ������Ѷѽṹ������ȷ״̬
		AdjustDown(array, size-1- i,0);
	}

}
void AdjustDown(int array,int size,int parent){
	int child = parent*2+1;   //����
      while(parent<size)
      {
		if(child+1<size&&array[child+1]<array[child])
        //��һ���������ж��Һ��Ӵ��ڲ����Һ���С������
		{
			child += 1;  //֮ǰchild�����ӣ���1�����������Ļ�child �ʹ�������Һ���
		}
		if(array[child] < array[parent])   //������Ӹ�С����ô�ͽ������Ӻ�˫�ף�������һ���ж�
		{
			Swap(&array[child],&array[parent]);
			parent = child;
			child = parent * 2+1;
		}
		else
			return ;
      }
}
