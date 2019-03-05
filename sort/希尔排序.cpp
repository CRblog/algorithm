#include<bits/stdc++.h>
using namespace std;

////插入排序分为三种：直接插入排序，折半插入排序，希尔排序
//所谓直接插入，就是在已排序好的序列中找出要当前数字的位置并插入
//折半插入，每次和1/2处进行比较，插入效率要高于直接插入
//希尔排序（shell）：
//    数组元素为N，对N进行操作，t=floor(n/3)+1
//    比较当前数字a[i]和a[i+t];
//    递归调用
#define N 10
void shellsort(int array[],const int start,const int end)
{
	int sign=end-start+1;//初始化划分量
	int temp = 0;
	do{
		sign=sign / 3 + 1;  //划分标志
		for(int i=start + sign;i<=end;i++)   //后面元素的第一个数开始比较
		{
			cout<<"          "<<array[i]<<" "<<array[i-sign]<<endl;
			if(array[i-sign]>array[i]){     //前面大于后面
				temp=array[i];              //temp=后面的值
				int j=i-sign;               //j=前面的序号
				do{
					array[j+sign]=array[j]; //交换前后的值
					j-=sign;
					cout<<"   "<<j<<endl; //
				}while(j>=start&&array[j]>temp);
				array[j+sign] = temp;
			}
		}
	}while(sign > 1);
}
int main()
{
	int array[N] = {1,4,2,3,5,7,6,9,8,2};
	for(int i=0;i<N;i++)
		cout<<" "<<array[i];
		cout<<endl;
	shellsort(array,0,9);
	for(int i=0;i<N;i++)
		cout<<" "<<array[i];
		cout<<endl;
	return 0;
}
