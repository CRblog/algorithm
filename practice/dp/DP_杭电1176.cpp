//#include<bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cmath>
using namespace std;
int dp[100003][20];
int main()
{
	int n,x,t,i,j;
	
	while(scanf("%d",&n),n)
	{
		int T=0;
		memset(dp,0,sizeof(dp));//dp�����ʼ��
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&t);
			dp[t][x]++;         //�����ڱ�λ�ü�ʱ����Ϣ
			T=max(T,t);         //������ʱ
		}
		for(i=T-1;i>=0;--i)
		{
			for(j=0;j<=11;j++)
			{
				//	ԭ���߽�ֵ��Ҫ��������ģ��������ֿ�������߽�
//				if(j==0)
//					dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]+dp[i][j]);
//				else if(j==10)
//					dp[i][j]=max(dp[i+1][j],dp[i+1][j-1]+dp[i][j]);
//				else
					dp[i][j]=max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]))+dp[i][j];
					//dp״̬����
					//dp[i][j]��ʾ��i����j���õ�����ڱ�����
			}
		}
		printf("%d\n",dp[0][5]);//��ʼ����0��5
	}
	return 0;
}
