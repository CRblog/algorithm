#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cmp(int a,int b){
	return a>b;
}//��������
int main()
{
	
	int n,temp,count;
	int a[101];
	int c[2];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);//˳������
		count=0;
		for(int i=0;i<n;i++)//����С����
		{   c[1]=0;//��ʼ��Ϊ0
			if(a[i]%2==0)
				continue;
			else{
			c[1]=a[i];    //��һ����С������
			if(n>1)
				a[i]=0;         //��С������0�������������һλ
				goto num;
				}
		}
	 num:
		sort(a,a+n,cmp);   //�Ӵ�С����
		if(c[1]==0||a[0]==0)
			{
			cout<<"-1"<<endl;  //һֱΪ0˵��û��ż��//��һ��Ϊ��˵����������
			}
		else
			{
			for(int i=0;i<n-1;i++)
			{
				cout<<a[i];//�������һ�����������
			}
			cout<<c[1]<<endl;//�������һ������
			}
	}
	return 0;
}
