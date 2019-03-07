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
		memset(dp,0,sizeof(dp));//dp数组初始化
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&t);
			dp[t][x]++;         //保存馅饼位置及时间信息
			T=max(T,t);         //保存用时
		}
		for(i=T-1;i>=0;--i)
		{
			for(j=0;j<=11;j++)
			{
				//	原本边界值是要单独计算的，后来发现可以扩宽边界
//				if(j==0)
//					dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]+dp[i][j]);
//				else if(j==10)
//					dp[i][j]=max(dp[i+1][j],dp[i+1][j-1]+dp[i][j]);
//				else
					dp[i][j]=max(dp[i+1][j-1],max(dp[i+1][j],dp[i+1][j+1]))+dp[i][j];
					//dp状态方程
					//dp[i][j]表示第i秒在j点获得的最大馅饼数量
			}
		}
		printf("%d\n",dp[0][5]);//起始点在0，5
	}
	return 0;
}
