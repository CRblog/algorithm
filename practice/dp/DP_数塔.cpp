//DP问题
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
int t,n;//实例个数,行数
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
			scanf("%d",&arr[i][j]);//用二维数组存下
		}
	}
int dp[101][101]={0};
	//DP，定义dp变量
	for(int i=0;i<n;i++)
	{
		dp[n-1][i]=arr[n-1][i];//状态方程的初始量。
        //要求最高层的最大值，从最后一行开始
	}
	for(int i=n-2;i>=0;--i){
		for(int j=0;j<=i;j++){
			dp[i][j]=arr[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
			//状态方程，意思是将下一行的当前列和下一列比较，值更大的和当前值相加
			//作为下一层的值
		}
	}
	cout<<dp[0][0]<<endl;//输出最上层的值
	}
	return 0;
}

