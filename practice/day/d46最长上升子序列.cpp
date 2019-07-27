#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
	{
		vector<int> a(n,0);
		vector<int> dp(n,1);
		int ans = 0;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
        	for(int j=0;j<i;++j)
        	{
        		if(a[j]<a[i])
        		{
        			dp[i] = max(dp[i],dp[j]+1);
				}
				//cout<<a[i]<<"--"<<a[j]<<"---"<<dp[i]<<endl;
			}
			
		}
		for(int i=0;i<n;++i)
		{
			ans = max(ans,dp[i]);
		}
        cout<<ans<<endl;
    }
    return 0;
}

//1 7 3 5 9 4 8
