#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100001];
int dp[100001];
//���͵Ķ�̬�滮
//��һ�ο�������������Ϊ������дn��Ȼ��3 -1 2 1�����������Ϊ3��
//������Ϊ��Ҫ����������������Ҳ����dp��������������ע����ģ�
//���˲ŷ��ֺ����⿴���ˣ�ֱ��д״̬���̾����ˣ������жϴ�С
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int maxn = dp[0] = a[0];
		for(int i=1;i<n;i++)
		{
			dp[i] = max(a[i],a[i]+dp[i-1]);
            //			if(dp[i]<dp[i-1])
//			{
//				dp[i] = 0;
//			}
			maxn = max(maxn,dp[i]);
		}
		cout<<maxn<<endl;
	}
	return 0;
}

