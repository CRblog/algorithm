#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[100001];
int dp[100001];
//典型的动态规划
//第一次看到测试用例以为是忘了写n，然后3 -1 2 1这个数组最大和为3，
//所以以为需要连续的正数，但是也想用dp，所以用了下面注释里的，
//交了才发现好像题看错了，直接写状态方程就行了，不用判断大小
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

