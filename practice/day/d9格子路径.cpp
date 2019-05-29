#include<bits/stdc++.h>
using namespace std;

int dp[1003][1003];
int main()
{
	int m,n;
	while(cin>>m>>n)
    {
    	int x = max(m,n)+1;
        for(int i=1;i<=x;i++)
		{
		dp[1][i] = i+1;
		}
		for(int i=1;i<=x;i++)
		{
		dp[i][1] = i+1;
		}
	for(int i =2;i<=x;i++)
	{
		for(int j=2;j<=x;j++)
		{
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
		}
	}
	//cout<<dp[1][1]<<dp[1][2]<<endl;
	cout<<dp[m][n]<<endl;
    }


	return 0;
}
