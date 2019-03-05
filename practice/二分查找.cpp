#include<iostream>
using namespace std;
int Binary_Search(int a[],int n,int key)
{
	int low,high,mid;//
	low=1;   //开始
	high=n;     //结束点
	while(low<=high)//结束的前提是开始数字小于结束数字
	{
		mid=(low+high)/2;//从中间二分
		if(key>a[mid])     //如果要找的这个值大于中间值，那么就把开始点换成中间值+1
		{
			low=mid+1;
		}
		else if(key<a[mid])//如果要找的这个值小于中间值，那么就把结束点换成中间值-1
		{
			high=mid-1;;
        }
		else
		{
		    return mid;//如果刚好和中间值一样，那么就返回
		}

	}
	return -1;//没找到就返回-1
}
int main()
{
	int arr[10]={0,1,1,2,4,5,6,7,8,9};//定义一个递增数组
	int len=sizeof(arr)/sizeof(arr[0]);//这里是数组的长度
	cout<<len<<endl;
	int ans=Binary_Search(arr,len,2);
	cout<<ans<<endl;//返回要查找的数字的下标
	return 0;
}
