#include<iostream>
using namespace std;
int Binary_Search(int a[],int n,int key)
{
	int low,high,mid;//
	low=1;   //��ʼ
	high=n;     //������
	while(low<=high)//������ǰ���ǿ�ʼ����С�ڽ�������
	{
		mid=(low+high)/2;//���м����
		if(key>a[mid])     //���Ҫ�ҵ����ֵ�����м�ֵ����ô�Ͱѿ�ʼ�㻻���м�ֵ+1
		{
			low=mid+1;
		}
		else if(key<a[mid])//���Ҫ�ҵ����ֵС���м�ֵ����ô�Ͱѽ����㻻���м�ֵ-1
		{
			high=mid-1;;
        }
		else
		{
		    return mid;//����պú��м�ֵһ������ô�ͷ���
		}

	}
	return -1;//û�ҵ��ͷ���-1
}
int main()
{
	int arr[10]={0,1,1,2,4,5,6,7,8,9};//����һ����������
	int len=sizeof(arr)/sizeof(arr[0]);//����������ĳ���
	cout<<len<<endl;
	int ans=Binary_Search(arr,len,2);
	cout<<ans<<endl;//����Ҫ���ҵ����ֵ��±�
	return 0;
}
