#include<bits/stdc++.h>
using namespace std;
//��������
//1.����Ҫ����һ����׼����������Ϊ�ȽϵĻ���
//2.����һ��left,һ��right
//3.����ұߵĴ��ڻ�������ߵ�С�ڻ������ұߵĴ�����ߵģ�������������������ٰѻ����ŵ��м�
//�γ��������С���ұߴ�ľ���
//4.������ұ���������ٷֱ��������Ĳ������ݹ飩
//5.���������


//��ð�������Ӷȸ��ͣ�����ʱ�����
int a[101],n;
void quicksort(int left,int right){//����

	int i,j,t,temp;
	if(left > right)
		return ;
		temp = a[left];//����һ����׼
		i = left;
		j = right;
		while(i != j){  //
			while(a[j] >= temp && i<j)
			//����ұߵ������ڱ�׼���������ұߵ���������ߵ���
				j--;//���������ж�ǰһ����
			while(a[i] <= temp && i<j)
			//�����ߵ���С�ڱ�׼���������ұߵ�������ߵ�����
				i++;//������������һ���������ж�
			if(i<j)//�����������������е�λ��
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
		//����׼�������м�
		a[left] = a[i];
		a[i] = temp;//������һ����׼��
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
