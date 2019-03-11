#include<bits/stdc++.h>
using namespace std;
//
//1.时间复杂度      算法执行时间
//O(N^2)
//常见时间复杂度：
O(1)
O(log(n))
O(n)
O(nlog(n))
O(n^2)
O(2^n)
O(n!)
//二分查找，时间复杂度为 log(n)
BinarySearch(int array[],int size,int value){
	int start=0;    //左边的下标
	int end=size-1; //右边的下标

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
//2.空间复杂度      算法耗费“内存”大小
常见：O(1)
	  O(n)
	  
