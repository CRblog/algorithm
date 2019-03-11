#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
/*
首先拿出5元用来买最大价值的那件东西
   m-5
然后以M为背包容量，背包问题，写出状态方程，算出最大价值dp[m-5]
最后用钱数减去总价值（背包装下的价值+单个物品最大价值）
*/
int main()
{
	int n,m,sum;
	int a[1003];
    int dp[1003];
    while(cin>>n&&n!=0)
    {
    	memset(dp,0,sizeof(dp));
    	for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		cin>>m;
		if(m<5)
		{
			cout<<m<<endl;
		}
		else
		{

			for(int i=0;i<n-1;i++)
			{
				for(int j=m-5;j>=a[i];j--)
				{
					dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
				}
			}
			cout<<m-dp[m-5]-a[n-1]<<endl;
	   }

	}
	return 0;
}
