#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int a[100];
void quicksort(int left, int right)
{
	int pos, i, j,t;
	if (left > right)
		return;
	pos = a[left];  //刚开始将最左边的值确定为标准，大于它的放在右边，小于的放在左边
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= pos&& i<j){   //如果左边的大于标志值，则一直往前寻找，知道寻找到了一个小于标志值的位置停下来
			j--;
		}
		while (a[i] <= pos&& i<j){  //然后左边开始找，找到一个大于标志值的，就停下来，准备交换值
			i++;
		}
		if (i<j){    //这里的判断条件是因为如果本次循环没有找到的话i就会和j相同，这样的话就不需要交换位置
            //如果需要交换，就进入循环，交换值
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//现在我们定的标志位是左边的，所以我们得把标志的和i现在指向的点交换，
	//如果是和j交换，肯定会把标志右边的值交换过来
	a[left] = a[i];   //这里是需要将标志的值放在两个区的中间，
	a[i] = pos;
	quicksort(left, i - 1);  //对左区进行递归排序
	quicksort(i + 1, right); //对右区进行递归排序
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
			cin >> a[i];
		}
	quicksort(1,n);
	for (int i = 1; i<n; i++)
	{
		cout << a[i]<<" ";
	}
	cout<<a[n]<< endl;
	system("pause");
	return 0;
}

