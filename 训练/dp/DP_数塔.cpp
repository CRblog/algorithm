//DP����
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
int t,n;//ʵ������,����
int arr[101][101];
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		//cout<<"i="<<i<<":"<<endl;
		for(int j=0;j<=i;j++)
		{
			scanf("%d",&arr[i][j]);//�ö�ά�������
		}
	}
int dp[101][101]={0};
	//DP������dp����
	for(int i=0;i<n;i++)
	{
		dp[n-1][i]=arr[n-1][i];//״̬���̵ĳ�ʼ����
        //Ҫ����߲�����ֵ�������һ�п�ʼ
	}
	for(int i=n-2;i>=0;--i){
		for(int j=0;j<=i;j++){
			dp[i][j]=arr[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
			//״̬���̣���˼�ǽ���һ�еĵ�ǰ�к���һ�бȽϣ�ֵ����ĺ͵�ǰֵ���
			//��Ϊ��һ���ֵ
		}
	}
	cout<<dp[0][0]<<endl;//������ϲ��ֵ
	}
	return 0;
}

