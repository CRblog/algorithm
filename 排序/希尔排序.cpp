#include<bits/stdc++.h>
using namespace std;

////���������Ϊ���֣�ֱ�Ӳ��������۰��������ϣ������
//��νֱ�Ӳ��룬������������õ��������ҳ�Ҫ��ǰ���ֵ�λ�ò�����
//�۰���룬ÿ�κ�1/2�����бȽϣ�����Ч��Ҫ����ֱ�Ӳ���
//ϣ������shell����
//    ����Ԫ��ΪN����N���в�����t=floor(n/3)+1
//    �Ƚϵ�ǰ����a[i]��a[i+t];
//    �ݹ����
#define N 10
void shellsort(int array[],const int start,const int end)
{
	int sign=end-start+1;//��ʼ��������
	int temp = 0;
	do{
		sign=sign / 3 + 1;  //���ֱ�־
		for(int i=start + sign;i<=end;i++)   //����Ԫ�صĵ�һ������ʼ�Ƚ�
		{
			cout<<"          "<<array[i]<<" "<<array[i-sign]<<endl;
			if(array[i-sign]>array[i]){     //ǰ����ں���
				temp=array[i];              //temp=�����ֵ
				int j=i-sign;               //j=ǰ������
				do{
					array[j+sign]=array[j]; //����ǰ���ֵ
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
