//#include<bits/stdc++.h>
//using namespace std;
//
//int a[101];
//
//void quick_sort(int left, int right)
//{
//	int pos, i, j, temp;
//	if (left > right)    //不满足条件直接退出
//		return;
//	pos = a[left];  //首先我们设一个标志位置，这里我选择的是最左边
//	i = left;
//	j = right;
//	while (i != j)  //两边移动到一起才会停止
//	{
//		while (a[j] >= pos&& i < j)
//		{
//			j--;
//		}
//		while (a[i] <= pos&& i < j)
//		{
//			i++;
//		}
//		if (i < j)
//		{
//			temp = a[i];
//			a[i] = a[j];
//			a[j] = temp;
//		}
//	}
//	//现在我们定的标志位是左边的，所以我们得把标志的和i现在指向的点交换，
//	//如果是和j交换，肯定会把标志右边的值交换过来
//	a[left] = a[i];
//	a[i] = pos;
//	quick_sort(left, i - 1);
//	quick_sort(i + 1, right);
//}
//
//int main()
//{
//	int n;  //数组中的元素个数
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i];
//	}
//	quick_sort(0, n-1);
//	for (int i = 0; i < n-1; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << a[n-1] << endl;
//	system("pause");
//	return 0;
//}

//
//#include<bits/stdc++.h>
//using namespace std;
//int a[101];
////插入排序的思想就是分为两个区
////左边是排好序的，每次右边取一个值来在左边寻找第一个小于它的数字，找到了之后就和这个数字的下一个位置交换位置
////另外在循环寻找的时候一直将大于待排序值的往后挪动
//void insert_sort(int* a,int n)
//{
//	int i, j,temp;
//	for (i = 1; i < n; ++i)    
//	{
//		temp = a[i];
//		j = i - 1;
//		while (j >= 0 && temp < a[j])   //如果要排序的值小于a[j],就一直往前走，并将a[j]往后顺序挪动
// 		{
//			a[j + 1] = a[j];   
//			j--;
//		}
//		a[j+1] = temp;   //交换位置
//	}
//}
//
//int main()
//{
//	int n;  //数组中的元素个数
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i];
//	}
//	insert_sort(a,n);
//	for (int i = 0; i < n-1; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << a[n-1] << endl;
//	system("pause");
//	return 0;
//}
//



//#include<bits/stdc++.h>
//using namespace std;
//int a[101];

//void select_sort(int* a,int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		int temp = i;
//		for (int j = i + 1; j < n;++j)
//		{
//			if (a[j] < a[temp])
//			{
//				temp = j;
//			}
//		}
//		//现在我们找到了未排序区的最小值
//		if (i!=temp)
//		{
//			a[temp] ^= a[i];
//			a[i] ^= a[temp];
//			a[temp] ^= a[i];
//		}
//	}
//}
//
//int main()
//{
//	int n;  //数组中的元素个数
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i];
//	}
//	select_sort(a,n);
//	for (int i = 0; i < n-1; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << a[n-1] << endl;
//	system("pause");
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//int a[101];
//
////希尔排序的思想就是将数组分为多个组，对每组进行插入排序，一轮排序完了之后调整分组为n/2
//void shell_sort(int* a, int n)
//{
//	int h = n / 2 + 1;
//	while (h)
//	{
//		for (int i = h; i < n; ++i)
//		{
//			cout << a[i] << endl;
//			int temp = a[i];
//			int j = i-h;
//			while (j >= h && temp < a[j])
//			{
//				a[j+h] = a[j];
//				j-=h;
//			}
//			a[j + h] = temp;
//		}
//		h = h / 2 ;
//	}
//}
//
//int main()
//{
//	int n;  //数组中的元素个数
//	cin >> n;
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> a[i];
//	}
//	shell_sort(a, n);
//	for (int i = 0; i < n - 1; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << a[n - 1] << endl;
//	system("pause");
//	return 0;
//}


#include<bits/stdc++.h>
using namespace std;
int a[101];
void Merge(int* arr, int left, int mid, int right){
	int *temp = new int[right - left + 1];
	int i = left;
	int j = mid + 1;
	int t = 0;
	while (i <= mid && j <= right){
		temp[t++] = arr[i] > arr[j] ? arr[j++] : arr[i++];		
	}
	while (i <= mid)
	{
		temp[t++] = arr[i++];
	}
	while (j <= right)
	{
		temp[t++] = arr[j++];
	}
	for (int j = 0; j < t; ++j)
	{
		arr[left + j] = temp[j];
	}
	delete[] temp;
}
void MergeSort(int* arr, int start, int end){
	if (arr == NULL || start >= end)
		return;
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid + 1, end);
		Merge(arr, start, mid, end);
	}
	
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	MergeSort(a, 0, n-1);
	for (int i = 0; i < n-1; i++)
	{
		cout << a[i] << " ";
	}
	cout << a[n-1] << endl;
	system("pause");
	return 0;
}
