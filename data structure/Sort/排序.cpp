#include<bits/stdc++.h>
using namespace std;
////堆排序
//void HeapSort(int array[],int size)
//{
//	CreateHeap(array,size);
//	for(int i=0;i<size-1;i++)
//	{
//		int t = array[0];
//		array[0] = array[size - i -1];
//		array[size -i -1] = t;
//		AdjustDown(array,size -i -1,0);//除去最后排序好的
//	}
//}
//插入排序
//直接插入排序
void InsertSort(int array[],int size)
{
	for(int i=1;i<size;i++)
	{
		for(int j = i-1;j>=0;j--)
		{  
			if(array[i]<array[j])
			{
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			else
				break;
		}
	}
}
//sort
//选择排序
int main()
{
	int array[10] = {1,2,4,3,4,5,6,7,8,9};
	int size = sizeof(array)/sizeof(array[0]);
	InsertSort(array,size);
	for(int i=0;i<size;i++)
	{
		cout<<array[i];
	}
	cout<<endl;
	return 0;
}
