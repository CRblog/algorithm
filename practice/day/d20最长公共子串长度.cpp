#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string st1,st2;
    while(cin>>st1>>st2)
    {
        vector<vector<int>> dp(st1.size()+1,vector<int>(st2.size()+1,0));
        int ans = 0;
        for(int i=1;i<=st1.size();++i)
        {
            for(int j=1;j<=st2.size();++j)
            {
            	if(st1[i-1]==st2[j-1])
				{
					dp[i][j] = dp[i-1][j-1]+1;
					ans = max(dp[i][j],ans);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
