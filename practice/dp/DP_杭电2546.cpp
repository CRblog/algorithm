#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
/*
�����ó�5Ԫ����������ֵ���Ǽ�����
   m-5
Ȼ����MΪ�����������������⣬д��״̬���̣��������ֵdp[m-5]
�����Ǯ����ȥ�ܼ�ֵ������װ�µļ�ֵ+������Ʒ����ֵ��
*/
int main()
{
	int n,m,sum;
	int a[1003];
    int dp[1003];
    while(cin>>n&&n!=0)
    {
    	memset(dp,0,sizeof(dp));
		//�����ʼ��
    	for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		//˳������Ŀ�����ҳ�����ֵ����Ʒ
		cin>>m;
		if(m<5)
		{
			cout<<m<<endl;
			//С��5Ԫʱ�޷�������Ȼ���ǵ�ǰֵ
		}
		else
		{

			for(int i=0;i<n-1;i++)
			{
				for(int j=m-5;j>=a[i];j--)
				{
					dp[j]=max(dp[j],dp[j-a[i]]+a[i]);//״̬����
				}
			}
			cout<<m-dp[m-5]-a[n-1]<<endl;
			//�������ܷŵ����ֵ����dp[m-5]
			//������m
			//���յ�ֵ����������ȥ�����е�ֵ��
			//�ټ�ȥ֮ǰ�����ҳ����Ǹ�����ֵ����Ʒ
	   }

	}
	return 0;
}
