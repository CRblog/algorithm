#include<bits/stdc++.h>
using namespace std;
//
//1.ʱ�临�Ӷ�      �㷨ִ��ʱ��
//O(N^2)
//����ʱ�临�Ӷȣ�
O(1)
O(log(n))
O(n)
O(nlog(n))
O(n^2)
O(2^n)
O(n!)
//���ֲ��ң�ʱ�临�Ӷ�Ϊ log(n)
BinarySearch(int array[],int size,int value){
	int start=0;    //��ߵ��±�
	int end=size-1; //�ұߵ��±�

		while(start<=end)
		{
			int key=(start+end)/2;
			if(value<key)
			{
				end=key-1;
			}
			else if(value>key)
			{
				start=key+1;
			}
			else
				return key;
		}
		return 1;
}

int main()
{
	int arr[11]={0,1,2,3,4,5,6,7,8,9};
	int size=sizeof(arr)/sizeof(arr[0]);
	BinarySearch(arr,size,7);
}


//
//
//2.�ռ临�Ӷ�      �㷨�ķѡ��ڴ桱��С
������O(1)
	  O(n)
	  
