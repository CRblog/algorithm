//#include<bits/stdc++.h>
//using namespace std;
//
//int a[101];
//
//void quick_sort(int left, int right)
//{
//	int pos, i, j, temp;
//	if (left > right)    //����������ֱ���˳�
//		return;
//	pos = a[left];  //����������һ����־λ�ã�������ѡ����������
//	i = left;
//	j = right;
//	while (i != j)  //�����ƶ���һ��Ż�ֹͣ
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
//	//�������Ƕ��ı�־λ����ߵģ��������ǵðѱ�־�ĺ�i����ָ��ĵ㽻����
//	//����Ǻ�j�������϶���ѱ�־�ұߵ�ֵ��������
//	a[left] = a[i];
//	a[i] = pos;
//	quick_sort(left, i - 1);
//	quick_sort(i + 1, right);
//}
//
//int main()
//{
//	int n;  //�����е�Ԫ�ظ���
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
////���������˼����Ƿ�Ϊ������
////������ź���ģ�ÿ���ұ�ȡһ��ֵ�������Ѱ�ҵ�һ��С���������֣��ҵ���֮��ͺ�������ֵ���һ��λ�ý���λ��
////������ѭ��Ѱ�ҵ�ʱ��һֱ�����ڴ�����ֵ������Ų��
//void insert_sort(int* a,int n)
//{
//	int i, j,temp;
//	for (i = 1; i < n; ++i)    
//	{
//		temp = a[i];
//		j = i - 1;
//		while (j >= 0 && temp < a[j])   //���Ҫ�����ֵС��a[j],��һֱ��ǰ�ߣ�����a[j]����˳��Ų��
// 		{
//			a[j + 1] = a[j];   
//			j--;
//		}
//		a[j+1] = temp;   //����λ��
//	}
//}
//
//int main()
//{
//	int n;  //�����е�Ԫ�ظ���
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
//		//���������ҵ���δ����������Сֵ
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
//	int n;  //�����е�Ԫ�ظ���
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
////ϣ�������˼����ǽ������Ϊ����飬��ÿ����в�������һ����������֮���������Ϊn/2
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
//	int n;  //�����е�Ԫ�ظ���
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
