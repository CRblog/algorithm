#include<bits/stdc++.h>
using namespace std;
//快速排序
//1.首先要定义一个基准数，将他作为比较的基数
//2.定义一个left,一个right
//3.如果右边的大于基数，左边的小于基数，右边的大于左边的，把两个数交换，最后再把基数放到中间
//形成最后的左边小，右边大的局势
//4.将左边右边区域的数再分别进行上面的操作（递归）
//5.结束，输出


//比冒泡排序复杂度更低，消耗时间更少
int a[101],n;
void quicksort(int left,int right){//快排

	int i,j,t,temp;
	if(left > right)
		return ;
		temp = a[left];//定义一个标准
		i = left;
		j = right;
		while(i != j){  //
			while(a[j] >= temp && i<j)
			//如果右边的数大于标准数，并且右边的数大于左边的数
				j--;//不操作，判断前一个数
			while(a[i] <= temp && i<j)
			//如果左边的数小于标准数，并且右边的数比左边的数大
				i++;//不操作，换下一个数进行判断
			if(i<j)//交换两个数在数组中的位置
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		//将标准数放在中间
		a[left] = a[i];
		a[i] = temp;//定义下一个标准数
		quicksort(left,i-1);
		quicksort(i+1,right);
}
int main(){
	int i;
	scanf("%d",&n);
	for(i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	quicksort(1,n);
	for(i = 1;i < n; i++)
		printf("%d",a[i]);
	printf("%d\n",a[n]);
	return 0;
}
