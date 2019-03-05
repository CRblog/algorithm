#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int i,j,n;
	int dp[1003],maxx[1003];
	memset(maxx,0,sizeof(maxx));
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>dp[i];
	maxx[1]=1;//初始化，刚开始最长长度为1
	for(i=2;i<=n;i++)
	{
		for(j=1;j<i;j++)
			if(dp[i]<dp[j])
			 maxx[i]= max(maxx[i],maxx[j]+1);
	
	if(maxx[i]==0)
	maxx[i]=1;
	}
	sort(maxx,maxx+n+1);
	cout<<maxx[n]+1<<endl;
}
