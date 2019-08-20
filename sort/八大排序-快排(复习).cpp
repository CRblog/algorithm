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
	pos = a[left];  //�տ�ʼ������ߵ�ֵȷ��Ϊ��׼���������ķ����ұߣ�С�ڵķ������
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= pos&& i<j){   //�����ߵĴ��ڱ�־ֵ����һֱ��ǰѰ�ң�֪��Ѱ�ҵ���һ��С�ڱ�־ֵ��λ��ͣ����
			j--;
		}
		while (a[i] <= pos&& i<j){  //Ȼ����߿�ʼ�ң��ҵ�һ�����ڱ�־ֵ�ģ���ͣ������׼������ֵ
			i++;
		}
		if (i<j){    //������ж���������Ϊ�������ѭ��û���ҵ��Ļ�i�ͻ��j��ͬ�������Ļ��Ͳ���Ҫ����λ��
            //�����Ҫ�������ͽ���ѭ��������ֵ
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	//�������Ƕ��ı�־λ����ߵģ��������ǵðѱ�־�ĺ�i����ָ��ĵ㽻����
	//����Ǻ�j�������϶���ѱ�־�ұߵ�ֵ��������
	a[left] = a[i];   //��������Ҫ����־��ֵ�������������м䣬
	a[i] = pos;
	quicksort(left, i - 1);  //���������еݹ�����
	quicksort(i + 1, right); //���������еݹ�����
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

